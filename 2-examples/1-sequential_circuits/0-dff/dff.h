/* dff.h */


#ifndef __DFF_H__
#define __DFF_H__

#include <systemc.h>

SC_MODULE(DFF) 
{
    sc_in<bool> clk;
    sc_in<bool> d;
    sc_out<bool> q;

    void do_dff();

    SC_CTOR(DFF);
};

#endif // __DFF_H__
