
#include    <iostream>
#include    <systemc.h>
#include    <cmath>
#include    "cosinePowerTwo.h"

#define PI 3.1415



template <int NumClk, int N>
void CosinePwrTwo<NumClk, N> :: operation() {
    float rad, tmp;
    
    while(true){
        float term = 1;
        float cosPwr2 = 1;        

        if(rst == '1') {
            ready = SC_LOGIC_0;
            RBus = 0;
        } else if((clk == '1') && (clk->event())) {
            if(go == '1') {
                ready = SC_LOGIC_0;
                RBus = 0; 

                XBus_reg = XBus->read();
                
                wait(clk->posedge_event());
                rad = (double)(XBus_reg.read() * PI)/180.0;
                tmp = 4 * rad * rad;

                for(int i = 1; i < N; i++) {
                    term = term * ((i % 2) ? -1 : 1) * (tmp / float((2 * i) * (2 * i -1)));
                    cosPwr2 += 0.5 * term;
                }

                for(int i = 0; i < NumClk - 1; i++)
                    wait(clk->posedge_event());

                ready = SC_LOGIC_1;
                RBus = cosPwr2;
            }
        }
        wait();
    }
}

template <int NumClk, int N>
int CosinePwrTwo<NumClk, N> :: factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;

}
