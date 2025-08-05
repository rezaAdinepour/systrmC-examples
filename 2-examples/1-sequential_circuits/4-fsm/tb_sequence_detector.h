/* tb_sequence_detector.h */


#ifndef __TB_SEQUENCE_DETECTOR_H__
#define __TB_SEQUENCE_DETECTOR_H__

#include <systemc.h>
#include "sequence_detector.h"

SC_MODULE(TB_SequenceDetector) 
{
    sc_signal<bool> sig_reset, sig_din, sig_detected;
    sc_clock clk;

    SequenceDetector* fsm;

    void stimulus();

    SC_CTOR(TB_SequenceDetector);
    ~TB_SequenceDetector();
};

#endif // __TB_SEQUENCE_DETECTOR_H__
