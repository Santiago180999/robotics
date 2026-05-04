#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "Dependencies.hpp"

namespace SO3
{
    class LieAlgebra;
    struct ExpCoordinates;

    class LieGroup
    {
        public:
        // default constructor, identity matrix
        LieGroup(); 

        // construct from matrix
        LieGroup(mat3& A);
        
        // copy other LieGroup
        LieGroup(LieGroup& other);

        // init from YPR angles, roll first, pitch second, yaw third
        static LieGroup YPR(double dyaw, double dpitch, double droll);

        mat3 GetMatrix() const;

        // LieGroup matrix for yaw about z axis
        static LieGroup Yaw(double alpha);

        // LieGroup matrix for pitch about y axis
        static LieGroup Pitch(double beta);

        // LieGroup matrix for roll about x axis
        static LieGroup Roll(double gamma);

        // return identity element for rotation
        static LieGroup Identity();

        // Rodrigues exponential formula, assumes unit vector
        static LieGroup Rodrigues(LieAlgebra omega, double theta);
        
        // Unit vector case
        static LieGroup Rodrigues(LieAlgebra omega);

        // Non-unit vector case, assume norm is the rotation 
        static LieGroup Rodrigues(vec3 omega);

        // Non unit vector case, give explicit rotation
        static LieGroup Rodrigues(vec3 omega, double theta);

        // Exponential coordinates version
        static LieGroup Rodrigues(ExpCoordinates exp);

        // Transpose the rotation matrix
        LieGroup Transpose();

        // Inverse the rotation matrix, equal to transpose
        LieGroup Inverse();

        // multiply two rotation matrices
        LieGroup operator*(const LieGroup& other);
        
        // Rotate a vector
        vec3 operator*(const vec3& other);

        // add two rotation matrices
        LieGroup operator+(const LieGroup& other);

        friend LieGroup operator*(double constant, LieGroup& other);

        // print rotation matrix
        friend std::ostream& operator<<(std::ostream& out, const LieGroup& A);


        private:
        bool isLieGroup(mat3& A, double PRECISION = 1e-4); // I'd want more precision, but idk how to.

        mat3 mat;

        // maybe need to include the exp coordinates, and redo the implementation to not be so dependent on mat. 
    };

    class LieAlgebra
    {
        public:
        LieAlgebra();

        LieAlgebra(vec3 u);

        LieAlgebra(LieAlgebra& other);

        // Get normalized vector
        vec3 GetUnitVec();

        // get the skew matrix
        skew3 GetMatrix();

        // return the norm of the original vector
        double GetNorm();

        // return the square of this so3 
        mat3 sq();

        // return the cube of this so3
        mat3 cube();

        // print rotation matrix
        friend std::ostream& operator<<(std::ostream& out, const LieAlgebra A);

        private:
        // Skew a vector
        static skew3 Skew(vec3& u);
        // Convert skew back to vector
        static vec3 DeSkew(skew3& w);

        vec3 v; // normalized of original vector
        skew3 m; // skew version
        double t; // norm of original vector
    };

    struct ExpCoordinates
    {
        // Exponential coordinates for an arbitrary rotation
        ExpCoordinates(vec3 _omega, double _theta);

        // Get the lie algebra of this rotation
        LieAlgebra GetLieAlgebra();

        vec3 omega;
        double theta;
    };
}
#endif