/*****************************************
 ** Starter code for COP3014 Project 03 **
 *****************************************/

#ifndef _TEXTMENU_H_
#define _TEXTMENU_H_

// TODO: include the header file(s) of the class(es) you designed, only if needed
#include <iostream>
#include <string>
#include "ledger.h"

using namespace std;
class TextMenu {

	// TODO: add instance variable(s) of the class(es) you designed, only if needed
Ledger ledger;
    int selectOptions();

    void addTransaction();

    void printsummary();

    void voidTransaction(); // wrapper for voidOrRemoveTransaction(false)

    void removeTransaction(); // wrapper for voidOrRemoveTransaction(true)

    void voidOrRemoveTransaction(bool removeInstead);

public:
	// TODO: constructor declaration
  TextMenu(Ledger ledger);
    void run();
};


#endif // _TEXTMENU_H_
