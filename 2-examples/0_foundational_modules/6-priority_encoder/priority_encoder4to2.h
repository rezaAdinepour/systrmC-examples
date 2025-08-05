/* priority_encoder4to2.h */


#ifndef __PRIORITY_ENCODER4TO2_H__
#define __PRIORITY_ENCODER4TO2_H__

#include <systemc.h>

SC_MODULE(PriorityEncoder4to2) 
{
    sc_in<sc_bv<4> > in;
    sc_out<sc_uint<2> > out;
    sc_out<bool> valid;

    void do_encode();

    SC_CTOR(PriorityEncoder4to2);
};

#endif // __PRIORITY_ENCODER4TO2_H__
