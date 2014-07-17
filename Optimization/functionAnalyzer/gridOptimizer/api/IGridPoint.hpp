
#ifndef FUNCTIONANALYZER_IGRIDPOINT
#define FUNCTIONANALYZER_IGRIDPOINT

namespace functionAnalyzer {
namespace gridOptimizer {

class IGridPoint
{
public:
   IGridPoint() {}

   virtual ~IGridPoint() {}

public:
   virtual const double getX() const = 0;

   virtual const double getY() const = 0;

   virtual const double getFuncVal() const = 0;

   virtual const IGridPoint* getLowerGridPoint() const = 0;

   virtual const IGridPoint* getRightGridPoint() const = 0;
};

} // namespace functionAnalyzer
} // namespace gridOptimizer

#endif // FUNCTIONANALYZER_IGRIDPOINT
