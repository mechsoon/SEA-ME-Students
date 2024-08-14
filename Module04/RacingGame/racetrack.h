#ifndef RACETRACK_H
#define RACETRACK_H
#include <QGraphicsItem>
#include <QPainter>

class RaceTrack
{
private:
    qint32 size;
    qint32 finishLine;
public:
    RaceTrack();
    RaceTrack(qint32 size,qint32 finishLine);
    void setFinishLine(qint32 newFinishLine);
    qint32 getFinishLine() const;
};

#endif // RACETRACK_H
