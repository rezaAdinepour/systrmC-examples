/* tb_sequence_detector.cpp */


#include "tb_sequence_detector.h"

TB_SequenceDetector::TB_SequenceDetector(sc_module_name name)
    : sc_module(name), clk("clk", 5, SC_NS)
{
    fsm = new SequenceDetector("seq_detector");
    fsm->clk(clk);
    fsm->reset(sig_reset);
    fsm->din(sig_din);
    fsm->detected(sig_detected);

    SC_THREAD(stimulus);
}

TB_SequenceDetector::~TB_SequenceDetector() 
{
    delete fsm;
}

void TB_SequenceDetector::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, clk, "CLK");
    sc_trace(tf, sig_reset, "RESET");
    sc_trace(tf, sig_din, "DIN");
    sc_trace(tf, sig_detected, "DETECTED");

    sig_reset.write(1);
    sig_din.write(0);
    wait(10, SC_NS);

    sig_reset.write(0);

    // Send sequence: 1 0 1 1 → match
    // Then more sequences for test coverage
    bool input_sequence[] = {
        0, 1, 0, 1, 1,  // 1011 (match)
        0, 1, 1, 1,     // no match
        1, 0, 1, 1,     // 1011 (match)
        1, 0, 0         // no match
    };

    for (int i = 0; i < sizeof(input_sequence)/sizeof(bool); ++i) 
    {
        sig_din.write(input_sequence[i]);
        wait(5, SC_NS);
    }

    wait(10, SC_NS);
    sc_close_vcd_trace_file(tf);
    sc_stop();
}
