/*****************************************
 ** Starter code for COP3014 Project 03 **
 *****************************************/

/*  Author: TODO
 *  COP3014 - Project 3
 *  Revision #: TODO
 */

#include <iostream>
#include "ledger.h"
#include "textmenu.h"
#include"transaction.h"
// TODO: include the header file(s) of the class(es) you designed, only if needed

int main() {
    Ledger ledger;
    TextMenu menu(ledger);
    menu.run();

}
