#include "rippledetector.h"

RippleDetector::RippleDetector(bool falseDetectionChan, int samplingRate,
                               float z_score, float timeReqInSeconds, QObject *parent):
    fd(falseDetectionChan), fs(samplingRate), amplitude_threshold(z_score), QObject(parent){

    postDetectionBlock = static_cast<int>(std::ceil(static_cast<float>(fs) * 0.2f)); // 200 ms block length
    rippleDetected = false;

    timeThreshold_samples = std::ceil(static_cast<float>(fs) * timeReqInSeconds);

}

RippleDetector::~RippleDetector() {}

/**
 * @brief RippleDetector::updateBlockLength
 * @param blockLengthInSeconds
 */
void RippleDetector::updateBlockLength(float blockLengthInSeconds){
    postDetectionBlock = static_cast<int>(
                            std::ceil(static_cast<float>(fs) * blockLengthInSeconds)
                        );
}

void RippleDetector::updateTimeReq(float timeReqInSeconds){
    timeThreshold_samples = std::ceil(static_cast<float>(fs) * timeReqInSeconds);
}

/**
 * @brief RippleDetector::run Run thread for the RippleDetector
 */
void RippleDetector::run(){
    // read proper area of shared memory
    // pass data to new data if ripple detection is enabled
}

void RippleDetector::handleNewData(float sample){
    // perform checks for threshold crossing (amplitude and time)

    // or send data to train parameters
}

void RippleDetector::resetParams(){

}

void RippleDetector::trainParams(){

}
