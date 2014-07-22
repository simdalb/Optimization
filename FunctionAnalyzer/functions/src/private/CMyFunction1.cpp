
#include "../CMyFunction1.hpp"

namespace functions {

CMyFunction1::CMyFunction1()
: mMinX(-3.)
, mMaxX(4.)
, mMinY(-3.)
, mMaxY(4.)
{}

const double CMyFunction1::operator() (const double x, const double y) const
{
   return (x-1.)*(x-1.) + (y-1.)*(y-1.);
}

} // namespace functions
