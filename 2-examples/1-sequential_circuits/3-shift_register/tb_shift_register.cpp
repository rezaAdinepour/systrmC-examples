/* tb_shift_register.cpp */


#include "tb_shift_register.h"

TB_ShiftRegister::TB_ShiftRegister(sc_module_name name)
    : sc_module(name), clk("clk", 5, SC_NS)
{
    sr = new ShiftRegister<8>("shiftreg");
    sr->clk(clk);
    sr->reset(sig_reset);
    sr->enable(sig_enable);
    sr->d_in(sig_din);
    sr->q(sig_q);

    SC_THREAD(stimulus);
}

TB_ShiftRegister::~TB_ShiftRegister() 
{
    delete sr;
}

void TB_ShiftRegister::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, clk, "CLK");
    sc_trace(tf, sig_reset, "RESET");
    sc_trace(tf, sig_enable, "ENABLE");
    sc_trace(tf, sig_din, "DIN");
    sc_trace(tf, sig_q, "Q");

    sig_reset.write(1);
    sig_enable.write(0);
    wait(10, SC_NS);  // reset active

    sig_reset.write(0);
    sig_enable.write(1);

    // Shift in: 1, 0, 1, 1, 0, 0, 1, 0
    bool data[] = {1, 0, 1, 1, 0, 0, 1, 0};

    for (int i = 0; i < 8; ++i) 
    {
        sig_din.write(data[i]);
        wait(5, SC_NS);
    }

    sig_enable.write(0);  // stop shifting
    wait(10, SC_NS);

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
