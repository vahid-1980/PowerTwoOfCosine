#ifndef CPT_H
#define CPT_H

#define PI 3.1415

#include    <iostream>
#include    <systemc.h>

template <int NumClk, int N>
SC_MODULE(CosinePwrTwo) 
{
   sc_in<float> XBus;
   sc_in<sc_logic> clk;
   sc_in<sc_logic> rst;
   sc_in<sc_logic> go;

   sc_out<float> RBus;
   sc_out<sc_logic> ready;

   sc_signal<float> XBus_reg;


   SC_CTOR(CosinePwrTwo) {
       SC_THREAD(operation)
            sensitive << clk << rst;
   } 

   void operation();
   int factorial(int);
};


#endif