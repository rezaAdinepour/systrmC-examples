/* shift_register.cpp */


#include "shift_register.h"

template <int WIDTH>
ShiftRegister<WIDTH>::ShiftRegister(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(do_shift);
    sensitive << clk.pos();
}

template <int WIDTH>
void ShiftRegister<WIDTH>::do_shift() 
{
    if (reset.read()) 
    {
        q.write(0);
    } 
    else if (enable.read()) 
    {
        sc_uint<WIDTH> val = q.read();
        val = (val >> 1) | (d_in.read() << (WIDTH - 1));
        q.write(val);
    }
}

// Explicit instantiation for 8-bit version
template class ShiftRegister<8>;
