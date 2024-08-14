#include "racetrack.h"

RaceTrack::RaceTrack():size(500),finishLine(500) {}
RaceTrack::RaceTrack(qint32 size,qint32 finishLine):size(size),finishLine(finishLine){
}
void RaceTrack::setFinishLine(qint32 newFinishLine){
    finishLine=newFinishLine;
}
qint32 RaceTrack::getFinishLine() const{
    return finishLine;

}
