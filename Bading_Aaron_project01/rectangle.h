//Aaron Bading
#ifndef Rectangle_H
#define Rectangle_H

#include <iostream>
#include <cmath>



class Rectangle
{

public:
  Rectangle();
  Rectangle(double length, double width);
  double getlength();
  void setlength(double length);
  double getWidth();
  void setWidth(double width);
  double area();
  double diagonal();
  double perimeter();
  bool isSquare();

  private :
  double length ;
  double width;
};
#endif
