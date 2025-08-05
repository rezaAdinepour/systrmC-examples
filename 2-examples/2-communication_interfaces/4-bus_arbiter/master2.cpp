/* master2.cpp */


#include "master2.h"

Master2::Master2(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(generate);
    sensitive << clk.pos();
}

void Master2::generate() 
{
    req.write(false);
    write_en.write(false);
    read_en.write(false);
    wait(20, SC_NS);  // Master 2 starts later

    // Request and wait for grant
    req.write(true);
    wait();

    while (!grant.read()) wait();

    addr.write(0x1);
    data_out.write(0xB2);
    write_en.write(true);
    wait(5, SC_NS);
    write_en.write(false);
    req.write(false);

    wait(15, SC_NS);  // Some delay before trying to read

    req.write(true);
    wait();

    while (!grant.read()) wait();

    addr.write(0x1);
    read_en.write(true);
    wait(5, SC_NS);
    read_en.write(false);
    req.write(false);

    wait(20, SC_NS);
}
