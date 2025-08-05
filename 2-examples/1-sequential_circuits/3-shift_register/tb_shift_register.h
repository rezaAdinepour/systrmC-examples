/* tb_shift_register.h */


#ifndef __TB_SHIFT_REGISTER_H__
#define __TB_SHIFT_REGISTER_H__

#include <systemc.h>
#include "shift_register.h"

SC_MODULE(TB_ShiftRegister) 
{
    sc_signal<bool> sig_din, sig_reset, sig_enable;
    sc_signal<sc_uint<8> > sig_q;
    sc_clock clk;

    ShiftRegister<8>* sr;

    void stimulus();

    SC_CTOR(TB_ShiftRegister);
    ~TB_ShiftRegister();
};

#endif // __TB_SHIFT_REGISTER_H__
