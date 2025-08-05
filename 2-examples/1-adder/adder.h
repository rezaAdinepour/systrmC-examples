/* adder.h */

#ifndef __ADDER_H__
#define __ADDER_H__

#include <systemc.h>


SC_MODULE(Adder)
{
    sc_in<int> a, b;
    sc_out<int> sum;

    void do_add();

    SC_CTOR(Adder);
};


#endif // __ADDER_H__