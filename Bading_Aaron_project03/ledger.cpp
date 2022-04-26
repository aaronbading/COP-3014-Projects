#include <iostream>
#include <string>
#include <limits>
#include "ledger.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include<locale>
using namespace std;

Ledger::Ledger()
{ const int ledgersize=9;
  transaction trans[ledgersize];
  //for loop initializes profits (didnt use this anyways lol)
  for (int i = 0; i < ledgersize+1; i++)
  {(*(trans+i)).setprofit(0);}

}

void Ledger::addtransaction(int hour, int minute, int second, string name,double cost, double price)
{
  int id=0 ,random=0;
  bool decision=true;
  bool iddecision=true;

  // first loop sees if transactions are full
          for(int i=0;i<ledgersize+1;i++)
          {
              if ((*(trans+i)).getvalid())
              {}
              else
              {break;}

              if(i==ledgersize)
              {decision=false;
                cout<< "The ledger is full, remove something and then try again :)" << endl;
                break;}
          }


              if(decision)
          {
              int tempid;
              bool keepgoing=true;
              do
              {
                    keepgoing=true;
                    srand(time(0)+random++);
                    tempid=rand()%10;

                    for (int i = 0; i < ledgersize+1; i++) //this loop checks to see if this id has been used
                    {
                      if(tempid==(*(trans+i)).getid())
                        {keepgoing=false;}
                    }

                    if(keepgoing)
                    {     for(int j=0;j<ledgersize+1;j++)//this loop looks for the empty spot
                          {
                              if(!(*(trans+j)).getvalid())
                              { if((*(trans+j)).getid()<0)
                                  {iddecision=false;
                                  id=tempid;
                                  break;}
                              }
                          }
                    }

                }
                           while(iddecision);
                     (*(trans+id)).sethour(hour);
                     (*(trans+id)).setminute(minute);
                     (*(trans+id)).setsecond(second);
                     (*(trans+id)).setname(name);
                     (*(trans+id)).setprice(price);
                     (*(trans+id)).setcost(cost);
                     (*(trans+id)).setprofit(price-cost);
                     (*(trans+id)).setid(id);
                     (*(trans+id)).setvalid(true);

         }

}
void Ledger::printsummary(string choice)
{ int direction;
    if (choice=="id")
    {direction=1;}
    if (choice=="name")
    {direction=2;}
    if (choice=="profit")
    {direction=3;}

  switch (direction) {
    case 1:
{



          transaction temp[10] ,tempval;   //first loop copies information into temp array
      for (int i = 0; i < ledgersize+1; i++)
      {temp[i]=trans[i];}

      int i,j,k;
      for (int k = 0; k < ledgersize+1; k++)
      {


            for (int i = 0; i< ledgersize-k; i++)
            {
              if ((*(temp+i)).getid()>(*(temp+i+1)).getid())
              { tempval=(*(temp+i));
                (*(temp+i))=(*(temp+i+1));
                 (*(temp+i+1))=tempval;
               }
            }
      }


      const char separator    = ' ';
      const int nameWidth     = 8;
      const int numWidth      = 15;
      cout << "=|| Printing Summary ||=" << endl << endl;
      cout << left << setw(numWidth) << setfill(separator) << "ID";
      cout << left << setw(numWidth) << setfill(separator) << "Name";
      cout << left << setw(numWidth) << setfill(separator) << "Hour";
      cout << left << setw(numWidth) << setfill(separator) << "Minute";
      cout << left << setw(numWidth) << setfill(separator) << "Second";
      cout << left << setw(numWidth) << setfill(separator) << "Price";
      cout << left << setw(numWidth) << setfill(separator) << "Cost";
      cout << left << setw(numWidth) << setfill(separator) << "Profit";
      cout << endl;

      for (int i = 0; i < ledgersize+1; i++)
      {
        if((*(temp+i)).getid()>-1){
        cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getid();
        cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getname();
        cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).gethour();
        cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getminute();
        cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getsecond();
        cout << "$"<< left << setw(numWidth) << setfill(separator) << (*(temp+i)).getprice();
        cout << "$"<< left << setw(numWidth) << setfill(separator) << (*(temp+i)).getcost();
        cout << "$"<< left << setw(numWidth) << setfill(separator) << (*(temp+i)).getprice()-(*(temp+i)).getcost();
        cout << endl;}
      }



        double totalprofit=0,actualtrans=0,count=0;
        for (int i = 0; i < ledgersize+1; i++)
        {
              if((*(temp+i)).getvalid())
              {totalprofit=totalprofit+((*(temp+i)).getprice()-(*(temp+i)).getcost());}
        }
        for (int i = 0; i < ledgersize+1; i++)
        {
            if((*(trans+i)).getvalid())
            {actualtrans++;}
        }
        //checks for emptyness if its emty it will make the average a negative
        for (int i = 0; i < ledgersize+1; i++)
        {
          if((*(trans+i)).getvalid())
            {break;}
          if(i==ledgersize)
            {actualtrans=-1;}
        }
        cout << "Total Profit :  " << totalprofit<<"$" <<endl;
        cout << "Average Profit :  " << totalprofit/actualtrans<< "$"<<endl;
      break;

}
    case 2:
{
   transaction temp[10] ,tempval;
for (int i = 0; i < ledgersize+1; i++)
{temp[i]=trans[i];}


int i,j,k;
for (int k = 0; k < ledgersize+1; k++)
{

    for (int i = 0; i< ledgersize-k; i++)
    {   if(((*(temp+i)).getname()).at(0)>((*(temp+(i+1))).getname()).at(0))

          {tempval=(*(temp+i));
            (*(temp+i))=(*(temp+i+1));
             (*(temp+i+1))=tempval;}
    }
}


const char separator    = ' ';
const int nameWidth     = 8;
const int numWidth      = 15;
cout << "=|| Printing Summary ||=" << endl << endl;
cout << left << setw(numWidth) << setfill(separator) << "ID";
cout << left << setw(numWidth) << setfill(separator) << "Name";
cout << left << setw(numWidth) << setfill(separator) << "Hour";
cout << left << setw(numWidth) << setfill(separator) << "Minute";
cout << left << setw(numWidth) << setfill(separator) << "Second";
cout << left << setw(numWidth) << setfill(separator) << "Price";
cout << left << setw(numWidth) << setfill(separator) << "Cost";
cout << left << setw(numWidth) << setfill(separator) << "Profit";
cout << endl;

for (int i = 0; i < ledgersize+1; i++)
{
  if((*(temp+i)).getid()>-1){
  cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getid();
  cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getname();
  cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).gethour();
  cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getminute();
  cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getsecond();
  cout << "$" << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getprice() ;
  cout << "$" << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getcost() ;
  cout << "$" << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getprice()-(*(temp+i)).getcost();
  cout << endl;}
}



double totalprofit=0,actualtrans=0,count=0;
for (int i = 0; i < ledgersize+1; i++)
{
    if((*(temp+i)).getvalid())
    {totalprofit=totalprofit+((*(temp+i)).getprice()-(*(temp+i)).getcost());}
}
for (int i = 0; i < ledgersize+1; i++)
{
  if((*(trans+i)).getvalid())
  {actualtrans++;}
}
//checks for emptyness if its emty it will make the average a negative
for (int i = 0; i < ledgersize+1; i++)
{
  if((*(trans+i)).getvalid())
  {break;}
  if(i==ledgersize)
  {actualtrans=-1;}
}
cout << "Total Profit :  " << totalprofit<<"$" <<endl;
cout << "Average Profit :  " << totalprofit/actualtrans<<"$" <<endl;

    break;}
    case 3:
{
            transaction temp[10] ,tempval;   //first loop copies information into temp array
        for (int i = 0; i < ledgersize+1; i++)
        {temp[i]=trans[i];}

        int i,j,k;
        for (int k = 0; k < ledgersize+1; k++)
        {


            for (int i = 0; i< ledgersize-k; i++)
            {
              if (((*(temp+i)).getprice()-(*(temp+i)).getcost())<((*(temp+i+1)).getprice()-(*(temp+i+1)).getcost()))
                {tempval=(*(temp+i));
                (*(temp+i))=(*(temp+i+1));
                 (*(temp+i+1))=tempval;}
            }
       }


        const char separator    = ' ';
        const int nameWidth     = 8;
        const int numWidth      = 15;
        cout << "=|| Printing Summary ||=" << endl << endl;
        cout << left << setw(numWidth) << setfill(separator) << "ID";
        cout << left << setw(numWidth) << setfill(separator) << "Name";
        cout << left << setw(numWidth) << setfill(separator) << "Hour";
        cout << left << setw(numWidth) << setfill(separator) << "Minute";
        cout << left << setw(numWidth) << setfill(separator) << "Second";
        cout << left << setw(numWidth) << setfill(separator) << "Price";
        cout << left << setw(numWidth) << setfill(separator) << "Cost";
        cout << left << setw(numWidth) << setfill(separator) << "Profit";
        cout << endl;

        for (int i = 0; i < ledgersize+1; i++)
        {
          if((*(temp+i)).getid()>-1){
          cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getid();
          cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getname();
          cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).gethour();
          cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getminute();
          cout << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getsecond();
          cout << "$" << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getprice();
          cout << "$" << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getcost();
          cout << "$" << left << setw(numWidth) << setfill(separator) << (*(temp+i)).getprice()-(*(temp+i)).getcost();
          cout << endl;}
        }



  double totalprofit=0,actualtrans=0,count=0;
  for (int i = 0; i < ledgersize+1; i++)
  {
    if((*(temp+i)).getvalid())
    {totalprofit=totalprofit+((*(temp+i)).getprice()-(*(temp+i)).getcost());}
  }

  for (int i = 0; i < ledgersize+1; i++)
  {
    if((*(trans+i)).getvalid())
    {actualtrans++;}
  }
  //checks for emptyness if its emty it will make the average a negative
  for (int i = 0; i < ledgersize; i++)
  {
    if((*(trans+i)).getvalid())
    {break;}
    if(i==ledgersize)
    {actualtrans=-1;}

  }
  cout << "Total Profit :  " << totalprofit<< "$"<<endl;
  cout << "Average Profit :  " << totalprofit/actualtrans<< "$"<<endl;




    break; }
;

}

}







bool Ledger::removetransaction(int id)
  {
    //first loop checks if its empty
    bool decision=true,lastdecision;
    for(int i=0;i<ledgersize+1;i++)
    {

      if (!(*(trans+i)).getvalid())
      {}
      else
      {break;}

      if(i==ledgersize)
        {  decision=false;
          cout<< "The ledger is empty, add something and then try again :)" << endl;
          lastdecision= false;
          break;}
      }


if(decision)
{
  (*(trans+id)).sethour(0);
  (*(trans+id)).setminute(0);
  (*(trans+id)).setsecond(0);
  (*(trans+id)).setname("<noname>");
  (*(trans+id)).setprice(0);
  (*(trans+id)).setcost(0);
  (*(trans+id)).setprofit(0);
  (*(trans+id)).setid(-1);
  (*(trans+id)).setvalid(false);
  lastdecision= true;
}
 return lastdecision;
 }
bool Ledger::voidtransaction(int id)
  {//first loop checks if its empty
  bool decision=true,lastdecision;
  for(int i=0;i<ledgersize+1;i++)
  {

    if (!(*(trans+i)).getvalid())
    {}
    else
    {break;}

    if(i==ledgersize)
      {  decision=false;
        cout<< "The ledger is empty, add something and then try again :)" << endl;
        lastdecision= false;
        break;}
  }


if(decision)
{
  string name;
    name=(*(trans+id)).getname();
   name.append("*Void*");
  (*(trans+id)).setname(name);
  (*(trans+id)).setvalid(false);
  lastdecision=true;

}
return lastdecision;





  }
