/* axi_master.h */


#ifndef __AXI_MASTER_H__
#define __AXI_MASTER_H__

#include <systemc.h>

SC_MODULE(AxiMaster) 
{
    sc_in<bool> clk;
    sc_out<bool> awvalid, wvalid, arvalid, bready, rready;
    sc_out<sc_uint<32> > awaddr, araddr;
    sc_out<sc_uint<32> > wdata;
    sc_in<bool> awready, wready, bvalid, arready, rvalid;
    sc_in<sc_uint<32> > rdata;

    void run();

    SC_CTOR(AxiMaster);
};

#endif // __AXI_MASTER_H__
