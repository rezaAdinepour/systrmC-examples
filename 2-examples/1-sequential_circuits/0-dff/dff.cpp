/* dff.cpp */


#include "dff.h"

DFF::DFF(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(do_dff);
    sensitive << clk.pos();  // Triggered on rising edge
}

void DFF::do_dff() 
{
    q.write(d.read());
}
