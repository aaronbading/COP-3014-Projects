//Aaron Bading
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include<string>
using namespace std;
class student
{
  //student class which contains all the info for student +  member functions
public:
student();
string getname();
void setname(string name);
double getexam(int index);
void setexam(int index,int grade);
double gethw(int index);
void sethw(int index,int grade);
double getquiz(int index);
void setquiz(int index,int grade);
void setexamaverage();
double getexamaverage();
void sethwaverage();
double gethwaverage();
void setquizaverage();
double getquizaverage();
private:
  string name;
  double exam[2];
  double hw[5];
  double quiz[4];
  double examaverage;
  double hwaverage;
  double quizaverage;
  double finalaverage;
};


#endif
