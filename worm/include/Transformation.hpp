#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include "Dependencies.hpp"
#include "Rotation.hpp"

namespace SE3
{
    class LieGroup
    {
        public:
        // empty default constructor, gives identity rotation and zero vector
        LieGroup();
        
        // initialize from a 4x4 matrix
        LieGroup(mat4 mat);

        // intialize from a given Rotation and Translatoin
        LieGroup(SO3::LieGroup rotation, vec3 translation);

        // initialize from another SE3::LieGroup
        LieGroup(LieGroup& other);

        // Get the 4x4 homogeneous matrix representation
        mat4 GetMatrix() const;

        // Return an identity matrix
        static LieGroup Identity();

        // Apply transformation to a point
        pt3 PointTransform(pt3 target);
        
        // Apply transformation to a vector
        vec3 VectorTransform(vec3 target);
        
        // Matrix multiplicatoion
        LieGroup Multiply(const LieGroup& other);

        // Inverse the lie group
        LieGroup Inverse();

        // multiply two SE3 Lie Groups
        LieGroup operator*(const LieGroup& other);

        // since point and vector have different funcitions to apply the transform, i dont think we can use operator override

        // print the matrix form
        friend std::ostream& operator<<(std::ostream& out, LieGroup& other);


        private:
        SO3::LieGroup Rotation;
        vec3 Translation;

    };

}


#endif