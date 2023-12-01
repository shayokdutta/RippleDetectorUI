#include "stimulationhandler.h"

/**
 * @brief StimulationHandler::StimulationHandler
 * @param chanSelect
 * @param parent
 */
StimulationHandler::StimulationHandler(ChannelSelection *chanSelect, QObject *parent):
    dataChan(chanSelect), QObject(parent){
    connect(dataChan, &ChannelSelection::sendData, this, &StimulationHandler::handleData);
}

void StimulationHandler::handleData(){

}

