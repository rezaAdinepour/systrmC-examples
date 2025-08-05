/* mux2to1.cpp */

#include "mux2to1.h"

Mux2to1::Mux2to1(sc_module_name name) : sc_module(name)
{
    SC_METHOD(do_mux);
    sensitive << sel << a << b;
}

void Mux2to1::do_mux()
{
    y.write(sel.read() ? b.read() : a.read());
}
