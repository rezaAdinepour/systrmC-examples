/* comparator.cpp */

#include "comparator.h"

Comparator::Comparator(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(do_compare);
    sensitive << a << b;
}

void Comparator::do_compare() 
{
    if (a.read() == b.read()) 
    {
        eq.write(true);
        gt.write(false);
        lt.write(false);
    } 
    else if (a.read() > b.read()) 
    {
        eq.write(false);
        gt.write(true);
        lt.write(false);
    } 
    else 
    {
        eq.write(false);
        gt.write(false);
        lt.write(true);
    }
}

