/* tb_dff.h */


#ifndef __TB_DFF_H__
#define __TB_DFF_H__

#include <systemc.h>
#include "dff.h"

SC_MODULE(TB_DFF)
{
    sc_signal<bool> sig_d, sig_q;
    sc_clock clk;

    DFF* dff;

    void stimulus();

    SC_CTOR(TB_DFF);
    ~TB_DFF();
};

#endif // __TB_DFF_H__
