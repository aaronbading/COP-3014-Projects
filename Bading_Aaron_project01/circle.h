//Aaron Bading
//class file : (declerations , ends in .h)
//ifndef is to guard the file ?
#ifndef Circle_H
#define Circle_H

#include <iostream>


class Circle
{
public:
    Circle();                            //constructor
    Circle(double radius);              //initialized constructor
    double getRadius();                 //getter
    void setRadius(double radius);      //setter
    double area();
    double diameter();
    double circumference();
  private:
  double radius;
};
#endif
