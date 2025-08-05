/* reg_nbit.cpp */


#include "reg_nbit.h"

template <int WIDTH>
RegNBit<WIDTH>::RegNBit(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(do_register);
    sensitive << clk.pos();
}

template <int WIDTH>
void RegNBit<WIDTH>::do_register() 
{
    if (enable.read()) {
        q.write(d.read());
    }
}

// Explicit template instantiation for 8-bit version
template class RegNBit<8>;
