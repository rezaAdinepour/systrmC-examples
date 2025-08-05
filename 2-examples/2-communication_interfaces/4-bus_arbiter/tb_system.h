/* tb_system.h */


#ifndef __TB_SYSTEM_H__
#define __TB_SYSTEM_H__

#include <systemc.h>
#include "master1.h"
#include "master2.h"
#include "bus_arbiter.h"
#include "reg_device.h"

SC_MODULE(TB_System) 
{
    sc_clock clk;

    // Signals: M1
    sc_signal<bool> req1, grant1, we1, re1;
    sc_signal<sc_uint<4> > addr1;
    sc_signal<sc_uint<8> > dout1, din1;

    // Signals: M2
    sc_signal<bool> req2, grant2, we2, re2;
    sc_signal<sc_uint<4> > addr2;
    sc_signal<sc_uint<8> > dout2, din2;

    // Bus <-> Device
    sc_signal<sc_uint<4> > dev_addr;
    sc_signal<sc_uint<8> > dev_dout, dev_din;
    sc_signal<bool> dev_we, dev_re;

    Master1* m1;
    Master2* m2;
    BusArbiter* arbiter;
    RegDevice* device;

    void trace();

    SC_CTOR(TB_System);
    ~TB_System();
};

#endif // __TB_SYSTEM_H__
