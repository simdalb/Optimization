
#ifndef FUNCTIONANALYZER_CGRIDCONFIG
#define FUNCTIONANALYZER_CGRIDCONFIG

namespace functionAnalyzer {
namespace gridOptimizer {

class CGridConfig
{
public:
   enum eExtremaType
   {
      MINIMUM = 0,
      MAXIMUM
   };

   eExtremaType mExtremaType;
   double mX0;
   double mY0;
   double mXRange;
   double mYRange;
   int mnxCells;
   int mnyCells;
};

} // namespace functionAnalyzer
} // namespace gridOptimizer

#endif // FUNCTIONANALYZER_CGRIDPOINT
