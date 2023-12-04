#include "stimulationhandler.h"

/**
 * @brief StimulationHandler::StimulationHandler
 * @param chanSelect
 * @param parent
 */
StimulationHandler::StimulationHandler(ChannelSelection *chanSelect, DataInterface *dataInterface, QObject *parent):
    dataChan(chanSelect), dataInterfacePtr(dataInterface), QObject(parent){

    connect(dataChan, &ChannelSelection::sendData, this, &StimulationHandler::handleData);

}

void StimulationHandler::handleData(){

}

