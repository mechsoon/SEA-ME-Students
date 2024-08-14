#include "Carthread.h"

Carthread::Carthread(Car *car):car(car) {}

void Carthread::run(){
    if(car->getPosition()<700){
        // m.lock();
        car->move();
        // m.unlock();
        msleep(10);
        qDebug()<<QThread::currentThread()->objectName()<<"move\n position: "<<car->getPosition()<<"\n";
    }else{

        emit arrivedFinishline(QThread::currentThread()->objectName());
    }
}
