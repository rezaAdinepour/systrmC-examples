/* stage2.h */


#ifndef __STAGE2_H__
#define __STAGE2_H__

#include <systemc.h>

SC_MODULE(Stage2) 
{
    sc_in<bool> clk;
    sc_fifo_in<sc_uint<8> > in;
    sc_fifo_out<sc_uint<8> > out;

    void process();

    SC_CTOR(Stage2);
};

#endif // __STAGE2_H__
