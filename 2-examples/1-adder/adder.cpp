/* adder.cpp */

#include "adder.h"

Adder::Adder(sc_module_name name) : sc_module(name)
{
    SC_METHOD(do_add);
    sensitive << a << b;
}

void Adder::do_add() 
{
    sum.write(a.read() + b.read());
}