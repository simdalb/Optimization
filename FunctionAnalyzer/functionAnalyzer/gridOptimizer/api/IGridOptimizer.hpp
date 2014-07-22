
#ifndef FUNCTIONANALYZER_IGRIDOPTIMIZER
#define FUNCTIONANALYZER_IGRIDOPTIMIZER

#include "IGridPoint.hpp"
#include "../src/CGridConfig.hpp"

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

   virtual void calculateExtrema(const CGridConfig::eExtremaType extremaType) = 0;

   virtual const IGridPoint* getFuncExtremaGridPoint() = 0;
};

} // namespace functionAnalyzer
} // namespace gridOptimizer

#endif // FUNCTIONANALYZER_IGRIDOPTIMIZER
