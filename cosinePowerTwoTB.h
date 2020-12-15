#ifndef CPTTB_H
#define CPTTB_H

#include    "cosinePowerTwo.h"
// As we're ganna instanciate a template class, inorder to avoid linker error I had to include this.
// If any one knows a better way please share. 
#include    "cosinePowerTwo.cpp"

SC_MODULE(CosinePwrTwoTB)
{
    sc_signal<sc_logic> clk, rst, go, ready;
    sc_signal<float> XBus, RBus;

    CosinePwrTwo<10, 10> *cos2;

    SC_CTOR(CosinePwrTwoTB)
    {
        cos2 = new CosinePwrTwo<10, 10> ("cos^2_Interface");
        (*cos2)(XBus, clk, rst, go, RBus, ready);

        SC_THREAD(resetting);
        SC_THREAD(clocking);
        SC_THREAD(inGenerating);
        SC_THREAD(displaying);
            sensitive << ready;
    }
        void resetting();
        void clocking();
        void inGenerating();
        void displaying();
};

#endif