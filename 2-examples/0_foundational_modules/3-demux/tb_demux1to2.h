/* tb_demux1to2.cpp */

#ifndef __TB_DEMUX1TO2_H__
#define __TB_DEMUX1TO2_H__

#include <systemc.h>
#include "demux1to2.h"

SC_MODULE(TB_Demux1to2) 
{
    sc_signal<bool> sig_in, sig_sel, sig_y0, sig_y1;

    Demux1to2* demux;

    void stimulus();

    SC_CTOR(TB_Demux1to2);
    ~TB_Demux1to2();
};

#endif // __TB_DEMUX1TO2_H__
