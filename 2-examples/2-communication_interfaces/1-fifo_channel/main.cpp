/* main.cpp */


#include "tb_fifo.h"

int sc_main(int argc, char* argv[]) 
{
    TB_Fifo tb("tb_fifo");
    sc_start(100, SC_NS);  // run simulation
    return 0;
}
