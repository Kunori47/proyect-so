#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <stdlib.h>
#include <utility>

using namespace std;

struct Bauxita{
    int cant;
};
queue<Bauxita> cola_bauxita;
mutex mtx;
condition_variable cv;

    /*
    void fusion(){
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, []{  return ;});


            lock.unlock();

            cout << "Fusionando bauxita... " << endl;

        }
    }*/

    void purification(int cant_bau){

        for(int i = 0; i <= cant_bau; ++i){
            lock_guard<mutex>  lock(mtx);
            //fusion();
            cola_bauxita.push({i});
            cv.notify_one();

        }
        cout << "Purificando bauxitas espere..." << endl;

    }

    /*
    void electrolisis(){

            while (true) {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, []{  return ;});


                lock.unlock();

                cout << "Electrolizando bauxita... " << endl;

            }
            }*/

    void extraccion(){

        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, []{  return !cola_bauxita.empty();});

            int bauxita = cola_bauxita.front().cant;
            cola_bauxita.pop();

            lock.unlock();

            cout << "Lingotes de aluminio obtenido: " << bauxita << endl;

        }

    }

void preparing(int cant_bau){

    thread t1(purification, cant_bau);
    thread t2(extraccion);

    t1.join();
    t2.join();

}
