/* shift_register.h */


#ifndef __SHIFT_REGISTER_H__
#define __SHIFT_REGISTER_H__

#include <systemc.h>

template <int WIDTH = 8>
SC_MODULE(ShiftRegister) 
{
    sc_in<bool> clk, reset, enable;
    sc_in<bool> d_in;
    sc_out<sc_uint<WIDTH> > q;

    void do_shift();

    SC_CTOR(ShiftRegister);
};

#endif // __SHIFT_REGISTER_H__
