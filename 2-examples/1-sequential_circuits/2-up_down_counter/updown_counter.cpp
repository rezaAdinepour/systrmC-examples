/* updown_counter.cpp */


#include "updown_counter.h"

template <int WIDTH>
UpDownCounter<WIDTH>::UpDownCounter(sc_module_name name) : sc_module(name)
{
    SC_METHOD(count);
    sensitive << clk.pos();
}

template <int WIDTH>
void UpDownCounter<WIDTH>::count() 
{
    if (reset.read()) 
    {
        q.write(0);
    } 
    else if (enable.read()) 
    {
        sc_uint<WIDTH> val = q.read();
        if (updown.read())  // Count up
            q.write(val + 1);
        else                // Count down
            q.write(val - 1);
    }
}

// Explicit instantiation
template class UpDownCounter<4>;
