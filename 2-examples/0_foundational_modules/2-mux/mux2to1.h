/* mux2to1.h */

#ifndef __MUX2TO1_H__
#define __MUX2TO1_H__

#include <systemc.h>

SC_MODULE(Mux2to1)
{
    sc_in<bool> sel;
    sc_in<bool> a, b;
    sc_out<bool> y;

    void do_mux();

    SC_CTOR(Mux2to1);
};

#endif // __MUX2TO1_H__
