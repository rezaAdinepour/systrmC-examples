/* sequence_detector.cpp */


#include "sequence_detector.h"

SequenceDetector::SequenceDetector(sc_module_name name) : sc_module(name), current_state(S0) 
{
    SC_METHOD(process);
    sensitive << clk.pos();
}

void SequenceDetector::process() 
{
    if (reset.read()) 
    {
        current_state = S0;
        detected.write(false);
        return;
    }

    // Moore FSM logic
    switch (current_state) 
    {
        case S0:
            detected.write(false);
            current_state = din.read() ? S1 : S0;
            break;
        case S1:
            detected.write(false);
            current_state = din.read() ? S1 : S2;
            break;
        case S2:
            detected.write(false);
            current_state = din.read() ? S3 : S0;
            break;
        case S3:
            current_state = din.read() ? S1 : S4;
            detected.write(din.read()); // 1 if input is '1' at this state → sequence matched
            break;
        case S4:
            detected.write(false);
            current_state = din.read() ? S1 : S0;
            break;
    }
}
