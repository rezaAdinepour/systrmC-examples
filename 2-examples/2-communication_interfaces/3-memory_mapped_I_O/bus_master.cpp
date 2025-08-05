/* bus_master.cpp */


#include "bus_master.h"

BusMaster::BusMaster(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(run);
    sensitive << clk.pos();
}

void BusMaster::run() 
{
    // Initial state
    addr.write(0);
    data_out.write(0);
    write_en.write(0);
    read_en.write(0);
    wait(5, SC_NS);

    // Write 0xAA to REG_A (addr 0)
    addr.write(0x0);
    data_out.write(0xAA);
    write_en.write(1);
    wait(5, SC_NS);

    write_en.write(0);  // stop write
    wait(5, SC_NS);

    // Write 0x55 to REG_B (addr 1)
    addr.write(0x1);
    data_out.write(0x55);
    write_en.write(1);
    wait(5, SC_NS);

    write_en.write(0);
    wait(5, SC_NS);

    // Read REG_A
    addr.write(0x0);
    read_en.write(1);
    wait(5, SC_NS);
    cout << sc_time_stamp() << " - Read REG_A = " << data_in.read() << endl;
    read_en.write(0);

    // Read REG_B
    addr.write(0x1);
    read_en.write(1);
    wait(5, SC_NS);
    cout << sc_time_stamp() << " - Read REG_B = " << data_in.read() << endl;
    read_en.write(0);

    // End simulation
    sc_stop();
}
