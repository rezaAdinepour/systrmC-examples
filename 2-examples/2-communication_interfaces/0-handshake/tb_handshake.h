/* tb_handshake.h */


#ifndef __TB_HANDSHAKE_H__
#define __TB_HANDSHAKE_H__

#include <systemc.h>
#include "producer.h"
#include "consumer.h"

SC_MODULE(TB_Handshake) 
{
    sc_clock clk;
    sc_signal<bool> sig_valid, sig_ready;
    sc_signal<sc_uint<8> > sig_data;

    Producer* producer;
    Consumer* consumer;

    SC_CTOR(TB_Handshake);
    ~TB_Handshake();
};

#endif // __TB_HANDSHAKE_H__
