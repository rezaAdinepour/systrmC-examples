/* tb_comparator.cpp */

#include "tb_comparator.h"

TB_Comparator::TB_Comparator(sc_module_name name) : sc_module(name) 
{
    comp = new Comparator("comparator");
    comp->a(sig_a);
    comp->b(sig_b);
    comp->eq(sig_eq);
    comp->gt(sig_gt);
    comp->lt(sig_lt);

    SC_THREAD(stimulus);
}

TB_Comparator::~TB_Comparator() 
{
    delete comp;
}

void TB_Comparator::stimulus() 
{
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS);

    sc_trace(tf, sig_a, "A");
    sc_trace(tf, sig_b, "B");
    sc_trace(tf, sig_eq, "EQ");
    sc_trace(tf, sig_gt, "GT");
    sc_trace(tf, sig_lt, "LT");

    // Test case 1: A == B
    sig_a.write(2); sig_b.write(2);
    wait(1, SC_NS);
    cout << "A=2, B=2 → EQ=" << sig_eq.read() << " GT=" << sig_gt.read() << " LT=" << sig_lt.read() << endl;

    // Test case 2: A > B
    sig_a.write(3); sig_b.write(1);
    wait(1, SC_NS);
    cout << "A=3, B=1 → EQ=" << sig_eq.read() << " GT=" << sig_gt.read() << " LT=" << sig_lt.read() << endl;

    // Test case 3: A < B
    sig_a.write(0); sig_b.write(1);
    wait(1, SC_NS);
    cout << "A=0, B=1 → EQ=" << sig_eq.read() << " GT=" << sig_gt.read() << " LT=" << sig_lt.read() << endl;

    sc_close_vcd_trace_file(tf);
    sc_stop();
}
