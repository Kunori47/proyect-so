#ifndef PRODUCCION_H
#define PRODUCCION_H

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "warehouse.h"

using namespace std;

struct Bauxite{
    int cant;
};
struct Aluminum{
    int cant;
};

queue<Bauxite> queue_bauxita;
queue<Bauxite> queue_fusion;
queue<Bauxite> queue_electrolisis;
queue<Aluminum> queue_aluminum;
mutex mtx;
condition_variable cv;

void purification(int cant_bau){
    for(int i = 0; i <= cant_bau; ++i){
        lock_guard<mutex>  lock(mtx);
        queue_bauxita.push({i});
        cv.notify_one();
    }
    cout << "Purifying and fusing bauxites. Please wait..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Electrolyzing bauxite... " << endl;
}

void fusion(){
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{  return !queue_bauxita.empty();});
        int fusion = queue_bauxita.front().cant;
        queue_fusion.push({fusion});
        queue_bauxita.pop();
        lock.unlock();
    }
}

void electrolysis(){
    for (int i = 1; i < queue_fusion.size(); i++) {
        lock_guard<mutex> lock2(mtx);
        queue_electrolisis.push({i});
        cv.notify_one();
    }
}

void extraction(int cant_alu){
    while (true) {
        unique_lock<mutex> lock2(mtx);
        cv.wait(lock2, []{  return !queue_electrolisis.empty();});
        queue_aluminum.push({queue_electrolisis.front().cant});
        queue_fusion.pop();
        queue_electrolisis.pop();
        lock2.unlock();
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Aluminum ingots: " << queue_aluminum.size() << endl;
        conveyor(queue_aluminum.front().cant, cant_alu);
    }
}

void preparing(int cant_bau){
    thread t1(purification, cant_bau);
    thread t2(fusion);
    thread t3(electrolysis);
    thread t4(extraction, cant_bau);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

#endif // PRODUCCION_H
