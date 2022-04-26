//Aaron Bading
#include <iostream>
#include "student.h"
#include "gradebook.h"
#include <string>

using namespace std;
int main(){
// constructing object1 of class gradebook
gradebook object1;

bool again=true;
do {
    int x;
    cout <<endl<<endl << "     -=|   MAIN MENU  |=-   " << endl;
    cout <<"1. Add a student" << endl;
    cout <<"2. Remove a student" << endl;
    cout <<"3. Change a student's grade" << endl;
    cout <<"4. Change group weights" << endl;
    cout <<"5. Change the gradebook name" << endl;
    cout <<"6. Display class averages" << endl;
    cout <<"7. Display full report" << endl;
    cout <<"0. QUIT" << endl <<endl;
    cout <<"Enter an action:" << endl <<endl;
    cin >> x;

switch(x){
//Case 1 : Adding student
  case 1:
  {string name;
  cout << "-=| ADDING STUDENT |=-" << endl << endl;
  cout << "Please enter the student's name: " << endl << endl;
  cin >> name;
  object1.setname(0,name);
  break;}
// Case 2 : Removing Student
  case 2:
  {int choice;
   cout << "-=| REMOVING STUDENT |=-" << endl << endl ;
   for (int i = 0; i < 5; i++)
   {cout <<i+1<<"." <<object1.getname(i) << endl << endl ;}
    cout << "Enter student to remove:" << endl <<endl;
    cin >> choice;
    object1.removestudent(choice-1);
    break;}
// Case 3 : Chaning Grade
  case 3:
  {int student,type,grade,index;
    cout << "-=| CHANGING GRADE |=-" << endl <<endl;
for (int i = 0; i < 5; i++)
{ cout <<i+1<<"." <<object1.getname(i) << endl << endl;}
  cout << "Which student would you like to change" <<endl <<endl;
  cin >> student;
  cout << "1. Change a homework grade" << endl <<endl;
  cout << "2. Change a quiz grade" << endl <<endl;
  cout << "3. Change a exam grade" << endl <<endl;
  cout << "What type of grade would you like to change"<<endl <<endl;
  cin >> type;
  if (type==1)
  {
  for (int i = 0; i < 5; i++) {
    if (object1.gethw(student-1,i)<0)
    {cout <<i+1<<"." <<"<ungraded>"<< endl <<endl;}
    else
    {cout <<i+1<<"." <<object1.gethw(student-1,i) << endl <<endl;}}
    cout <<"Which grade do you want to change"<<endl <<endl;
    cin >> index;
    cout << "What do you want to change the grade to?(-1 for ungraded)"<<endl<<endl;
    cin >> grade;
    if ((grade<-1)||(grade>100))
    {cout << "Invalid Grade !" << endl;
    break;}
    else
    {object1.sethw(student-1,index-1,grade);
    break;}
}
else{
if (type==2) {
  for (int i = 0; i < 4; i++)
  {if (object1.getquiz(student-1,i)<0)
    {cout <<i+1<<"." <<"<ungraded>"<< endl<<endl;}
  else
    {cout <<i+1<<"." <<object1.getquiz(student-1,i) << endl<<endl;}}
  cout <<"Which grade do you want to change"<<endl<<endl;
  cin >> index;
  cout << "What do you want to change the grade to?(-1 for ungraded)"<<endl<<endl;
  cin >> grade;if ((grade<-1)||(grade>100))
  {cout << "Invalid Grade !" << endl;
  break;}
  else
  {object1.setquiz(student-1,index-1,grade);
  break;}

}
else
{if (type==3) {
  for (int i = 0; i < 2; i++) {
  if (object1.getexam(student-1,i)<0)
  {cout <<i+1<<"." <<"<ungraded>"<< endl<<endl;}
else
{cout <<i+1<<"." <<object1.getexam(student-1,i) << endl<<endl;}
}
  cout <<"Which grade do you want to change"<<endl<<endl;
  cin >> index;
  cout << "What do you want to change the grade to?(-1 for ungraded)"<<endl<<endl;
  cin >> grade;
  if ((grade<-1)||(grade>100))
  {cout << "Invalid Grade !" << endl;
  break;}
  else
  {object1.setexam(student-1,index-1,grade);
  break;}
}
else
{cout <<"Invalid grade type"<< endl;
break;}
}
}
}
//  Case 4 Changing Weights
case 4:
{double hw,quiz,exam;
  cout << "-=| CHANGING WEIGHTS |=-" << endl <<endl;
  cout <<"Weights must add to 1.0"<<endl<<endl;
  cout <<"Enter  new weight for Homeworks"<<endl<<endl;
  cin >>hw;
  cout <<"Enter new weight for Quizzes"<<endl<<endl;
  cin >>quiz;
  cout <<"Enter new weight for Exams"<<endl<<endl;
  cin >>exam;
object1.changeweight(hw,quiz,exam);
break;}
//Case 5 : Change Gradebook Name
case 5:
{ string name;
  cout << "-=| CHANGING GRADEBOOKNAME |=-" << endl <<endl;
cout << "Please enter the new name for the gradebook"<< endl<<endl;
cin >>name;
object1.changebookname(name);
break;
}
//Case 6 displays class averages
case 6:
{cout << "-=| CLASS AVERAGES |=-" << endl <<endl;
  object1.displayaverages();
  break;}
// Case 7 displays full report
case 7:
{ cout << "-=| GRADEBOOK REPORT |=-" << endl <<endl;
  cout << "Course: "<<object1.displaybookname() << endl;
  object1.displayaverages();
  cout << endl <<endl;
  object1.displayreport();
  cout << endl;
  break;}
 //Case 0 exits the program
case 0:
{again=false;
 break;}

default:
{cout << "Invalid Entry, try again" << endl;}

}
} while(again==true);


    return 0;
}
