/* sequence_detector.h */


#ifndef __SEQUENCE_DETECTOR_H__
#define __SEQUENCE_DETECTOR_H__

#include <systemc.h>

SC_MODULE(SequenceDetector) 
{
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<bool> din;
    sc_out<bool> detected;

    void process();

    SC_CTOR(SequenceDetector);

private:
    enum State { S0, S1, S2, S3, S4 };
    State current_state;
};

#endif // __SEQUENCE_DETECTOR_H__
