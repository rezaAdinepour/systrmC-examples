/* tb_comparator.h */

#ifndef __TB_COMPARATOR_H__
#define __TB_COMPARATOR_H__

#include <systemc.h>
#include "comparator.h"

SC_MODULE(TB_Comparator) 
{
    sc_signal<sc_uint<2> > sig_a, sig_b;
    sc_signal<bool> sig_eq, sig_gt, sig_lt;

    Comparator* comp;

    void stimulus();

    SC_CTOR(TB_Comparator);
    ~TB_Comparator();
};

#endif // __TB_COMPARATOR_H__
