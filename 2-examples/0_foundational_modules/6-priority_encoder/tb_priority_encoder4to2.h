/* tb_priority_encoder4to2.h */


#ifndef __TB_PRIORITY_ENCODER4TO2_H__
#define __TB_PRIORITY_ENCODER4TO2_H__

#include <systemc.h>
#include "priority_encoder4to2.h"

SC_MODULE(TB_PriorityEncoder4to2) 
{
    sc_signal<sc_bv<4> > sig_in;
    sc_signal<sc_uint<2> > sig_out;
    sc_signal<bool> sig_valid;

    PriorityEncoder4to2* encoder;

    void stimulus();

    SC_CTOR(TB_PriorityEncoder4to2);
    ~TB_PriorityEncoder4to2();
};

#endif // __TB_PRIORITY_ENCODER4TO2_H__
