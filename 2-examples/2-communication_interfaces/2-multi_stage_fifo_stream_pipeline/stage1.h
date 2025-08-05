/* stage1.h */


#ifndef __STAGE1_H__
#define __STAGE1_H__

#include <systemc.h>

SC_MODULE(Stage1) 
{
    sc_in<bool> clk;
    sc_fifo_in<sc_uint<8> > in;
    sc_fifo_out<sc_uint<8> > out;

    void process();

    SC_CTOR(Stage1);
};

#endif // __STAGE1_H__
