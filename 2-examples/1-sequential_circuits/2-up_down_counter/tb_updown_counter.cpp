/* tb_updown_counter.cpp */


#include "tb_updown_counter.h"

TB_UpDownCounter::TB_UpDownCounter(sc_module_name name)
    : sc_module(name), clk("clk", 5, SC_NS)
{
    counter = new UpDownCounter<4>("counter");
    counter->clk(clk);
    counter->reset(sig_reset);
    counter->enable(sig_enable);
    counter->updown(sig_updown);
    counter->q(sig_q);

    SC_THREAD(stimulus);
}

TB_UpDownCounter::~TB_UpDownCounter() 
{
    delete counter;
}

void TB_UpDownCounter::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, clk, "CLK");
    sc_trace(tf, sig_reset, "RESET");
    sc_trace(tf, sig_enable, "EN");
    sc_trace(tf, sig_updown, "UPDOWN");
    sc_trace(tf, sig_q, "Q");

    // Reset initially
    sig_reset.write(1);
    sig_enable.write(0);
    sig_updown.write(1);  // up
    wait(10, SC_NS);

    sig_reset.write(0);
    sig_enable.write(1);
    wait(30, SC_NS);  // count up for 3 cycles

    sig_updown.write(0);  // count down
    wait(30, SC_NS);

    sig_enable.write(0);  // pause
    wait(10, SC_NS);

    sig_reset.write(1);  // reset again
    wait(10, SC_NS);

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
