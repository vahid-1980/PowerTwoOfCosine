#include "cosinePowerTwoTB.h"

void CosinePwrTwoTB::resetting()
{
    while(true){
        wait(12, SC_NS);
        rst = SC_LOGIC_0;
        wait(12, SC_NS);
        rst = SC_LOGIC_1;
        wait(20, SC_NS);
        rst = SC_LOGIC_0;
        wait();
    }
}

void CosinePwrTwoTB::clocking()
{
    while(true){
        wait(10, SC_NS);
        clk = SC_LOGIC_0;
        wait(10, SC_NS);
        clk = SC_LOGIC_1;
    }
}


void CosinePwrTwoTB::inGenerating()
{
    while(true){
        XBus = 0;
        go = SC_LOGIC_0;
        wait(50, SC_NS);

        XBus = 2;
        go = SC_LOGIC_1;
        wait(50, SC_NS);
        go = SC_LOGIC_0;

        wait(200, SC_NS);

        XBus = 2.5;
        go = SC_LOGIC_1;
        wait(50, SC_NS);
        go = SC_LOGIC_0;

        wait(200, SC_NS);
 
        XBus = 3;
        go = SC_LOGIC_1;
        wait(60, SC_NS);
        go = SC_LOGIC_0;
     
        wait();
    }
}

void CosinePwrTwoTB::displaying()
{
    while(true){
        if(ready == '1')
            cout << " cos^2" << "( " << XBus << " ) = " << RBus << " - Time : " << sc_time_stamp() << endl; 
        wait();
    }
}



