/* tb_decoder2to4.h */


#ifndef __TB_DECODER2TO4_H__
#define __TB_DECODER2TO4_H__

#include <systemc.h>
#include "decoder2to4.h"

SC_MODULE(TB_Decoder2to4) 
{
    sc_signal<sc_uint<2> > sig_sel;
    sc_signal<bool> sig_y0, sig_y1, sig_y2, sig_y3;

    Decoder2to4* decoder;

    void stimulus();

    SC_CTOR(TB_Decoder2to4);
    ~TB_Decoder2to4();
};

#endif // __TB_DECODER2TO4_H__
