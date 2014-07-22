
#include "functionAnalyzer/src/CFunctionAnalyzer.hpp"
#include "functionAnalyzer/gridOptimizer/api/IGridOptimizer.hpp"
#include "functionAnalyzer/gridOptimizer/api/IGridPoint.hpp"
#include "functions/src/CMyFunction1.hpp"
#include <iostream>

int main()
{
   functions::CMyFunction1 myFunction;

   functionAnalyzer::CFunctionAnalyzer<functions::CMyFunction1> functionAnalyzer(myFunction);

   functionAnalyzer::gridOptimizer::IGridOptimizer& gridOptimizer = functionAnalyzer.getGridOptimizer();

   gridOptimizer.addResolutions(6, 6);
   gridOptimizer.addResolutions(8, 8);
   gridOptimizer.addResolutions(10, 10);

   gridOptimizer.calculateExtrema(functionAnalyzer::gridOptimizer::CGridConfig::MINIMUM);

   const functionAnalyzer::gridOptimizer::IGridPoint* minGridPoint = gridOptimizer.getFuncExtremaGridPoint();

   std::cout << "Value of minimum: " << minGridPoint->getFuncVal() << ", location of minimum: ("
         << minGridPoint->getX() << ", " << minGridPoint->getY() << ")" << std::endl;
}
