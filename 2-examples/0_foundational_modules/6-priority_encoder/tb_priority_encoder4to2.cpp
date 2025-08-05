/* tb_priority_encoder4to2.cpp */


#include "tb_priority_encoder4to2.h"

TB_PriorityEncoder4to2::TB_PriorityEncoder4to2(sc_module_name name) : sc_module(name) 
{
    encoder = new PriorityEncoder4to2("priority_encoder");
    encoder->in(sig_in);
    encoder->out(sig_out);
    encoder->valid(sig_valid);

    SC_THREAD(stimulus);
}

TB_PriorityEncoder4to2::~TB_PriorityEncoder4to2() 
{
    delete encoder;
}

void TB_PriorityEncoder4to2::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, sig_in, "IN");
    sc_trace(tf, sig_out, "OUT");
    sc_trace(tf, sig_valid, "VALID");

    const char* test_cases[] = 
    {
        "0000", "0001", "0010", "0100", "1000", "0011", "1010", "1111"
    };
    
    for (int i = 0; i < 8; ++i) 
    {
        sig_in.write(test_cases[i]);
        wait(1, SC_NS);
        cout << "IN=" << sig_in.read()
             << " → OUT=" << sig_out.read()
             << " VALID=" << sig_valid.read() << endl;
    }
    

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
