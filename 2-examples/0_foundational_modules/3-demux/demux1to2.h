/* demux1to2.h */

#ifndef __DEMUX1TO2_H__
#define __DEMUX1TO2_H__

#include <systemc.h>

SC_MODULE(Demux1to2)
{
    sc_in<bool> sel;
    sc_in<bool> in;
    sc_out<bool> y0, y1;

    void do_demux();

    SC_CTOR(Demux1to2);
};

#endif // __DEMUX1TO2_H__
