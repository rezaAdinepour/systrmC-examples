/* decoder2to4.h */


#ifndef __DECODER2TO4_H__
#define __DECODER2TO4_H__

#include <systemc.h>

SC_MODULE(Decoder2to4) 
{
    sc_in<sc_uint<2> > sel;
    sc_out<bool> y0, y1, y2, y3;

    void do_decode();

    SC_CTOR(Decoder2to4);
};

#endif // __DECODER2TO4_H__
