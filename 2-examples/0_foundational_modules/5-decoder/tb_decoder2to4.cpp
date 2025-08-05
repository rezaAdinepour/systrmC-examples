/* tb_decoder2to4.cpp */


#include "tb_decoder2to4.h"

TB_Decoder2to4::TB_Decoder2to4(sc_module_name name) : sc_module(name) 
{
    decoder = new Decoder2to4("decoder2to4");
    decoder->sel(sig_sel);
    decoder->y0(sig_y0);
    decoder->y1(sig_y1);
    decoder->y2(sig_y2);
    decoder->y3(sig_y3);

    SC_THREAD(stimulus);
}

TB_Decoder2to4::~TB_Decoder2to4() 
{
    delete decoder;
}

void TB_Decoder2to4::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, sig_sel, "SEL");
    sc_trace(tf, sig_y0, "Y0");
    sc_trace(tf, sig_y1, "Y1");
    sc_trace(tf, sig_y2, "Y2");
    sc_trace(tf, sig_y3, "Y3");

    for (int i = 0; i < 4; ++i) 
    {
        sig_sel.write(i);
        wait(1, SC_NS);
        cout << "SEL=" << i
             << " → Y0=" << sig_y0.read()
             << " Y1=" << sig_y1.read()
             << " Y2=" << sig_y2.read()
             << " Y3=" << sig_y3.read() << endl;
    }

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
