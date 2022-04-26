//Aaron Bading
#include "student.h"
#include <iostream>
#include<string>
//constructor initializes all 5 names to <noname>
//initializes all grades.
student::student()
{
  string name="<noname>";
  int grade=-1;
  this->examaverage=0;
  this->quizaverage=0;
  this->hwaverage=0;

  this->name=name;
  for (int i = 0; i < 2; i++) {
  this->exam[i]=grade;
  }
  for (int i = 0; i < 5; i++) {
  this->hw[i]=grade;
  }
  for (int i = 0; i < 4; i++) {
  this->quiz[i]=grade;
  }
}
string student::getname()
{
  return name;
}
void student::setname(string name)
{

  this->name=name;
}

double student::getexam(int index)
{
  return exam[index];
}
void student::setexam(int index,int grade)
{
  this->exam[index]=grade;
}
double student::gethw(int index)
{
  return hw[index];
}
void student::sethw(int index,int grade)
{
  this->hw[index]=grade;
}
double student::getquiz(int index)
{
  return quiz[index];
}
void student::setquiz(int index,int grade)
{
  this->quiz[index]=grade;
}
void student::setexamaverage()
{
  int invalidcount=0;
  for (int i = 0; i <2 ; i++) {
    if (exam[i]==-1)
    {invalidcount++;
      }  }
      this->examaverage=(exam[0]+exam[1]+invalidcount)/(2);
}
double student::getexamaverage()
{
  return examaverage;
}

void student::sethwaverage()
{
  int invalidcount=0;
  for (int i = 0; i <5 ; i++) {
    if (hw[i]==-1)
    {invalidcount++;
      }  }
      this->hwaverage=((hw[0]+hw[1]+hw[2]+hw[3]+hw[4]+invalidcount)/(5));
}
double student::gethwaverage()
{
  return hwaverage;
}

void student::setquizaverage()
{
  int invalidcount=0;
  for (int i = 0; i <4 ; i++) {
    if (quiz[i]==-1)
    {invalidcount++;
      }  }
      this->quizaverage=((quiz[0]+quiz[1]+quiz[2]+quiz[3]+invalidcount)/(4));
}
double student::getquizaverage()
{
  return quizaverage;
}
