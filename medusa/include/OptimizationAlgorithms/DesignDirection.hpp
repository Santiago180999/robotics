#ifndef DESIGNDIRECTION_HPP
#define DESIGNDIRECTION_HPP

#include <initializer_list>
#include <iostream>
using namespace std;

class DesignDirection
{
    public:

    DesignDirection() = default;
    DesignDirection(const DesignDirection& other) : dimension(other.dimension) {vec = other.vec;}
    DesignDirection(size_t dim) : dimension(dim) {}
    DesignDirection(size_t dim, vector<float> vector) : dimension(dim) {vec = vector;}

    DesignDirection& operator= (const initializer_list<float> list)
    {
        if (list.size() == dimension)
        {
            vec.assign(list);
        } 
        else
        {
            cout << "new design direction doesnt match the expected size \n"; 
        }
        return *this;
    } 

    DesignDirection& operator= (const vector<float> list)
    {
        for (int i = 0; i < dimension; i++)
        {
            vec[i] = list[i];
        }
        return *this;
    }

    DesignDirection& operator= (const DesignDirection&& other)
    {
        if (this != &other)
        {
            vec = other.vec;
            dimension = other.dimension;
        }
        return *this;
    }
    
    // return the i-th value of the design point
    float operator[] (int i) const
    {
        return vec[i];
    }

    // dot product of two directions
    float dot(const DesignDirection& rhs)
    {
        int sum = 0;
        DesignDirection& lhs = *this;
        for (int i = 0; i < dimension; i++)
        {
            sum += lhs[i]*rhs[i];
        }
        return sum;
    }

    void normalize()
    {
        float len = length();
        vector<float> current = vec;
        for (int i = 0; i < dimension; i++)
        {
            vec[i] = (1/len)*current[i];
        }
    }

    // return the dimension of the design point
    size_t dim() const
    {
        return dimension;
    }

    float length_squared() const
    {
        float sum;
        for (int i = 0; i < dimension; i++)
        {
            sum += vec[i]*vec[i];
        }
        return sum;
    }

    float length() const
    {
        return sqrt(length_squared());
    }

    private:
    vector<float> vec;
    size_t dimension;

};

// multiplication by a scalar
DesignDirection operator*(float scalar, const DesignDirection& rhs)
{
    size_t dim = rhs.dim();
    vector<float> outvec(dim);
    for (int i = 0; i < dim; i++)
    {
        outvec[i] = scalar*rhs[i];
    }
    return DesignDirection(dim, outvec);
}

#endif