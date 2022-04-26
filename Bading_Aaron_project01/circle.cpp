// Aaron Bading
//source file : (defines methods and ends in .cpp)
// use "" for user defined classes
#include "circle.h"
#include <iostream>

Circle::Circle ()
{
const double Pi=3.141592;
radius=1;
}
//initialized constructor
 Circle::Circle(double radius)
{
this->radius=radius;
}
//compute area
 double Circle::area()
{
  const double Pi=3.141592;
return radius*radius*Pi;

}
//compute diameter
 double Circle ::diameter()
{
  return 2*radius;
}
//compute circumference
 double Circle :: circumference()
{
const double Pi=3.141592;
return 2*Pi*radius;

}
 void Circle :: setRadius(double radius )
{
this->radius=radius;

}
 double Circle :: getRadius()
{
return radius;

}
