#include "stimulationhandler.h"

/**
 * @brief StimulationHandler::StimulationHandler
 * @param chanSelect
 * @param parent
 */
StimulationHandler::StimulationHandler(ChannelSelection *chanSelect, DataInterface *dataInterface, QObject *parent):
    dataChan(chanSelect), dataInterfacePtr(dataInterface), QObject(parent){

    connect(dataChan, &ChannelSelection::theseChannels, this, &StimulationHandler::sendChannels);

    connect(dataChan, &ChannelSelection::sendData, this, &StimulationHandler::handleData);

}

/**
 * @brief StimulationHandler::handleData
 */
void StimulationHandler::handleData(){

}


/**
 * @brief StimulationHandler::sendChannels
 * @param channels
 */
void StimulationHandler::sendChannels(QVector<int> channels){
    // send message to clear data from shared memory
    // this essentially accounts for resets of channels
    this->sendSocketMessage("nonibbles");

    // handle the false detection channel slightly differently with regards to spawning it
    if(dataChan->fdChanSet()){
        // spawn ripple detector with false ripple detector channel
        // the false ripple detector is the last channel in the QVector

    }

    // Convert channels QVector to a comma-separated string
    std::string channelsStr;
    for (int channel : channels) {
        channelsStr += std::to_string(channel) + "\n";
    }

    // Remove last newline
    if (!channelsStr.empty()) {
        channelsStr.pop_back();
    }

    // spawn all ripple detectors

    // write all channels to shared memory
    dataInterfacePtr->writeToSharedMemory(channelsStr);
}

/**
 * @brief StimulationHandler::sendSocketMessage
 * @param msg
 */
void StimulationHandler::sendSocketMessage(std::string msg){
    dataInterfacePtr->writeToSocket(msg);
}
