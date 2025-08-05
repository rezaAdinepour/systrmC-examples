/* bus_master.h */


#ifndef __BUS_MASTER_H__
#define __BUS_MASTER_H__

#include <systemc.h>

SC_MODULE(BusMaster) 
{
    sc_in<bool> clk;
    sc_out<sc_uint<4> > addr;
    sc_out<sc_uint<8> > data_out;
    sc_in<sc_uint<8> > data_in;
    sc_out<bool> write_en;
    sc_out<bool> read_en;

    void run();

    SC_CTOR(BusMaster);
};

#endif // __BUS_MASTER_H__
