#include <iostream>
#include <string>
#include <limits>
#include "transaction.h"

using namespace std;

transaction::transaction()
{string name="<noname>";
  this->hour=0;
  this->minute=0;
  this->second=0;
  this->name=name;
  this->cost=0;
  this->price=0;
  this->valid=false;
  this->id=-1;
//constructor
}

void transaction::sethour(int hour)
{
  this->hour=hour;
}
void transaction::setminute(int minute)
{
  this->minute=minute;
}
void transaction::setsecond(int second)
{
  this->second=second;
}
void transaction::setname(string name)
{
  this->name=name;
}
void  transaction::setcost(double cost)
{
  this->cost=cost;
}
void transaction::setprice(double price)
{
  this->price=price;
}
void transaction::setid(int id)
{
  this->id=id;
}
void transaction::setvalid(bool decision)
{if (decision) {
  this->valid=true;
}else
{this->valid=false;}
  }
  void transaction::setprofit(double profit)
  {
    this->profit=profit;
  }
bool transaction::getvalid()
{
  return this->valid;
}
int transaction::getid()
{
 return this->id;
}
string transaction::getname()
{
 return this->name;
}
int transaction::gethour()
{ return this->hour;}
int transaction::getminute()
{return this->minute;}
int transaction::getsecond()
{return this->second;}
double transaction::getcost()
{ return this->cost;}
double transaction::getprice()
{ return this->price;}
double transaction::getprofit()
{ return this->profit;}
