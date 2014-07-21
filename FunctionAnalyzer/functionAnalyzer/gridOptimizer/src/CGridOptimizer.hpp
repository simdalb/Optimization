
#ifndef FUNCTIONANALYZER_CGRIDOPTIMIZER
#define FUNCTIONANALYZER_CGRIDOPTIMIZER

#include "../api/IGridOptimizer.hpp"
#include "./CGridPoint.hpp"
#include "./CGridConfig.hpp"
#include <vector>

namespace functionAnalyzer {
namespace gridOptimizer {

template <typename Functor>
class CGridOptimizer
: public IGridOptimizer
{
public:
   CGridOptimizer(const Functor& functor)
   : mFunctor(functor)
   , mXResolutionList()
   , mYResolutionList()
   , mpFuncMinGridPoint(0)
   , mpFuncMaxGridPoint(0)
   , mpGridPoint(0)
   {}

   virtual ~CGridOptimizer()
   {
      if(mpGridPoint)
      {
         delete mpGridPoint;
      }
   }

// IGridOptimizer
public:
   virtual void addResolutions(const int xResolution,
                               const int yResolution)
   {
      mXResolutionList.push_back(xResolution);
      mYResolutionList.push_back(yResolution);
   }

   virtual void calculateExtrema()
   {
      if(mXResolutionList.empty() || mXResolutionList.size() != mYResolutionList.size())
      {
         return;
      }
      if(mpGridPoint)
      {
         delete mpGridPoint;
      }
      CGridConfig gridConfig;
      gridConfig.mX0 = mFunctor.getMinX();
      gridConfig.mY0 = mFunctor.getMinY();
      gridConfig.mXRange = mFunctor.getMaxX() - mFunctor.getMinX();
      gridConfig.mYRange = mFunctor.getMaxY() - mFunctor.getMinY();
      std::vector<int>::const_iterator itXResolutionList = mXResolutionList.begin();
      std::vector<int>::const_iterator itYResolutionList = mYResolutionList.begin();
      gridConfig.mnxCells = raise(2, *(itXResolutionList++));
      gridConfig.mnyCells = raise(2, *(itYResolutionList++));
      while(itXResolutionList != mXResolutionList.end())
      {
         if(mpGridPoint)
         {
            gridConfig.mXRange = 2. * gridConfig.mXRange / double(gridConfig.mnxCells);
            gridConfig.mYRange = 2. * gridConfig.mYRange / double(gridConfig.mnyCells);
            gridConfig.mnxCells = raise(2, *(itXResolutionList++));
            gridConfig.mnyCells = raise(2, *(itYResolutionList++));
            gridConfig.mX0 = mpFuncMinGridPoint->getX() - 0.5 * gridConfig.mXRange;
            gridConfig.mY0 = mpFuncMinGridPoint->getY() - 0.5 * gridConfig.mYRange;
            if(gridConfig.mX0 < mFunctor.getMinX())
            {
               gridConfig.mX0 = mFunctor.getMinX();
            }
            if(gridConfig.mX0 + gridConfig.mXRange > mFunctor.getMaxX())
            {
               gridConfig.mXRange = mFunctor.getMaxX() - gridConfig.mX0;
            }
            if(gridConfig.mY0 < mFunctor.getMinY())
            {
               gridConfig.mY0 = mFunctor.getMinY();
            }
            if(gridConfig.mY0 + gridConfig.mYRange > mFunctor.getMaxY())
            {
               gridConfig.mYRange = mFunctor.getMaxY() - gridConfig.mY0;
            }
            delete mpGridPoint;
         }
         mpGridPoint = new CGridPoint<Functor>(gridConfig, mFunctor, mpFuncMinGridPoint, mpFuncMaxGridPoint);
      }
   }

   virtual const IGridPoint* getFuncMinGridPoint() {return mpFuncMinGridPoint;}

   virtual const IGridPoint* getFuncMaxGridPoint() {return mpFuncMaxGridPoint;}

private:
   int raise(const int base, const int exp)
   {
      int res = 1;
      for(int i = 0; i < exp; i++)
      {
         res *= base;
      }
      return res;
   }

private:
   const Functor&   mFunctor;
   std::vector<int> mXResolutionList;
   std::vector<int> mYResolutionList;
   IGridPoint*      mpFuncMinGridPoint;
   IGridPoint*      mpFuncMaxGridPoint;
   IGridPoint*      mpGridPoint;
};

} // namespace functionAnalyzer
} // namespace gridOptimizer

#endif // FUNCTIONANALYZER_CGRIDOPTIMIZER
