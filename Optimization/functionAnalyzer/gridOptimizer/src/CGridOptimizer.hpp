
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
      CGridConfig gridConfig;
      gridConfig.mX0 = mFunctor.getMinX();
      gridConfig.mY0 = mFunctor.getMinY();
      gridConfig.mXRange = mFunctor.getMaxX() - mFunctor.getMinX();
      gridConfig.mYRange = mFunctor.getMaxY() - mFunctor.getMinY();
      gridConfig.mnxCells = raise(2, mXResolutionList[0]);
      gridConfig.mnyCells = raise(2, mYResolutionList[0]);
      std::vector<int>::const_iterator itXResolutionList = mXResolutionList.begin();
      std::vector<int>::const_iterator itYResolutionList = mYResolutionList.begin();
      if(mpGridPoint)
      {
         delete mpGridPoint;
      }
      for(; itXResolutionList != mXResolutionList.end(); itXResolutionList++)
      {
         if(itXResolutionList != mXResolutionList.begin())
         {
            gridConfig.mXRange = 2. * gridConfig.mXRange / double(gridConfig.mnxCells);
            gridConfig.mX0 = mpFuncMinGridPoint->getX() - 0.5 * gridConfig.mXRange;
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
            gridConfig.mYRange = 2. * gridConfig.mYRange / double(gridConfig.mnyCells);
            gridConfig.mY0 = mpFuncMinGridPoint->getY() - 0.5 * gridConfig.mYRange;
            gridConfig.mnxCells = raise(2, *itXResolutionList);
            gridConfig.mnyCells = raise(2, *itYResolutionList);
            delete mpGridPoint;
         }
         mpGridPoint = new CGridPoint<Functor>(gridConfig, mFunctor, mpFuncMinGridPoint, mpFuncMaxGridPoint);
         itYResolutionList++;
      }
   }

   virtual const IGridPoint* getFuncMinGridPoint() {return mpFuncMaxGridPoint;}

   virtual const IGridPoint* getFuncMaxGridPoint() {return mpFuncMaxGridPoint;}

private:
   int raise(const int base, const int exp)
   {
      int res = 1;
      for(int i = 0; i < exp; i++)
      {
         res *= base;
      }
      return base;
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
