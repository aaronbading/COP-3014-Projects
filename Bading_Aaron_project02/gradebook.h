//Aaron Bading
#ifndef gradebook_H
#define gradebook_H

#include <iostream>
#include<string>
#include "student.h"
class gradebook
{
  // Gradebook class contains all the functions for retrieving and changing name, exam, hw ..etc
public:
gradebook();
string getname(int num);
void setname(int num, string name);
double getexam(int num, int index);
void setexam(int num, int index, int grade);
void changeexam(int num, int index, int grade);
void sethw(int num, int index, int grade);
double gethw(int num, int index);
void changehw(int num, int index, int grade);
void setquiz(int num, int index, int grade);
double getquiz(int num, int index);
void changequiz(int num, int index, int grade);
void removestudent(int num);
void changeweight(double weight1,double weight2,double weight3);
void changebookname(string name);
string displaybookname();
void displayaverages();
void displayreport();
private:
student st[5];
double weight1;
double weight2;
double weight3;
string gradebookname;
};

#endif
