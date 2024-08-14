#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QDebug>
#include <QThread>
class Car:public QObject
{
    Q_OBJECT
private:
    qint32 position;
    qint32 speed;
    qint32 direction;
public:
    Car();
    Car(qint32 position,double speed,double direction);
    void move();
    void setPosition(qint32 position);
    void setSpeed(double speed);
    void setDirection(double direction);
    qint32 getPosition() const;
    double getSpeed() const;
    double getDirection() const;
signals:
    void positionChanged(qint32 position,QString id);
};

#endif // CAR_H
