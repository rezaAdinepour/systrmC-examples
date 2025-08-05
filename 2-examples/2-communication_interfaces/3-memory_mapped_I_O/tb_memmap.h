/* tb_memmap.h */


#ifndef __TB_MEMMAP_H__
#define __TB_MEMMAP_H__

#include <systemc.h>
#include "bus_master.h"
#include "reg_device.h"

SC_MODULE(TB_MemMap) 
{
    sc_clock clk;

    sc_signal<sc_uint<4> > sig_addr;
    sc_signal<sc_uint<8> > sig_data_out;
    sc_signal<sc_uint<8> > sig_data_in;
    sc_signal<bool> sig_write_en, sig_read_en;

    BusMaster* master;
    RegDevice* device;

    void trace();

    SC_CTOR(TB_MemMap);
    ~TB_MemMap();
};

#endif // __TB_MEMMAP_H__
