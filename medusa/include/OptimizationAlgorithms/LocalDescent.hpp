#ifndef LOCALDESCENT_HPP
#define LOCALDESCENT_HPP

#include "TestFunctions.hpp"
#include "DesignDirection.hpp"
/*
If d is a valid descent direction, then there must exist a sufficiently small step
size that satisfies the sufficient decrease condition.

fn - objective function, with gradient defined
x - design point
d - design direction
alpha - step size
p - step size reduction factor
beta - first wolfe condition parameter
*/
float backtrackingLineSearch(TestFunction fn, DesignPoint x, DesignDirection d, float alpha, float p=0.5, float beta=1e-4)
{
    int counter = 0;
    float y, y_next, y_test;
    y = fn(x);
    DesignDirection g = fn.grad(x); 
    std::cout << "Backtracking Line Search: \n";
    y_next = fn(x + alpha*d);
    y_test = y + beta*alpha*(g.dot(d));
    while (y_next > y_test) 
    {
        alpha *= p;
        y_next = fn(x + alpha*d);
        y_test = y + beta*alpha*(g.dot(d));
        std::cout<< counter <<": " << alpha << "\n";
        counter++;
    }
    return alpha; 
}

#endif