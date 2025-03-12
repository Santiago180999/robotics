#ifndef DESIGNPOINT_HPP
#define DESIGNPOINT_HPP

#include <vector>
#include <initializer_list>
#include "DesignDirection.hpp"

using namespace std;

class DesignPoint
{
    public:

    DesignPoint() = default;
    DesignPoint(const DesignPoint& other) : dimension(other.dimension) {point = other.point;}
    DesignPoint(size_t dim) : dimension(dim) {}
    DesignPoint(size_t dim, vector<float> vector) : dimension(dim) {point = vector;}

    DesignPoint& operator= (const initializer_list<float> list)
    {
        if (list.size() == dimension)
        {
            point.assign(list);
        } 
        else
        {
            cout << "new design direction doesnt match the expected size \n"; 
        }
        return *this;
    } 
    
    // return the i-th value of the design point
    float operator[] (int i) const
    {
        return point[i];
    }

    DesignPoint& operator= (const DesignPoint&& other)
    {
        if (this != &other)
        {
            point = other.point;
            dimension = other.dimension;
        }
        return *this;
    }

    // return the dimension of the design point
    int dim() const
    {
        return dimension;
    }

   

    private:
    vector<float> point;
    size_t dimension;

};

DesignPoint operator+ (const DesignPoint& x, const DesignDirection& d) // TODO: need to definethis 
{
    size_t dim = d.dim();
    vector<float> outvec(dim);
    for (int i = 0; i < x.dim(); i++)
    {
        outvec[i] = x[i] + d[i];       
    } 

    return DesignPoint(dim, outvec);
}

#endif