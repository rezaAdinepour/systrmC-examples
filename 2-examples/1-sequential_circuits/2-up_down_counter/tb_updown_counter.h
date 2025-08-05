/* tb_updown_counter.h */


#ifndef __TB_UPDOWN_COUNTER_H__
#define __TB_UPDOWN_COUNTER_H__

#include <systemc.h>
#include "updown_counter.h"

SC_MODULE(TB_UpDownCounter) 
{
    sc_signal<bool> sig_reset, sig_enable, sig_updown;
    sc_signal<sc_uint<4> > sig_q;
    sc_clock clk;

    UpDownCounter<4>* counter;

    void stimulus();

    SC_CTOR(TB_UpDownCounter);
    ~TB_UpDownCounter();
};

#endif // __TB_UPDOWN_COUNTER_H__
