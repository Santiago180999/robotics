#include <OptimizationAlgorithms/Bracketing.hpp>
#include <cmath>
#include <iostream>
float ackley(float x)
{
    float a=20; float b=0.2; float c=2*3.1415;

    return -a*std::exp(-b*std::sqrt(std::pow(x, 2))) - std::exp(std::cos(c*x)) + a + exp(1);
}

float quad(float x)
{
    return std::pow(x, 2);
}

int main()
{
    

    float* out;
    out = Bracketing::BracketMinimum(quad, 20, 0.01, 2.0);
    float a, b;
    a = *out;
    b = *(out + 1);
    std::cout << "[" << a << ", " << b << "]" << std::endl;

    delete[] out;
    return 0;
}