//Aaron  Bading
// include all the header files inside main
//use "" for all user created classes
#include<iostream>
#include"circle.h"
#include"triangle.h"
#include"rectangle.h"
using namespace std;

int main ()
{
  int r,b,h,l,w;
  Circle Circl1;
cout << "We Will now test every function in the Circle class:  " << endl;
cout << "Type in a number for the radius:"<< endl;
cin >> r;
Circl1.setRadius(r);
 cout << "Radius = " << Circl1.getRadius() << endl;
 cout << "Area = " << Circl1.area() << endl;
 cout << "Diameter = " << Circl1.diameter() << endl;
 cout << "Circumference = " << Circl1.circumference() << endl;

 Circle Circl2;
 cout << "Second test  for every function in the Circle class:  " << endl;
 cout << "Type in a number for the radius:"<< endl;
 cin >> r;
 Circl2.setRadius(r);
 cout << "Radius = " << Circl2.getRadius() << endl;
 cout << "Area = " << Circl2.area() << endl;
 cout << "Diameter = " << Circl2.diameter() << endl;
 cout << "Circumference = " << Circl2.circumference() << endl;

Triangle Tri1;
 cout << "We Will now test every function in the Triangle class:  " << endl;
 cout << "Type in a number for the base and height of the Triangle: "<< endl;
 cin >> b;
 cin >> h;
 Tri1.setBase(b);
 Tri1.setHeight(h);
 cout << "Base = " << Tri1.getBase() << endl;
 cout << "Height= " << Tri1.getHeight() << endl;
 cout << "Area = " << Tri1.area() << endl;

 Triangle Tri2;
  cout << " Second test for every function in the Triangle class:  " << endl;
  cout << "Type in a number for the base and height of the Triangle: "<< endl;
  cin >> b;
  cin >> h;
  Tri2.setBase(b);
  Tri2.setHeight(h);
  cout << "Base = " << Tri2.getBase() << endl;
  cout << "Height= " << Tri2.getHeight() << endl;
  cout << "Area = " << Tri2.area() << endl;

 Rectangle Rect1;
 cout << "We Will now test every function in the Rectangle class:  " << endl;
 cout << "Type in a number for the Length and width of the Rectangle: "<< endl;
 cin >> l;
 cin >> w;
 Rect1.setlength(l);
 Rect1.setWidth(w);
 cout << "Length = " << Rect1.getlength() << endl;
 cout << "Width = " << Rect1.getWidth() << endl;
 cout << "Area = " << Rect1.area() << endl;
 cout << "Diagonal = " << Rect1.diagonal() << endl;
 cout << "perimeter = " << Rect1.perimeter() << endl;
  if (Rect1.isSquare())
  {cout << "The Rectangle is a square" << endl;}
  else
  { cout << "The Rectangle is not a square" << endl;}

  Rectangle Rect2;
  cout << "Second test for every function in the Rectangle class:  " << endl;
  cout << "Type in a number for the Length and width of the Rectangle: "<< endl;
  cin >> l;
  cin >> w;
  Rect2.setlength(l);
  Rect2.setWidth(w);
  cout << "Length = " << Rect2.getlength() << endl;
  cout << "Width = " << Rect2.getWidth() << endl;
  cout << "Area = " << Rect2.area() << endl;
  cout << "Diagonal = " << Rect2.diagonal() << endl;
  cout << "perimeter = " << Rect2.perimeter() << endl;
   if (Rect2.isSquare())
   {cout << "The Rectangle is a square" << endl;}
   else
   { cout << "The Rectangle is not a square" << endl;}
return 0;
}
