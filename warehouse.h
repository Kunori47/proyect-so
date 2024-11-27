#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <stdlib.h>

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

    }



}
