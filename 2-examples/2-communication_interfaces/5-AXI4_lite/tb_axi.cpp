/* tb_axi.cpp */


#include <systemc.h>
#include "axi_master.h"
#include "axi_slave_mem.h"

int sc_main(int argc, char* argv[]) 
{
    sc_clock clk("clk", 10, SC_NS);

    // Signals
    sc_signal<bool> awvalid, awready, wvalid, wready, bvalid, bready;
    sc_signal<bool> arvalid, arready, rvalid, rready;
    sc_signal<sc_uint<32> > awaddr, araddr, wdata, rdata;

    // Modules
    AxiMaster master("master");
    master.clk(clk);
    master.awvalid(awvalid); master.awaddr(awaddr);
    master.wvalid(wvalid); master.wdata(wdata);
    master.bready(bready); master.bvalid(bvalid);
    master.arvalid(arvalid); master.araddr(araddr);
    master.rready(rready); master.rvalid(rvalid); master.rdata(rdata);
    master.awready(awready); master.wready(wready); master.arready(arready);

    AxiSlaveMem slave("slave");
    slave.clk(clk);
    slave.awvalid(awvalid); slave.awaddr(awaddr); slave.awready(awready);
    slave.wvalid(wvalid); slave.wdata(wdata); slave.wready(wready);
    slave.bvalid(bvalid); slave.bready(bready);
    slave.arvalid(arvalid); slave.araddr(araddr); slave.arready(arready);
    slave.rvalid(rvalid); slave.rready(rready); slave.rdata(rdata);

    // Trace
    sc_trace_file* tf = sc_create_vcd_trace_file("axi4_lite_trace");
    tf->set_time_unit(1, SC_NS);
    sc_trace(tf, clk, "clk");
    sc_trace(tf, awvalid, "awvalid"); sc_trace(tf, awready, "awready");
    sc_trace(tf, wvalid, "wvalid"); sc_trace(tf, wready, "wready");
    sc_trace(tf, bvalid, "bvalid"); sc_trace(tf, bready, "bready");
    sc_trace(tf, arvalid, "arvalid"); sc_trace(tf, arready, "arready");
    sc_trace(tf, rvalid, "rvalid"); sc_trace(tf, rready, "rready");
    sc_trace(tf, awaddr, "awaddr"); sc_trace(tf, wdata, "wdata");
    sc_trace(tf, rdata, "rdata");

    sc_start(200, SC_NS);
    sc_close_vcd_trace_file(tf);
    return 0;
}
