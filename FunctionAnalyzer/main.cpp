
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

   gridOptimizer.addResolutions(4, 4);
   gridOptimizer.addResolutions(5, 5);
   gridOptimizer.addResolutions(6, 6);

   gridOptimizer.calculateExtrema();

   const functionAnalyzer::gridOptimizer::IGridPoint* minGridPoint = gridOptimizer.getFuncMinGridPoint();
   const functionAnalyzer::gridOptimizer::IGridPoint* maxGridPoint = gridOptimizer.getFuncMaxGridPoint();

   std::cout << "Value of minimum: " << minGridPoint->getFuncVal() << ", location of minimum: ("
         << minGridPoint->getX() << ", " << minGridPoint->getY() << ")" << std::endl;
   std::cout << "Value of maximum: " << maxGridPoint->getFuncVal() << ", location of maximum: ("
         << maxGridPoint->getX() << ", " << maxGridPoint->getY() << ")" << std::endl;
}
