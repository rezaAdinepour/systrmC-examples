/* comparator.h */

#ifndef __COMPARATOR_H__
#define __COMPARATOR_H__

#include <systemc.h>

SC_MODULE(Comparator)
{
    sc_in<sc_uint<2> > a, b;
    sc_out<bool> eq, gt, lt;

    void do_compare();

    SC_CTOR(Comparator);
};

#endif // __COMPARATOR_H__

