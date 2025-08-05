/* tb_multi_fifo.cpp */


#include "tb_multi_fifo.h"

TB_MultiFifo::TB_MultiFifo(sc_module_name name)
    : sc_module(name), clk("clk", 5, SC_NS),
      fifo1(4), fifo2(4), fifo3(4)
{
    producer = new MultiFifoProducer("producer");
    producer->clk(clk);
    producer->out(fifo1);

    stage1 = new Stage1("stage1");
    stage1->clk(clk);
    stage1->in(fifo1);
    stage1->out(fifo2);

    stage2 = new Stage2("stage2");
    stage2->clk(clk);
    stage2->in(fifo2);
    stage2->out(fifo3);

    consumer = new MultiFifoConsumer("consumer");
    consumer->clk(clk);
    consumer->in(fifo3);
    consumer->data_out(consumer_data);

    SC_THREAD(trace);
}

TB_MultiFifo::~TB_MultiFifo() 
{
    delete producer;
    delete stage1;
    delete stage2;
    delete consumer;
}

void TB_MultiFifo::trace() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, clk, "CLK");
    sc_trace(tf, consumer_data, "FINAL_OUTPUT");

    wait(100, SC_NS);  // simulation time

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
