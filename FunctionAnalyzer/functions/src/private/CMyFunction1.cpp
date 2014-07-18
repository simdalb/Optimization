
#include "../CMyFunction1.hpp"

namespace functions {

CMyFunction1::CMyFunction1()
: mMinX(-3.)
, mMaxX(3.)
, mMinY(-3.)
, mMaxY(3.)
{}

const double CMyFunction1::operator() (const double x, const double y) const
{
   return x*x + y*y;
}

} // namespace functions
