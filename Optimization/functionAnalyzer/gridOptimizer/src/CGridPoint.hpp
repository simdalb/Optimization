
#ifndef FUNCTIONANALYZER_CGRIDPOINT
#define FUNCTIONANALYZER_CGRIDPOINT

#include "../src/CGridPoint.hpp"
#include "../src/CGridConfig.hpp"

namespace functionAnalyzer {
namespace gridOptimizer {

template <typename Functor>
class CGridPoint
: public IGridPoint
{
public:
   CGridPoint(const CGridConfig& gridConfig,
              const Functor&     functor,
              IGridPoint*&       pFuncMinGridPoint,
              IGridPoint*&       pFuncMaxGridPoint)
   : mX(gridConfig.mX0)
   , mY(gridConfig.mY0)
   , mFuncVal(functor(mX, mY))
   , mpRightGridPoint(0)
   , mpLowerGridPoint(0)
   {
      pFuncMaxGridPoint = this;
      pFuncMinGridPoint = this;

      mpRightGridPoint = new CGridPoint(gridConfig, functor, pFuncMinGridPoint, pFuncMaxGridPoint, 1, 0, true);
      mpLowerGridPoint = new CGridPoint(gridConfig, functor, pFuncMinGridPoint, pFuncMaxGridPoint, 0, 1, false);
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
              IGridPoint*&       pFuncMinGridPoint,
              IGridPoint*&       pFuncMaxGridPoint,
              const int          nX,
              const int          nY,
              const bool         doRight)
   : mX(gridConfig.mX0 + nX * gridConfig.mXRange / double(gridConfig.mnxCells))
   , mY(gridConfig.mY0 + nY * gridConfig.mYRange / double(gridConfig.mnyCells))
   , mFuncVal(functor(mX, mY))
   , mpRightGridPoint(0)
   , mpLowerGridPoint(0)
   {
      if(mFuncVal < pFuncMinGridPoint->getFuncVal())
      {
         pFuncMinGridPoint = this;
      }

      if(mFuncVal > pFuncMaxGridPoint->getFuncVal())
      {
         pFuncMaxGridPoint = this;
      }

      if(nX < gridConfig.mnxCells && doRight)
      {
         mpRightGridPoint = new CGridPoint(gridConfig, functor, pFuncMaxGridPoint, pFuncMinGridPoint, nX + 1, nY, true);
      }

      if(nY < gridConfig.mnyCells)
      {
         mpLowerGridPoint = new CGridPoint(gridConfig, functor, pFuncMaxGridPoint, pFuncMinGridPoint, nX, nY + 1, false);
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