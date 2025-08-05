/* tb_reg_nbit.cpp */


#include "tb_reg_nbit.h"

TB_RegNBit::TB_RegNBit(sc_module_name name)
    : sc_module(name), clk("clk", 5, SC_NS) // 5ns clock
{
    reg8 = new RegNBit<8>("reg8");
    reg8->clk(clk);
    reg8->enable(sig_enable);
    reg8->d(sig_d);
    reg8->q(sig_q);

    SC_THREAD(stimulus);
}

TB_RegNBit::~TB_RegNBit() 
{
    delete reg8;
}

void TB_RegNBit::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, clk, "CLK");
    sc_trace(tf, sig_enable, "EN");
    sc_trace(tf, sig_d, "D");
    sc_trace(tf, sig_q, "Q");

    sig_enable.write(0);
    sig_d.write(0xAA);
    wait(10, SC_NS);  // Not written

    sig_enable.write(1);
    sig_d.write(0x55);
    wait(10, SC_NS);  // Written

    sig_enable.write(0);
    sig_d.write(0xFF);
    wait(10, SC_NS);  // Not written

    sig_enable.write(1);
    sig_d.write(0x0F);
    wait(10, SC_NS);  // Written

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
