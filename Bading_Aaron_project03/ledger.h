#ifndef _LEDGER_H_
#define _LEDGER_H_

// TODO: include the header file(s) of the class(es) you designed, only if needed
#include <iostream>
#include <string>
#include "ledger.h"
#include "transaction.h"
using namespace std;
const int ledgersize=9;
class Ledger {
public:
//constructor will create object array of transactions.
Ledger();

void addtransaction(int hour, int minute, int second, string name,double cost,double price);
void printsummary(string choice);
bool removetransaction(int id);
bool voidtransaction(int id);
private:

transaction trans[ledgersize];
//stores 10 transactions
};


#endif
