/* tb_memmap.cpp */


#include "tb_memmap.h"

TB_MemMap::TB_MemMap(sc_module_name name) : sc_module(name), clk("clk", 5, SC_NS) 
{
    master = new BusMaster("master");
    master->clk(clk);
    master->addr(sig_addr);
    master->data_out(sig_data_out);
    master->data_in(sig_data_in);
    master->write_en(sig_write_en);
    master->read_en(sig_read_en);

    device = new RegDevice("device");
    device->clk(clk);
    device->addr(sig_addr);
    device->data_out(sig_data_out);
    device->data_in(sig_data_in);
    device->write_en(sig_write_en);
    device->read_en(sig_read_en);

    SC_THREAD(trace);
}

TB_MemMap::~TB_MemMap() 
{
    delete master;
    delete device;
}

void TB_MemMap::trace() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, clk, "CLK");
    sc_trace(tf, sig_addr, "ADDR");
    sc_trace(tf, sig_data_out, "DATA_OUT");
    sc_trace(tf, sig_data_in, "DATA_IN");
    sc_trace(tf, sig_write_en, "WRITE_EN");
    sc_trace(tf, sig_read_en, "READ_EN");

    wait(100, SC_NS);  // simulation time

    sc_close_vcd_trace_file(tf);
}
