#include "Racinggame.h"
#include "./ui_Racinggame.h"

RacingGame::RacingGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RacingGame)
{
    ui->setupUi(this);
    racetrack=new RaceTrack(400,700);
    // how to make carlist? in car,

    connect(ui->startbtn,&QPushButton::clicked,this,&RacingGame::StartGame);
    connect(ui->exitbtn,&QPushButton::clicked,this,&RacingGame::ExitGame);
}


/* what i have to implement.
    1. if press start button, generate car(4), thread generate, movethread. set finishline
    2. during game, using slot signal, update car's position. if position==finishline, emit signal, and thread quit, delete
    3. */


void RacingGame::deleteCar(QString id){
    // if(id=="Car 1"){
    //     delete ui->car1;
    //     ui->car1=nullptr;
    // }else if(id=="Car 2"){
    //     delete ui->car2;
    //     ui->car2=nullptr;
    // }
    // else if(id=="Car 3"){
    //     delete ui->car3;
    //     ui->car3=nullptr;
    // }
    // else{
    //     delete ui->car4;
    //     ui->car4=nullptr;
    // }

    rank.insert(id);
}

// smartpoint 이용

void RacingGame::StartGame(){
        // qDebug()<<racetrack->getFinishLine();
        int index=1;
        carlist.append(new Car(ui->car1->x(),1,1));
        carlist.append(new Car(ui->car2->x(),1,1));
        carlist.append(new Car(ui->car3->x(),1,1));
        carlist.append(new Car(ui->car4->x(),1,1));
        racetrack->setFinishLine(ui->finishline->x());
        for(int i=0;i<carlist.size();i++){
            QThread *thread=new QThread();
            Carthread *carthread=new Carthread(carlist[i]);
            carthread->moveToThread(thread);
            thread->setObjectName(QString("Car %1").arg(index++));
            qDebug()<<thread->objectName()<<"\n";
            // bool connected = connect(thread,&QThread::finished,thread,&QThread::deleteLater);
            // qDebug()<<"connected  "<<connected;
            connect(carlist[i],&Car::positionChanged,this,&RacingGame::updatePostion);
            connect(thread,&QThread::started,carthread,&Carthread::run);
            connect(this,&RacingGame::repetition,carthread,&Carthread::run);
            connect(carthread,&Carthread::arrivedFinishline,this,&RacingGame::deleteCar);
            connect(carthread,&Carthread::arrivedFinishline,thread,&QThread::quit);
            connect(carthread,&Carthread::arrivedFinishline,carthread,&Carthread::deleteLater);
            connect(thread,&QThread::finished,thread,&QThread::deleteLater);
            thread->start();
            threadlist.append(thread);
        }


}

// void RacingGame::PauseGame(){

// }
void RacingGame::ExitGame(){
    return;
}
void RacingGame::updatePostion(qint32 position,QString id){

    if(id=="Car 1"){
        ui->car1->move(position,ui->car1->y());
        carlist[0]->setPosition(position);

    }else if(id=="Car 2"){
        ui->car2->move(position,ui->car2->y());
        carlist[1]->setPosition(position);

    }
    else if(id=="Car 3"){
        ui->car3->move(position,ui->car3->y());
        carlist[2]->setPosition(position);

    }
    else if(id=="Car 4")
    {
        ui->car4->move(position,ui->car4->y());
        carlist[3]->setPosition(position);

    }else{
        qDebug()<<QThread::currentThread()->objectName();
    }

    emit repetition();


}
RacingGame::~RacingGame()
{
    delete ui;

    delete racetrack;

}
