#include    <iostream>
#include    "cosinePowerTwoTB.h"


int sc_main(int args, char *argv[])
{
    CosinePwrTwoTB *TOP = new CosinePwrTwoTB("Cosine_Power_Two_Test_Bench Instance");
    
    sc_trace_file *VCDFile;
    VCDFile = sc_create_vcd_trace_file("cosinePowerTwo");
    sc_trace(VCDFile, TOP->XBus, "XBus");
    sc_trace(VCDFile, TOP->clk, "clk");
    sc_trace(VCDFile, TOP->rst, "rst");
    sc_trace(VCDFile, TOP->go, "go");
    sc_trace(VCDFile, TOP->ready, "ready");
    sc_trace(VCDFile, TOP->RBus, "RBus");
    
    sc_start(2000, SC_NS);
    return 0;
}