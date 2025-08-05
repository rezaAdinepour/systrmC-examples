/* master2.h */


#ifndef __MASTER2_H__
#define __MASTER2_H__

#include <systemc.h>

SC_MODULE(Master2) 
{
    sc_in<bool> clk;
    sc_out<bool> req;
    sc_in<bool> grant;
    sc_out<sc_uint<4> > addr;
    sc_out<sc_uint<8> > data_out;
    sc_in<sc_uint<8> > data_in;
    sc_out<bool> write_en, read_en;

    void generate();

    SC_CTOR(Master2);
};

#endif // __MASTER2_H__
