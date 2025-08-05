/* testbench.h */

#ifndef __TESTBENCH_H__
#define __TESTBENCH_H__

#include <systemc.h>
#include "adder.h"

SC_MODULE(Testbench)
{
    sc_signal<int> sig_a, sig_b, sig_sum;

    Adder* adder;

    void stimulus();

    SC_CTOR(Testbench);
    ~Testbench();
};

#endif // __TESTBENCH_H__
