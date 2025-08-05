/* main.cpp */


#include "tb_handshake.h"

int sc_main(int argc, char* argv[]) 
{
    TB_Handshake tb("tb_handshake");
    sc_start(100, SC_NS);  // run for a fixed time
    return 0;
}
