/* tb_system.cpp */


#include "tb_system.h"

TB_System::TB_System(sc_module_name name) : sc_module(name), clk("clk", 5, SC_NS) 
{
    m1 = new Master1("Master1");
    m1->clk(clk); m1->req(req1); m1->grant(grant1);
    m1->addr(addr1); m1->data_out(dout1); m1->data_in(din1);
    m1->write_en(we1); m1->read_en(re1);

    m2 = new Master2("Master2");
    m2->clk(clk); m2->req(req2); m2->grant(grant2);
    m2->addr(addr2); m2->data_out(dout2); m2->data_in(din2);
    m2->write_en(we2); m2->read_en(re2);

    arbiter = new BusArbiter("Arbiter");
    arbiter->clk(clk);

    arbiter->req1(req1); arbiter->grant1(grant1);
    arbiter->addr1(addr1); arbiter->data_out1(dout1); arbiter->data_in1(din1);
    arbiter->we1(we1); arbiter->re1(re1);

    arbiter->req2(req2); arbiter->grant2(grant2);
    arbiter->addr2(addr2); arbiter->data_out2(dout2); arbiter->data_in2(din2);
    arbiter->we2(we2); arbiter->re2(re2);

    arbiter->dev_addr(dev_addr); arbiter->dev_data_out(dev_dout);
    arbiter->dev_data_in(dev_din); arbiter->dev_we(dev_we); arbiter->dev_re(dev_re);

    device = new RegDevice("Device");
    device->clk(clk); device->addr(dev_addr); device->data_out(dev_dout);
    device->data_in(dev_din); device->write_en(dev_we); device->read_en(dev_re);

    SC_THREAD(trace);
}

TB_System::~TB_System() 
{
    delete m1; delete m2; delete arbiter; delete device;
}

void TB_System::trace() {
    sc_trace_file* tf = sc_create_vcd_trace_file("bus_waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, clk, "clk");
    sc_trace(tf, req1, "req1"); sc_trace(tf, grant1, "grant1");
    sc_trace(tf, req2, "req2"); sc_trace(tf, grant2, "grant2");
    sc_trace(tf, dev_addr, "dev_addr");
    sc_trace(tf, dev_dout, "dev_data_out");
    sc_trace(tf, dev_din, "dev_data_in");

    wait(100, SC_NS);
    sc_close_vcd_trace_file(tf);
}
