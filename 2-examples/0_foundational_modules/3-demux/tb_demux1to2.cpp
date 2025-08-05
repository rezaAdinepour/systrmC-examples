/* tb_demux1to2.cpp */

#include "tb_demux1to2.h"

TB_Demux1to2::TB_Demux1to2(sc_module_name name) : sc_module(name) 
{
    demux = new Demux1to2("demux1to2");
    demux->in(sig_in);
    demux->sel(sig_sel);
    demux->y0(sig_y0);
    demux->y1(sig_y1);

    SC_THREAD(stimulus);
}

TB_Demux1to2::~TB_Demux1to2() 
{
    delete demux;
}

void TB_Demux1to2::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, sig_in, "IN");
    sc_trace(tf, sig_sel, "SEL");
    sc_trace(tf, sig_y0, "Y0");
    sc_trace(tf, sig_y1, "Y1");

    sig_in.write(1);

    sig_sel.write(0);
    wait(1, SC_NS);
    cout << "SEL=0: Y0=" << sig_y0.read() << " Y1=" << sig_y1.read() << endl;

    sig_sel.write(1);
    wait(1, SC_NS);
    cout << "SEL=1: Y0=" << sig_y0.read() << " Y1=" << sig_y1.read() << endl;

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
