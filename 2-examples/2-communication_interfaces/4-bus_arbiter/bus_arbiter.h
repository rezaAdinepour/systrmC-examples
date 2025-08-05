/* bus_arbiter.h */


#ifndef __BUS_ARBITER_H__
#define __BUS_ARBITER_H__

#include <systemc.h>

SC_MODULE(BusArbiter) 
{
    // Clock
    sc_in<bool> clk;

    // Master1
    sc_in<bool> req1;
    sc_out<bool> grant1;
    sc_in<sc_uint<4> > addr1;
    sc_in<sc_uint<8> > data_out1;
    sc_out<sc_uint<8> > data_in1;
    sc_in<bool> we1, re1;

    // Master2
    sc_in<bool> req2;
    sc_out<bool> grant2;
    sc_in<sc_uint<4> > addr2;
    sc_in<sc_uint<8> > data_out2;
    sc_out<sc_uint<8> > data_in2;
    sc_in<bool> we2, re2;

    // Shared Device
    sc_out<sc_uint<4> > dev_addr;
    sc_out<sc_uint<8> > dev_data_out;
    sc_in<sc_uint<8> > dev_data_in;
    sc_out<bool> dev_we, dev_re;

    void arbitrate();

    SC_CTOR(BusArbiter);
};

#endif // __BUS_ARBITER_H__
