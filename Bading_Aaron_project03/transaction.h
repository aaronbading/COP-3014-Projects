#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

// TODO: include the header file(s) of the class(es) you designed, only if needed
#include <iostream>
#include<string>
using namespace std;
class  transaction{
public:
 transaction();
void sethour(int hour);
void setminute(int minute);
void setsecond(int second);
void setname(string name);
void setcost(double cost);
void setprice(double price);
void setid(int id);
void setvalid(bool decision);
void setprofit(double profit);
int getid();
bool getvalid();
string getname();
int gethour();
int getminute();
int getsecond();
double getcost();
double getprice();
double getprofit();

private:

int hour;
int minute;
int second;
string name;
double cost;
double price;
int id;
bool valid;
double profit;
};


#endif
