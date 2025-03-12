#include <TestFunctions.hpp>
#include <DesignPoint.hpp>
#include <DesignDirection.hpp>
#include <LocalDescent.hpp>
#include <iostream>
#include <Vec.hpp>
int main()
{
    std::vector<float> params = {1, 5};
    int k_max = 20;
    TestFunction f(&rosenbrock, params);

    DesignPoint x(2);
    x = {-1.75, -1.75};
    float alpha = 0;
    float alpha_max = 6.0;
    for (int i = 0; i<k_max; i++)
    {
        alpha = alpha_max;
        DesignDirection d = -1*f.grad(x);
        d.normalize();
        float out = backtrackingLineSearch(f, x, d, alpha);
        std::cout << "alpha is: " << out << "\n";    
        x = x + out*d;
    }
    std::cout << "final design point is: " << " [" << x[0] << ", " << x[1] << "]\n";
    std::cout << "with value: " << f(x) << "\n";
    return 0;
}