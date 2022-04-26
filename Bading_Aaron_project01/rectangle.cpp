// Aaron Bading
#include "rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle()
{this->length=1;
this->width=1;
}
Rectangle::Rectangle(double length, double width)
{this->length=length;
  this->width=width;
}
double Rectangle::getlength()
{
  return length;
}
void Rectangle::setlength(double length)
{
  this->length=length;
}
 double Rectangle::getWidth()
{
  return width;
}
 void Rectangle::setWidth(double width)
{
  this->width=width;
}
double Rectangle::area()
{
return length*width;
}
double Rectangle::diagonal()
  {
    return sqrt((length*length)+(width*width));
  }
 double Rectangle ::perimeter()
{
  return (2*length+2*width);
}
 bool Rectangle :: isSquare()
{
if (length== width)
return true;
else {return false;}
}
