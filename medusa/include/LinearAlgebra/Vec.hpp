#ifndef VEC_HPP
#define VEC_HPP

#include <cmath>
#include <vector>

using namespace std;


// id like to make a class that both point and direction can inherit from
class Vec
{
    public: 
    Vec() = default;
    
    // constructor with only dimension
    Vec(size_t dim) : dimension(dim) {}

    // constructor with dimension and vector
    Vec(size_t dim, vector<float> vector) : dimension(dim) {vec = vector;}

    // copy constructor
    Vec(const Vec& other) : dimension(other.dimension) {vec = other.vec;}

    // copy assignment operator
    Vec& operator= (const Vec& rhs);

    private:
    vector<float> vec;
    size_t dimension;
};


Vec& Vec::operator=(const Vec& rhs)
{
    if (this != &rhs)
    {
        vec = rhs.vec;
        dimension = rhs.dimension;
    }
    return *this;
}

#endif