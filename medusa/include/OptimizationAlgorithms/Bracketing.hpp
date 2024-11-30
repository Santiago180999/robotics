#ifndef BRACKETING_HPP
#define BRACKETING_HPP

namespace Bracketing {
    
    /*
    Symbolic version of the Bracket minimum function
    */
    float* BracketMinimum(float (*func)(float), float xinit=0, float step=1e-2, float stepExp=2.0);

    /* 
    Bracket minimum outputs an interval [a, b] where a local minimum exists for a 2D function.
    data2d - a two dimensional array, containing the index and the value of the function
    xinit - the starting index for the algoritm
    step -  the distance from the previous index evaluated, a hyperparameter
    stepExp - the expansion rate of the step 
    */
    float* BracketMinimum(float* data2d, int datalength, float xinit=0, float step=1e-2, float stepExp=2.0);     

}



#endif  