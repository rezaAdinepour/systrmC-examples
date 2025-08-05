/* axi_slave_mem.h */


#ifndef __AXI_SLAVE_MEM_H__
#define __AXI_SLAVE_MEM_H__

#include <systemc.h>

SC_MODULE(AxiSlaveMem) 
{
    sc_in<bool> clk;
    
    // Write address channel
    sc_in<bool> awvalid;
    sc_out<bool> awready;
    sc_in<sc_uint<32> > awaddr;
    
    // Write data channel
    sc_in<bool> wvalid;
    sc_out<bool> wready;
    sc_in<sc_uint<32> > wdata;

    // Write response
    sc_out<bool> bvalid;
    sc_in<bool> bready;

    // Read address channel
    sc_in<bool> arvalid;
    sc_out<bool> arready;
    sc_in<sc_uint<32> > araddr;

    // Read data channel
    sc_out<bool> rvalid;
    sc_in<bool> rready;
    sc_out<sc_uint<32> > rdata;

    sc_uint<32> mem[64];  // 256B memory (64x32-bit)

    void write_process();
    void read_process();

    SC_CTOR(AxiSlaveMem);
};

#endif // __AXI_SLAVE_MEM_H__
