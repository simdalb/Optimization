
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
   , mpFuncExtremaGridPoint(0)
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

   virtual void calculateExtrema(const CGridConfig::eExtremaType extremaType)
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
      gridConfig.mExtremaType = extremaType;
      // lower left corner of grid
      gridConfig.mX0 = mFunctor.getMinX();
      gridConfig.mY0 = mFunctor.getMinY();
      // size of grid
      gridConfig.mXRange = mFunctor.getMaxX() - mFunctor.getMinX();
      gridConfig.mYRange = mFunctor.getMaxY() - mFunctor.getMinY();
      // set resolution of grid
      std::vector<int>::const_iterator itXResolutionList = mXResolutionList.begin();
      std::vector<int>::const_iterator itYResolutionList = mYResolutionList.begin();
      gridConfig.mnxCells = raise(2, *(itXResolutionList++));
      gridConfig.mnyCells = raise(2, *(itYResolutionList++));
      while(itXResolutionList != mXResolutionList.end())
      {
         if(mpGridPoint)
         {
            // Grid was previously created, replace with new smaller grid around approximate extrema
            gridConfig.mXRange = 2. * gridConfig.mXRange / double(gridConfig.mnxCells);
            gridConfig.mYRange = 2. * gridConfig.mYRange / double(gridConfig.mnyCells);
            gridConfig.mnxCells = raise(2, *(itXResolutionList++));
            gridConfig.mnyCells = raise(2, *(itYResolutionList++));
            gridConfig.mX0 = mpFuncExtremaGridPoint->getX() - 0.5 * gridConfig.mXRange;
            gridConfig.mY0 = mpFuncExtremaGridPoint->getY() - 0.5 * gridConfig.mYRange;
            // Do not go outside the range specified by the functor definition
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
            // previous grid not needed because we have all we need for new grid
            delete mpGridPoint;
         }
         // create new grid and get extrema of this grid
         mpGridPoint = new CGridPoint<Functor>(gridConfig, mFunctor, mpFuncExtremaGridPoint);
      }
   }

   virtual const IGridPoint* getFuncExtremaGridPoint() {return mpFuncExtremaGridPoint;}

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
   IGridPoint*      mpFuncExtremaGridPoint;
   IGridPoint*      mpGridPoint;
};

} // namespace functionAnalyzer
} // namespace gridOptimizer

#endif // FUNCTIONANALYZER_CGRIDOPTIMIZER
