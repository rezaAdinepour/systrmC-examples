/* demux1to2.cpp */

#include "demux1to2.h"

Demux1to2::Demux1to2(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(do_demux);
    sensitive << sel << in;
}

void Demux1to2::do_demux() 
{
    if (sel.read() == 0) 
    {
        y0.write(in.read());
        y1.write(false);
    } 
    else 
    {
        y0.write(false);
        y1.write(in.read());
    }
}
