
#ifndef FUNCTIONANALYZER_IGRIDOPTIMIZER
#define FUNCTIONANALYZER_IGRIDOPTIMIZER

#include "IGridPoint.hpp"

namespace functionAnalyzer {
namespace gridOptimizer {

class IGridOptimizer
{
public:
   IGridOptimizer() {}

   virtual ~IGridOptimizer() {}

public:
   virtual void addResolutions(const int xResolution,
                               const int yResolution) = 0;

   virtual void calculateExtrema() = 0;

   virtual const IGridPoint* getFuncMinGridPoint() = 0;

   virtual const IGridPoint* getFuncMaxGridPoint() = 0;
};

} // namespace functionAnalyzer
} // namespace gridOptimizer

#endif // FUNCTIONANALYZER_IGRIDOPTIMIZER
