#ifndef RTWEEKEND_H
#define RTWEEKEND_H


#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

// C++ std usings
using std::make_shared;
using std::shared_ptr;

//constants
const double inf = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//utility funciotns
inline double deg2rad(double degrees) 
{
    return degrees * pi / 180.0;
}

// return a random real in [0, 1)
inline double random_double()
{
    return std::rand() / (RAND_MAX + 1.0);
}

// return random real in [min, max)
inline double random_double(double min, double max)
{
    return min + (max-min)*random_double();
}

// common headers
#include "colour.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include "interval.hpp"
#endif