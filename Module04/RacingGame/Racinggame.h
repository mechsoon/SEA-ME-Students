#ifndef RACINGGAME_H
#define RACINGGAME_H
#include <QMainWindow>
#include <set>
#include "racetrack.h"
#include "Carthread.h"
#include "Car.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class RacingGame;
}
QT_END_NAMESPACE

class RacingGame : public QMainWindow
{
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr);
    ~RacingGame();
private slots:
    void StartGame();
    // void PauseGame();
    void ExitGame();
    void updatePostion(qint32 position,QString id);
    void deleteCar(QString id);

signals:
    void repetition();

private:
    Ui::RacingGame *ui;
    QList<Car*> carlist;
    QList<QThread*> threadlist;
    RaceTrack* racetrack;
    std::set<QString> rank;
    QMutex m;
};
#endif // RACINGGAME_H
