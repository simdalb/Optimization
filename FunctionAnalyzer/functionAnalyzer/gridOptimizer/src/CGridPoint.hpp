
#ifndef FUNCTIONANALYZER_CGRIDPOINT
#define FUNCTIONANALYZER_CGRIDPOINT

#include "./CGridConfig.hpp"
#include "../api/IGridPoint.hpp"

namespace functionAnalyzer {
namespace gridOptimizer {

template <typename Functor>
class CGridPoint
: public IGridPoint
{
public:
   CGridPoint(const CGridConfig& gridConfig,
              const Functor&     functor,
              IGridPoint*&       pFuncExtremaGridPoint)
   : mX(gridConfig.mX0)
   , mY(gridConfig.mY0)
   , mFuncVal(functor(mX, mY))
   , mpRightGridPoint(0)
   , mpLowerGridPoint(0)
   {
      pFuncExtremaGridPoint = this;

      mpRightGridPoint = new CGridPoint(gridConfig, functor, pFuncExtremaGridPoint, 1, 0, true);
      mpLowerGridPoint = new CGridPoint(gridConfig, functor, pFuncExtremaGridPoint, 0, 1, false);
   }

// IGridPoint
public:
   virtual const double getX() const {return mX;}
   virtual const double getY() const {return mY;}
   virtual const double getFuncVal() const {return mFuncVal;}
   virtual const IGridPoint* getLowerGridPoint() const {return mpLowerGridPoint;}
   virtual const IGridPoint* getRightGridPoint() const {return mpRightGridPoint;}

private:
   CGridPoint(const CGridConfig& gridConfig,
              const Functor&     functor,
              IGridPoint*&       pFuncExtremaGridPoint,
              const int          nX,
              const int          nY,
              const bool         doRight)
   : mX(gridConfig.mX0 + nX * gridConfig.mXRange / double(gridConfig.mnxCells))
   , mY(gridConfig.mY0 + nY * gridConfig.mYRange / double(gridConfig.mnyCells))
   , mFuncVal(functor(mX, mY))
   , mpRightGridPoint(0)
   , mpLowerGridPoint(0)
   {
      if(gridConfig.mExtremaType == CGridConfig::MINIMUM && mFuncVal < pFuncExtremaGridPoint->getFuncVal())
      {
         pFuncExtremaGridPoint = this;
      }
      else if(gridConfig.mExtremaType == CGridConfig::MAXIMUM && mFuncVal > pFuncExtremaGridPoint->getFuncVal())
      {
         pFuncExtremaGridPoint = this;
      }

      if(nX < gridConfig.mnxCells && doRight)
      {
         mpRightGridPoint = new CGridPoint(gridConfig, functor, pFuncExtremaGridPoint, nX + 1, nY, true);
      }

      if(nY < gridConfig.mnyCells)
      {
         mpLowerGridPoint = new CGridPoint(gridConfig, functor, pFuncExtremaGridPoint, nX, nY + 1, false);
      }
   }

   virtual ~CGridPoint()
   {
      if(mpLowerGridPoint)
      {
         delete mpLowerGridPoint;
      }

      if(mpRightGridPoint)
      {
         delete mpRightGridPoint;
      }
   }

private:
   const double mX;
   const double mY;
   const double mFuncVal;
   IGridPoint* mpRightGridPoint;
   IGridPoint* mpLowerGridPoint;
};

} // namespace functionAnalyzer
} // namespace gridOptimizer

#endif // FUNCTIONANALYZER_CGRIDPOINT
