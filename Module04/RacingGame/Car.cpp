#include "Car.h"

Car::Car() {}
Car::Car(qint32 position,double speed,double direction)
    :position(position),speed(speed),direction(direction){
    qDebug()<<"Car Generated\n";
}
void Car::move(){
    position+=speed*direction;
    qDebug()<<"car.move\n";
    QString id=QThread::currentThread()->objectName();
    emit positionChanged(position,id);
}
void Car::setPosition(qint32 position){
    this->position=position;
}
void Car::setSpeed(double speed){
    this->speed=speed;
}
void Car::setDirection(double direction){
    this->direction=direction;
}
qint32 Car::getPosition() const{
    return position;
}
double Car::getSpeed() const{
    return speed;
}
double Car::getDirection() const{
    return direction;
}

