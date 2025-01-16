#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <stdlib.h>

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

using namespace std;

struct Warehouse{
    int alu_cant;
};

queue<Warehouse> warehouse;

void conveyor(int cant, int maxcant){
    warehouse.push({cant});

    if (maxcant == warehouse.size()) {
        system("clear");
        cout << "Aluminum ingots stored! " << warehouse.size() << endl;

        cout << "  _______  " << endl;
        cout << " /       \\ " << endl;
        cout << "/         \\" << endl;
        cout << "|         |" << endl;
        cout << "| //x " << warehouse.size() << " |" << endl;
        cout << "|         |" << endl;
        cout << "\\         /" << endl;
        cout << " \\_______/ " << endl;
    }
}

int warehouse_alu(){
    return warehouse.size();
}

#endif // WAREHOUSE_H
