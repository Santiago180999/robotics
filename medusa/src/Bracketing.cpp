#include "OptimizationAlgorithms/Bracketing.hpp"
#include <algorithm>
#include <utility>

// search in a 1D array for a value; return the closest value if not found
int search(float* array, int length, float val2find)
{
    int pos = 0;
    int limit = std::min(length, 1);
    while (limit < length && array[limit] < val2find) // bounds the search so that the next loop doesnt iterate over all the value in the array
    {
        pos = limit + 1;
        limit = std::min(length, limit*2+1);
    }
    while (pos < limit) // in the bounded array search until the position reaches (equals) the limit. 
    {
        int testPos = pos + ((limit-pos) >> 1); // pos + (limit - pos)/2 

        if (array[testPos] < val2find)
        {
            pos = testPos + 1;
        }
        else
        {
            limit = testPos;
        }
    }
    return (pos < length && array[pos] == val2find ? pos : -1);
}

// column can only be 0 or 1
float* copyArrayColumn(float* inArray, int length, int column=0)
{
    float* outArray = new float[length];
    for (int i = 0; i < length; i++)
    {
        outArray[i] = *(inArray + i) + column;
    }   
    delete[] outArray;
    return outArray;
}

float* Bracketing::BracketMinimum(float (*func)(float), float xinit, float step, float stepExp)
{
    float a, ya, b, yb, c, yc;
    float* out = new float[2];
    a = xinit;
    ya = func(a);

    b = a + step;
    yb = func(b);

    if (yb > ya)
    {
        std::swap(a, b);
        std::swap(ya, yb);
        step = -step;
    }
    while (true)
    {
        c = b + step;
        yc = func(c);
        if (yc > yb)
        {
            out[0] = a < c ? a : c;
            out[1] = a < c ? c : a;
            return out;
        }
        std::swap(a, b);
        std::swap(ya, yb);
        std::swap(b, c);
        std::swap(yb, yc);

        step *= stepExp;
    }
}

float* Bracketing::BracketMinimum(float* data2d, int datalength, float xinit, float step, float stepExp) 
{
    // note: could try to make the float and length a structure to pass in to other algorithms 
    // assuming array is 2 columns, by whatever data length is
    // verify if input needs to be interpolated
    // Note: since the data is not continous, the step size could be adjusted, and the algorithm may not need to interpolate
    int pos;
    float a, ya, b, yb, c, yc;
    float* index;
    index = copyArrayColumn(data2d, datalength, 0);
    
    // need to find... thus need the following algorithms: find, interpolate
    // https://www.geeksforgeeks.org/pointer-array-array-pointer/
    
    // need to convert the xinit value to the index of the array  
    a = xinit;
    pos = search(index, datalength, a);
    ya = *(data2d + pos) + 1;

    return indexArr;
    }