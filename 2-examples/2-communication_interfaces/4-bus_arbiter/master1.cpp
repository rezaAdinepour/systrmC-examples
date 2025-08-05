/* master1.cpp */


#include "master1.h"

Master1::Master1(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(generate);
    sensitive << clk.pos();
}

void Master1::generate() 
{
    req.write(false);
    write_en.write(false);
    read_en.write(false);
    wait(10, SC_NS);

    // Request and wait for grant
    req.write(true);
    wait();

    while (!grant.read()) wait();

    addr.write(0x0);
    data_out.write(0xA1);
    write_en.write(true);
    wait(5, SC_NS);
    write_en.write(false);
    req.write(false);

    wait(20, SC_NS);
}
