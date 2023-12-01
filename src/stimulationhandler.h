#ifndef STIMULATIONHANDLER_H
#define STIMULATIONHANDLER_H

#include <QObject>
#include "channelselection.h"

class StimulationHandler : public QObject{
    Q_OBJECT
public:
    StimulationHandler(ChannelSelection *chanSelect,QObject *parent = nullptr);

    // this should just be spawning all ripple detectors that are necessary
    void spawnRippleDetectors();
    void destroyRippleDetectors();

    // talk to the TTL server whether that's the Pi or Beaglebone
    void initiateStimulation();

public slots:
    void handleData(/*dataType, dataPacket*/); // receives data from ChannelSelection object

private:
    ChannelSelection* dataChan;
    // rippleDetectors
    // RPi Interface

    // all of these functions should do similar things just unpack the data properly then
    // call rippledetectors to handle things then send it back to the handleData() function
    void handleTrodesIntanData();
    void handleTrodesNPXData();
    void handleIMECData();
};

#endif // STIMULATIONHANDLER_H
