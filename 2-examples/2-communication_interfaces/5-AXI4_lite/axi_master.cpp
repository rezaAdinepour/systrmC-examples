/* axi_master.cpp */


#include "axi_master.h"

AxiMaster::AxiMaster(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(run);
    sensitive << clk.pos();
}

void AxiMaster::run() 
{
    // === WRITE Transaction ===
    awaddr.write(0x10);
    wdata.write(0xBEEF);
    awvalid.write(true);
    wvalid.write(true);
    bready.write(true);

    // Wait for handshake
    do { wait(); } while (!awready.read());
    awvalid.write(false);
    do { wait(); } while (!wready.read());
    wvalid.write(false);

    do { wait(); } while (!bvalid.read());
    bready.write(false);

    wait(10, SC_NS);  // Delay

    // === READ Transaction ===
    araddr.write(0x10);
    arvalid.write(true);
    rready.write(true);

    do { wait(); } while (!arready.read());
    arvalid.write(false);

    do { wait(); } while (!rvalid.read());
    sc_uint<32> read_val = rdata.read();
    std::cout << sc_time_stamp() << " [MASTER] Read value: 0x" << std::hex << read_val << std::endl;

    rready.write(false);
}
