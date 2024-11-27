#include <iostream>
#include <ostream>
#include "produccion.h"

void menu(){

    int cant_bau, option;
    do {

        cout << "Welcome!" << endl;
        cout << "1. Aluminum production." << endl;
        cout << "2. View the warehouse." << endl;
        cout << "3. Exit." << endl;
        cout << "Please enter a choice: ";
        cin >> option;

        switch (option) {

            case 1:cout << "Please enter the amount of bauxite you wish to use (max 100): ";
                   cin >> cant_bau;
                   if (cant_bau > 0 && cant_bau <=  100) {

                       preparing(cant_bau);

                   }else {

                       cout << "Invalid number! (max 100 or min 1)" << endl;

                   }

            default:
                cout << "error not valid option" << endl;

        }

    } while (option != 3);



}
