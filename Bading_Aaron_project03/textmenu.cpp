/*****************************************
 ** Starter code for COP3014 Project 03 **
 *****************************************/

#include <iostream>
#include <string>
#include <limits>
#include "textmenu.h"

using namespace std;

// TODO: constructor definition here
TextMenu::TextMenu(Ledger ledger)
{

}

void TextMenu::run() {
    int choice;

    do {
        choice = selectOptions();
        cout << endl;
        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                voidTransaction();
                break;
            case 3:
                removeTransaction();
                break;
            case 4:
                printsummary();
                break;
            case 5:
                cout << "Thank you for using! Bye!" << endl;
        }
    } while (choice != 5);

}

int TextMenu::selectOptions() {
    int choice;
    cout << endl;
    cout << "Daily ledger managing system:" << endl;
    cout << "1. Add a transaction." << endl;
    cout << "2. Void a transaction." << endl;
    cout << "3. Remove a transaction." << endl;
    cout << "4. Print summary." << endl;
    cout << "5. Quit." << endl;
    cout << "Input your choice: ";
    do
    {
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(choice > 5 || choice < 1)
        {
            choice = 0;
            cout << "Invalid choice. Please try again!" << endl;
            cout << "Input your choice: ";
        }
    } while(choice == 0);

    return choice;
}

void TextMenu::addTransaction() {
    int hour, minute, second;
    string name;
    double cost, price;

    cout << "Please input the time as three integers for hour, minute and second separated by space: ";
    cin >> hour >> minute >> second;
    while(cin.fail())
    {
        cout << "Please only input integers for hour, minute, and second: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> hour >> minute >> second;
    }

    cout << "Please input the item name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Please input the item cost: ";
    cin >> cost;
    while(cin.fail())
    {
        cout << "Please only input valid monetary amounts: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cost;
    }

    cout << "Please input the item sale price: ";
    cin >> price;
        while(cin.fail())
    {
        cout << "Please only input valid monetary amounts: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> price;
    }
//  have : hour , minute, second ,name, cost, price,

      ledger.addtransaction(hour,minute,second,name,cost,price);

}

void TextMenu::printsummary() {
    int choice;
    cout << endl;
    cout << "Print summary sorted by:" << endl;
    cout << "1. Transaction id" << endl;
    cout << "2. Item name" << endl;
    cout << "3. Profit" << endl;
    cout << "Input your choice: ";

    do
    {
        cin >> choice;
        cout << endl;
        if(cin.fail())
        {
            choice = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(choice < 1 || choice > 3)
        {
            choice = 0;
            cout << "Invalid choice. Please try again!" << endl;
            cout << "Input your choice: ";
        }
    } while(choice == 0);

    switch (choice) {
        case 1:
            // Print summary sorted by id
            ledger.printsummary("id");
            break;
        case 2:
            // Print summary sorted by name
            ledger.printsummary("name");
            break;
        case 3:
            // Print summary sorted by profit
            ledger.printsummary("profit");
            break;
    }
    cout << endl;
}

void TextMenu::voidOrRemoveTransaction(bool removeInstead) {
    char choice;
    int id;
    bool succeed = false;
    cout << "You must enter the transaction id to "
         << (removeInstead ? "remove" : "void")
         << " the transaction." << endl;
    while (true) {
        cout << "Do you want to print the summary first? (y/n)" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            break;
        else
            cout << "You must input y for yes or n for no!" << endl;
    }
    if (choice == 'y' || choice == 'Y')
        ledger.printsummary("id");
    cout << "Please input the transaction id of the transaction you want to "
         << (removeInstead ? "remove" : "void") << ": ";
    cin >> id;

    if(removeInstead)
        // TODO: remove the transaction and set the succeed to true if successful
        if(ledger.removetransaction(id))
        {succeed=true;}
        else
        {succeed=false;}
    else
    if(ledger.voidtransaction(id))
    {succeed=true;}
    else
    {succeed=false;}
        // TODO: void the transaction and set the succeed to true if successful

    if (succeed){
        cout << "Transaction " << (removeInstead ? "removed!" : "voided!") << endl;
    }
    else {
        cout << "Invalid transaction id or ledger was empty" << endl;
    }
}

void TextMenu::voidTransaction() {
    voidOrRemoveTransaction(false);
}

void TextMenu::removeTransaction() {
    voidOrRemoveTransaction(true);
}
