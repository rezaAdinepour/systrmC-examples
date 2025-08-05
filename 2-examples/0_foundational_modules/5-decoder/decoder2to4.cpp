/* decoder2to4.cpp */


#include "decoder2to4.h"

Decoder2to4::Decoder2to4(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(do_decode);
    sensitive << sel;
}

void Decoder2to4::do_decode() 
{
    // Clear all outputs
    y0.write(0);
    y1.write(0);
    y2.write(0);
    y3.write(0);

    switch (sel.read()) 
    {
        case 0: y0.write(1); break;
        case 1: y1.write(1); break;
        case 2: y2.write(1); break;
        case 3: y3.write(1); break;
    }
}
