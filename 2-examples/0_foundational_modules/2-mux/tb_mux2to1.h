/* tb_mux2to1.ch */

#ifndef __TB_MUX2TO1_H__
#define __TB_MUX2TO1_H__

#include <systemc.h>
#include "mux2to1.h"

SC_MODULE(TB_Mux2to1) {
    sc_signal<bool> sig_a, sig_b, sig_sel, sig_y;

    Mux2to1* mux;

    void stimulus();

    SC_CTOR(TB_Mux2to1);
    ~TB_Mux2to1();
};

#endif // __TB_MUX2TO1_H__
