#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <stdlib.h>

using namespace std;
class Start{
  public:

  struct Bauxita{
      int cant;
  };
  queue<Bauxita> cola_bauxita;
  mutex mtx;
  condition_variable cv;
    void purification(int cant_bau){

        for(int i = 0; i <= cant_bau; ++i){
            lock_guard<mutex>  lock(mtx);
            fusion();

            cv.notify_one();
        }

    }

    void fusion(){


    }

    void electrolisis(){



    }

    void extraccion(){

        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, []{  return ;});


            lock.unlock();

            cout << "Extrayendo lingotes de aluminio... " << endl;

        }

    }

};
