/* tb_mux2to1.cpp */

#include "tb_mux2to1.h"

TB_Mux2to1::TB_Mux2to1(sc_module_name name) : sc_module(name)
{
    mux = new Mux2to1("mux2to1");
    mux->a(sig_a);
    mux->b(sig_b);
    mux->sel(sig_sel);
    mux->y(sig_y);

    SC_THREAD(stimulus);
}

TB_Mux2to1::~TB_Mux2to1() 
{
    delete mux;
}

void TB_Mux2to1::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, sig_a, "A");
    sc_trace(tf, sig_b, "B");
    sc_trace(tf, sig_sel, "SEL");
    sc_trace(tf, sig_y, "Y");

    sig_a.write(0); sig_b.write(1);

    sig_sel.write(0);
    wait(1, SC_NS);
    cout << "SEL=0: Y=" << sig_y.read() << endl;

    sig_sel.write(1);
    wait(1, SC_NS);
    cout << "SEL=1: Y=" << sig_y.read() << endl;

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
