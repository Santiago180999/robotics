#ifndef FUNCLIB
#define FUNCLIB

#include <cmath>
#include <vector>
#include <functional>
#include "DesignPoint.hpp"
#include "DesignDirection.hpp"

using namespace std;

// function return value
struct RetVal
{
    RetVal(size_t dimension) : g(dimension){};

    float f;
    DesignDirection g;
    vector<float> h;
};

// used to generically call the test function
class TestFunction
{
    public:
    // function with just the function defined
    TestFunction(RetVal(*objFn)(DesignPoint, vector<float>), vector<float> params)
    {
        objectiveFn = objFn;
        parameters = params;
    }

    // return the value of the function at the design point
    RetVal eval(DesignPoint x)
    {
        RetVal out = objectiveFn(x, parameters);
        return out;
    }


    // return the value of the function at the design point
    float func(DesignPoint x)
    {
        return eval(x).f;
    }
    
    float operator() (DesignPoint x)
    {
        return func(x);
    }

    // for now, user will have to understand how to access and interpret the gradient
    DesignDirection grad(DesignPoint x)
    {
        return eval(x).g;
    }
    

    private:
    function<RetVal(DesignPoint, vector<float>)> objectiveFn;
    vector<float> parameters;

};

/*
    Defined for any number of dimensions. One global minimum, many local minima.
    Suggested params values: params[0]=20 params[1]=0.2 params[2]=2*3.1415
*/
RetVal ackley(DesignPoint x, std::vector<float> params)
{
    float a=params[0];
    float b=params[1];
    float c=params[2];
    int n = x.dim();
    float sum1, sum2;
    for (int i = 0; i < n; i++)
    {
        sum1 += pow(x[i], 2);
        sum2 += cos(c*x[i]);
    }
    float val = -a*exp(-b*sqrt(sum1)) - (sum2) + a + exp(1);

    RetVal out(n);
    out.f = val;
   
    return out;
}


/*
    Two dimensional, It has a global minimum at [a, a^2] inside a long, curved valley.
    Suggested params values: params[0]=1 params[1]=5
*/
RetVal rosenbrock(DesignPoint x, std::vector<float> params)
{
    float a=params[0];
    float b=params[1];

    // function
    float val = pow(a - x[0],2) + b*pow(x[1] - pow(x[0],2), 2);

    // gradient
    float partialx1 = -2*(a - x[0]) - 4*b*(-pow(x[0],3) + x[1]*x[0]);
    float partialx2 = 2*b*(x[1] - pow(x[0], 2));

    RetVal out(x.dim());
    out.f = val;
    out.g = {partialx1, partialx2};

    return out;
}

#endif
