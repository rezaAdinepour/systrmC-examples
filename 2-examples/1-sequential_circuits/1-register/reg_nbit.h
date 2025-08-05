/* reg_nbit.h */


#ifndef __REG_NBIT_H__
#define __REG_NBIT_H__

#include <systemc.h>

template <int WIDTH = 8>
SC_MODULE(RegNBit) 
{
    sc_in<bool> clk;
    sc_in<bool> enable;
    sc_in<sc_uint<WIDTH> > d;
    sc_out<sc_uint<WIDTH> > q;

    void do_register();

    SC_CTOR(RegNBit);
};

#endif // __REG_NBIT_H__
