#ifndef RIPPLEDETECTOR_H
#define RIPPLEDETECTOR_H

#include <QObject>

#define ripple_filter_len 30
#define smoothing_filter_len 33

class RippleDetector : public QObject {
    Q_OBJECT
public:
    RippleDetector(bool falseDetectionChan, int samplingRate, float z_score, float timeReqInSeconds, QObject *parent=nullptr);
    ~RippleDetector();

    void updateBlockLength(float blockLengthInSeconds);
    void updateTimeReq(float timeReqInSeconds);

    void run();

    void handleNewData(float sample);

    void resetParams();

    void trainParams();

private:

    bool fd;

    bool rippleDetected;

    int postDetectionBlock;

    int fs;

    float mean, std_dev;
    float amplitude_threshold; // standard devations above mean (z-score)

    int timeThreshold_samples; // samples

    double **filter_circ_buffer;
    double **smoothing_circ_buffer;

    double ripple_filter_coefs[ripple_filter_len] = {
        0.006948895259200861,
        0.006926234072844102,
        0.006103502157617292,
        0.0019015869720564772,
        -0.008189119502501823,
        -0.024718456919193797,
        -0.04490236458710298,
        -0.06261768142301635,
        -0.07007106773169292,
        -0.060682222621851856,
        -0.03208366436487348,
        0.012060663184185196,
        0.0623490476891361,
        0.10616912299101257,
        0.131657880645337,
        0.13165788064533704,
        0.10616912299101257,
        0.06234904768913609,
        0.0120606631841852,
        -0.03208366436487348,
        -0.06068222262185186,
        -0.07007106773169292,
        -0.06261768142301641,
        -0.04490236458710301,
        -0.024718456919193794,
        -0.00818911950250182,
        0.0019015869720564766,
        0.0061035021576172944,
        0.006926234072844102,
        0.006948895259200861
    };

    double smoothing_filter_coefs[smoothing_filter_len] = {
        0.0203770957,
        0.0108532903,
        0.0134954582,
        0.0163441640,
        0.0193546202,
        0.0224738014,
        0.0256417906,
        0.0287934511,
        0.0318603667,
        0.0347729778,
        0.0374628330,
        0.0398648671,
        0.0419196133,
        0.0435752600,
        0.0447894668,
        0.0455308624,
        0.0457801628,
        0.0455308624,
        0.0447894668,
        0.0435752600,
        0.0419196133,
        0.0398648671,
        0.0374628330,
        0.0347729778,
        0.0318603667,
        0.0287934511,
        0.0256417906,
        0.0224738014,
        0.0193546202,
        0.0163441640,
        0.0134954582,
        0.0108532903,
        0.0203770957
    };
};

#endif // RIPPLEDETECTOR_H
