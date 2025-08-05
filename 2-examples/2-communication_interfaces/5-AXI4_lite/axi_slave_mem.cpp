/* axi_slave_mem.cpp */


#include "axi_slave_mem.h"
#include <iostream>

AxiSlaveMem::AxiSlaveMem(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(write_process);
    sensitive << clk.pos();

    SC_THREAD(read_process);
    sensitive << clk.pos();
}

void AxiSlaveMem::write_process() 
{
    awready.write(false);
    wready.write(false);
    bvalid.write(false);

    while (true) 
    {
        wait();
        if (awvalid.read()) 
        {
            awready.write(true);
            wait();
            awready.write(false);
        }

        if (wvalid.read()) 
        {
            wready.write(true);
            sc_uint<32> addr = awaddr.read() / 4;
            if (addr < 64) 
            {
                mem[addr] = wdata.read();
                std::cout << sc_time_stamp() << " [SLAVE] Write to mem[" << addr << "] = " << mem[addr] << std::endl;
            }
            wait();
            wready.write(false);
            bvalid.write(true);
            do { wait(); } while (!bready.read());
            bvalid.write(false);
        }
    }
}

void AxiSlaveMem::read_process() 
{
    arready.write(false);
    rvalid.write(false);

    while (true) 
    {
        wait();
        if (arvalid.read()) 
        {
            arready.write(true);
            wait();
            arready.write(false);

            sc_uint<32> addr = araddr.read() / 4;
            sc_uint<32> val = (addr < 64) ? mem[addr] : sc_uint<32>(0xDEADBEEF);
            rdata.write(val);
            std::cout << sc_time_stamp() << " [SLAVE] Read from mem[" << addr << "] = " << val << std::endl;

            rvalid.write(true);
            do { wait(); } while (!rready.read());
            rvalid.write(false);
        }
    }
}