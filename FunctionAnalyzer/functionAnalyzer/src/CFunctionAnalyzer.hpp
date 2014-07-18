
#ifndef FUNCTIONANALYZER_FUNCTIONANALYZER
#define FUNCTIONANALYZER_FUNCTIONANALYZER

#include "../gridOptimizer/src/CGridOptimizer.hpp"

namespace functionAnalyzer {

template<typename Functor>
class CFunctionAnalyzer
{
public:
   CFunctionAnalyzer(Functor& functor)
   : mFunctor(functor)
   , mGridOptimizer(functor)
   {}

   ~CFunctionAnalyzer() {}

public:
   gridOptimizer::IGridOptimizer& getGridOptimizer() {return mGridOptimizer;}

private:
   Functor& mFunctor;
   gridOptimizer::CGridOptimizer<Functor> mGridOptimizer;
};

} // namespace functionAnalyzer

#endif // FUNCTIONANALYZER_FUNCTIONANALYZER
