/* updown_counter.h */


#ifndef __UPDOWN_COUNTER_H__
#define __UPDOWN_COUNTER_H__

#include <systemc.h>

template <int WIDTH = 4>
SC_MODULE(UpDownCounter) 
{
    sc_in<bool> clk, reset, enable, updown;
    sc_out<sc_uint<WIDTH> > q;

    void count();

    SC_CTOR(UpDownCounter);
};

#endif // __UPDOWN_COUNTER_H__
