/* bus_arbiter.cpp */


#include "bus_arbiter.h"

BusArbiter::BusArbiter(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(arbitrate);
    sensitive << clk.pos();
}

void BusArbiter::arbitrate() 
{
    if (req1.read()) 
    {
        grant1.write(true);
        grant2.write(false);

        dev_addr.write(addr1.read());
        dev_data_out.write(data_out1.read());
        dev_we.write(we1.read());
        dev_re.write(re1.read());
        data_in1.write(dev_data_in.read());

    } 
    else if (req2.read()) 
    {
        grant1.write(false);
        grant2.write(true);

        dev_addr.write(addr2.read());
        dev_data_out.write(data_out2.read());
        dev_we.write(we2.read());
        dev_re.write(re2.read());
        data_in2.write(dev_data_in.read());

    } 
    else 
    {
        grant1.write(false);
        grant2.write(false);
        dev_we.write(false);
        dev_re.write(false);
    }
}
