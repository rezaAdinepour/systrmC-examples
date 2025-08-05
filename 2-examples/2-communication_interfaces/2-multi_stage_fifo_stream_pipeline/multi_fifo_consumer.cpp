/* multi_fifo_consumer.cpp */


#include "multi_fifo_consumer.h"

MultiFifoConsumer::MultiFifoConsumer(sc_module_name name) : sc_module(name)
{
    SC_THREAD(consume);
    sensitive << clk.pos();
}

void MultiFifoConsumer::consume()
{
    while (true)
    {
        wait();
        sc_uint<8> val = in.read();
        data_out.write(val);  // For VCD
        std::cout << sc_time_stamp() << " - Consumer received: " << val << std::endl;
    }
}
