#ifndef CARTHREAD_H
#define CARTHREAD_H
#include <QThread>
#include <QMutex>
#include "Car.h"
#include "racetrack.h"

class Carthread:public QThread
{
    Q_OBJECT
private:
    Car* car;
    QMutex m;

public:
    Carthread(Car *car);
signals:
    void arrivedFinishline(QString id);
public slots:
    void run() override;
};

#endif // CARTHREAD_H
