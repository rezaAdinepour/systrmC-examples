/* tb_reg_nbit.h */


#ifndef __TB_REG_NBIT_H__
#define __TB_REG_NBIT_H__

#include <systemc.h>
#include "reg_nbit.h"

SC_MODULE(TB_RegNBit) 
{
    sc_signal<sc_uint<8> > sig_d, sig_q;
    sc_signal<bool> sig_enable;
    sc_clock clk;

    RegNBit<8>* reg8;

    void stimulus();

    SC_CTOR(TB_RegNBit);
    ~TB_RegNBit();
};

#endif // __TB_REG_NBIT_H__
