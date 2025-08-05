/* tb_dff.cpp */


#include "tb_dff.h"

TB_DFF::TB_DFF(sc_module_name name)
    : sc_module(name), clk("clk", 5, SC_NS) // 5ns clock period
{
    dff = new DFF("dff");
    dff->clk(clk);
    dff->d(sig_d);
    dff->q(sig_q);

    SC_THREAD(stimulus);
}

TB_DFF::~TB_DFF() 
{
    delete dff;
}

void TB_DFF::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, clk, "CLK");
    sc_trace(tf, sig_d, "D");
    sc_trace(tf, sig_q, "Q");

    sig_d.write(0);
    wait(10, SC_NS);

    sig_d.write(1);
    wait(10, SC_NS);

    sig_d.write(0);
    wait(10, SC_NS);

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
