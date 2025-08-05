/* tb_handshake.cpp */


#include "tb_handshake.h"

TB_Handshake::TB_Handshake(sc_module_name name) : sc_module(name), clk("clk", 5, SC_NS) 
{
    producer = new Producer("producer");
    producer->clk(clk);
    producer->ready(sig_ready);
    producer->valid(sig_valid);
    producer->data(sig_data);

    consumer = new Consumer("consumer");
    consumer->clk(clk);
    consumer->valid(sig_valid);
    consumer->data(sig_data);
    consumer->ready(sig_ready);
}

TB_Handshake::~TB_Handshake() 
{
    delete producer;
    delete consumer;
}
