
#ifndef FUNCTIONS_CMYFUNCTION1
#define FUNCTIONS_CMYFUNCTION1

namespace functions {

class CMyFunction1
{
public:
   CMyFunction1();

   ~CMyFunction1() {}

public:
   const double operator() (const double x, const double y) const;

   const double getMinX() const {return mMinX;}

   const double getMaxX() const {return mMaxX;}

   const double getMinY() const {return mMinY;}

   const double getMaxY() const {return mMaxY;}

private:
   const double mMinX;
   const double mMaxX;
   const double mMinY;
   const double mMaxY;
};

} // namespace functions

#endif // FUNCTIONS_CMYFUNCTION1
