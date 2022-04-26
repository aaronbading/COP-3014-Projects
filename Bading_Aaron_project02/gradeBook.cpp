//Aaron Bading
#include "gradebook.h"
#include <iostream>
#include <iomanip>
gradebook::gradebook()
{ student st[5];
  this->weight1=.20;
  this->weight2=.30;
  this->weight3=.40;
this->gradebookname="<noname>";}


string gradebook::getname(int num)
{return (*(st+num)).getname();}
void gradebook::setname(int num, string name)
{int i=0;
do{
  if ((*(st+num)).getname()=="<noname>")
  {(*(st+num)).setname(name);
  i=5;}else{
  num++;
  i++;}}while(i<5);
if(num==5)
{cout <<" Students cannot be added because gradebook is full"<<endl;}
}


void gradebook::removestudent(int num)
{
bool branch;
for (int i= 0; i < 5; i++) {
  if(((*(st+i)).getname()=="<noname>"))
  {branch=true;}
  else
  {
    branch=false;
    while (num<4) {
     st[num]=st[num+1];
     num++;
     break;
   }
   (*(st+num)).setname("<noname>");
 for (int i = 0; i < 2; i++) {
   (*(st+num)).setexam(i,-1);
 }
 for (int i = 0; i < 5; i++) {
   (*(st+num)).sethw(i,-1);
 }
 for (int i = 0; i < 4; i++) {
   (*(st+num)).setquiz(i,-1);
 }
break;}}
 if(branch==true)
 {cout << "Cannot remove students because the gradebook is empty"<<endl;}
}

double gradebook::getexam(int num , int index)
{
  return (*(st+num)).getexam(index);
}
void gradebook::setexam(int num, int index, int grade)
{
  (*(st+num)).setexam(index,grade);
}

void gradebook::changeexam(int num, int index, int grade)
{
(*(st+num)).setexam(index,grade);
}
double gradebook::gethw(int num , int index)
{
  return (*(st+num)).gethw(index);
}
void gradebook::sethw(int num, int index, int grade)
{
  (*(st+num)).sethw(index,grade);
}

void gradebook::changehw(int num, int index, int grade)
{
(*(st+num)).sethw(index,grade);
}
double gradebook::getquiz(int num , int index)
{
  return (*(st+num)).getquiz(index);
}
void gradebook::setquiz(int num, int index, int grade)
{
  (*(st+num)).setquiz(index,grade);
}

void gradebook::changequiz(int num, int index, int grade)
{
(*(st+num)).setquiz(index,grade);
}

void gradebook::changeweight(double weight1,double weight2,double weight3)
{if ((weight1+weight2+weight3)==1) {
this->weight1=weight1;
this->weight2=weight2;
this->weight3=weight3;}
else
{cout<< "Weights don't add up to 1, try again" << endl << endl;}
}
void gradebook::changebookname(string name)
{ this->gradebookname=name;}

void  gradebook::displayaverages()
{double finalav, falsecounttotal;
double hwtotal=0,quiztotal=0,examtotal=0;
int falsecount1=0,falsecount2=0,falsecount3=0;
for (int num = 0; num < 5; num++) {
  for (int index = 0; index < 2; index++) {
    examtotal=examtotal+(*(st+num)).getexam(index);
    if((*(st+num)).getexam(index)<0)
    {falsecount1++; }
  }
}
for (int num = 0; num < 5; num++) {
  for (int index = 0; index < 5; index++) {
    hwtotal=hwtotal+(*(st+num)).gethw(index);
    if((*(st+num)).gethw(index)<0)
    {falsecount2++; }
  }
}
for (int num = 0; num < 5; num++) {
  for (int index = 0; index < 4; index++) {
    quiztotal=quiztotal+(*(st+num)).getquiz(index);
    if((*(st+num)).getquiz(index)<0)
    {falsecount3++; }
  }
}
falsecounttotal=falsecount1+falsecount2+falsecount3;
finalav= ((hwtotal+falsecount2)*(this->weight1)+(quiztotal+falsecount3)*(this->weight2)+(examtotal+falsecount1)*(this->weight3))/55;
cout << "Homework average of class:"<< (hwtotal+falsecount2)/25.0 <<"%"<< endl;
cout << "Quiz average of class:"<<(quiztotal+falsecount3)/20.0 <<"%"<< endl;
cout << "Exam average of class:"<<(examtotal+falsecount1)/10.0 <<"%"<<endl;
cout << "Final average of class:"<<finalav << "%"<<endl <<endl <<endl;

}

string gradebook::displaybookname()
{
return this->gradebookname;
}
void gradebook::displayreport()
{
  cout<<  "Homework "<< "("<<weight1*100<<"%)";
  cout << setw(15) << right << "|" << "Quizzes "<< "("<<weight2*100<<"%)";
  cout << setw(15) << right << "|" << "Exams"<< "("<<weight3*100<<"%)";
  cout << setw(15) << right << "|" << "  HW AVG  ";
  cout << "|" << "  Quiz Avg  ";
  cout << "|" << "  Exam Avg  ";
  cout << "|" << " Final Grade |" << "Student" <<setw(10)<<right <<"|"<< endl ;
  cout << "-------------------";
  cout << "---------|---------------------------|";
  cout << "------------------------|";
  cout << "----------|"<<"------------|"<< "------------|" << "-------------|----------------|"<<endl;

for (int i = 0; i <5; i++) {
(*(st+i)).sethwaverage();
(*(st+i)).setexamaverage();
(*(st+i)).setquizaverage();
for (int j = 0; j < 5; j++) {
    if ((*(st+i)).gethw(j)<0) {
  cout << "UG" << "  ";
  }
  else
  {cout << (*(st+i)).gethw(j) << "  ";}
  }
  cout << setfill(' ')<< setw(15) << left  << "  ";
for (int j = 0; j < 4; j++) {
  if ((*(st+i)).getquiz(j)<0) {
  cout << "UG" << "  ";
  }
  else
  {cout << (*(st+i)).getquiz(j) << "  ";}
  }
  cout << setfill(' ')<< setw(15) << left  << "  ";
for (int j = 0; j < 2; j++) {
  if ((*(st+i)).getexam(j)<0) {
  cout << "UG" << "  ";
  }
  else
  {cout << (*(st+i)).getexam(j) << "   ";}
  }
// editting here--->
  cout << setfill(' ')<< setw(12) << left  << "  ";


  cout << (*(st+i)).gethwaverage() << "  ";
  cout << setfill(' ')<< setw(8) << left  << "  ";

  cout << (*(st+i)).getquizaverage() << "  ";
  cout << setfill(' ')<< setw(10) << left  << "  ";

  cout << (*(st+i)).getexamaverage() << "  ";
  cout << setfill(' ')<< setw(10) << left  << "  ";

  cout << ((*(st+i)).gethwaverage()*weight1+(*(st+i)).getquizaverage()*weight2+(*(st+i)).getexamaverage()*weight3) << "  " ;
  cout << setfill(' ')<< setw(8) << left  << "  ";
  cout << (*(st+i)).getname() << setfill(' ')<< setw(15) << left  << "  " << endl<<endl;
  }

}
