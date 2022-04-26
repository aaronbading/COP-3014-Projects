//Aaron Bading

#ifndef Triangle_H
#define Triangle_H

#include <iostream>

class Triangle
{
  public :
  Triangle();
  Triangle(double base, double height);
  double getBase();
  void setBase(double base);
  double getHeight();
  void setHeight(double height);
  double area();

  private :
  double base ;
  double height;
};
#endif
