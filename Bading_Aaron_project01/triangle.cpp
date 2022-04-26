//Aaron Bading

#include "triangle.h"
using namespace std;

Triangle::Triangle ()
{
this->base=1;
this->height=1;
}
Triangle::Triangle(double base, double height)
{

}
double Triangle::getBase()
{
  return base;
}
 void Triangle::setBase(double base)
{
  this->base=base;
}
 double Triangle::getHeight()
{
  return height;
}
 void Triangle::setHeight(double height)
{
this->height=height;
}
 double Triangle::area()
{
    return .5*base*height;
}
