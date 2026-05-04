#include "Rotation.hpp"

namespace SO3
{
    LieGroup::LieGroup() 
    {
        mat <<  1, 0, 0, 
                0, 1, 0, 
                0, 0, 1;
    }

    LieGroup::LieGroup(mat3& A) 
    {
        if (isLieGroup(A))
        {
            mat = A;
        }
        else
        {
            throw std::invalid_argument("Matrix is not LieGroup");
        }
    }

    // copy other LieGroup
    LieGroup::LieGroup(LieGroup& other)
    {
        mat = other.mat;
    }

    // init from YPR angles, roll first, pitch second, yaw third
    LieGroup LieGroup::YPR(double dyaw, double dpitch, double droll)
    {
        mat3 B = Yaw(dyaw).GetMatrix()*Pitch(dpitch).GetMatrix()*Roll(droll).GetMatrix();
        return LieGroup(B);
    }

    mat3 LieGroup::GetMatrix() const
    {
        return mat;
    }

    // Rotation matrix for yaw about z axis
    LieGroup LieGroup::Yaw(double alpha)
    {
        mat3 B;
        B << std::cos(alpha), -std::sin(alpha), 0, 
                std::sin(alpha), std::cos(alpha), 0,
                0         , 0         , 1;
        return LieGroup(B);
    }
        
    // Rotation matrix for pitch about y axis
    LieGroup LieGroup::Pitch(double beta)
    {
        mat3 B;
        B << std::cos(beta), 0, std::sin(beta), 
                0,         1,           0,
                -std::sin(beta) , 0, std::cos(beta);
        return LieGroup(B);
    }
        
    LieGroup LieGroup::Roll(double gamma)
    {
        mat3 B;
        B << 1, 0, 0,
                0, std::cos(gamma), -std::sin(gamma),
                0, std::sin(gamma), std::cos(gamma);
        return LieGroup(B);
    }
        

    // return identity element for rotation
    LieGroup LieGroup::Identity()
    {
        return LieGroup();
    }

    // Rodrigues exponential formula, assumes unit vector
    LieGroup LieGroup::Rodrigues(LieAlgebra omega, double theta)
    {
        mat3 r = Identity().GetMatrix() + omega.GetMatrix()*std::sin(theta) + omega.sq()*(1 - std::cos(theta));
        return LieGroup(r);
    }
    // Unit vector case
    LieGroup LieGroup::Rodrigues(LieAlgebra omega)
    {
        return Rodrigues(omega, omega.GetNorm());
    }
    // Non-unit vector case, assume norm is the rotation 
    LieGroup LieGroup::Rodrigues(vec3 omega)
    {
        LieAlgebra omg = LieAlgebra(omega);
        return Rodrigues(omg, omg.GetNorm());
    }
    // Non unit vector case, give explicit rotation
    LieGroup LieGroup::Rodrigues(vec3 omega, double theta)
    {
        LieAlgebra omg = LieAlgebra(omega);
        return Rodrigues(omg, theta);
    }

    // Exponential coordinates version
    LieGroup LieGroup::Rodrigues(ExpCoordinates exp)
    {
        return Rodrigues(exp.GetLieAlgebra());
    }

    LieGroup LieGroup::Transpose()
    {
        mat3 out = mat.transpose();
        return LieGroup(out);
    }

    LieGroup LieGroup::Inverse()
    {
        return Transpose();
    }

    // multiply two rotation matrices
    LieGroup LieGroup::operator*(const LieGroup& other)
    {
        mat3 B = mat * other.mat;
        return LieGroup(B);
    }

    // Rotate a vector
    vec3 LieGroup::operator*(const vec3& other)
    {
        vec3 v = mat * other;
        return v;
    }

    LieGroup LieGroup::operator+(const LieGroup& other)
    {
        mat3 m = mat + other.mat;
        return LieGroup(m);
    }

    // print rotation matrix
    std::ostream& operator<<(std::ostream& out, const LieGroup& A)
    {
        return out << A.mat;
    } 
        
    bool LieGroup::isLieGroup(mat3& A, double PRECISION) // I'd want more precision, but idk how to.
    {
        mat3 identityCheck = A.transpose() * A;
        bool isIdentity = identityCheck.isIdentity(PRECISION);
        bool isPositive = A.determinant() > 0;
        return (isIdentity && isPositive);
    }


    LieAlgebra::LieAlgebra()
    {
        v << 0, 0, 0;
        m = Skew(v);
        t = 0;
    }

    LieAlgebra::LieAlgebra(vec3 u)
    {
        v = u.normalized();
        t = u.norm();
        m = Skew(v);
    }

    LieAlgebra::LieAlgebra(LieAlgebra& other)
    {
        v = other.v;
        t = other.t;
        m = other.m;
    }

    // Get normalized vector
    vec3 LieAlgebra::GetUnitVec()
    {
        return v;
    }

    // get the skew matrix
    skew3 LieAlgebra::GetMatrix()
    {
        return m;
    }

    // return the norm of the original vector
    double LieAlgebra::GetNorm()
    {
        return t;
    }

    // return the square of this so3 
    mat3 LieAlgebra::sq()
    {
        mat3 j = v*t * v.transpose()*t;
        mat3 k = t*t * LieGroup::Identity().GetMatrix();
        mat3 sq = j - k; // need it to be a skew matrix
        return sq;
    }

    // return the cube of this so3
    mat3 LieAlgebra::cube()
    {
        mat3 a = -1*(t*t)*m;
        return a;
    }

    // Skew a vector
    skew3 LieAlgebra::Skew(vec3& u)
    {
        skew3 m;
        m <<    0,  -u(2),  u(1),
                u(2),   0,  -u(0),
                -u(1), u(0), 0;
        return m;
    }

    // Convert skew back to vector
    vec3 LieAlgebra::DeSkew(skew3& w)
    {
        return vec3(w(2,1), w(0,2), w(1,0));
    }

    LieGroup operator*(double constant, LieGroup& other)
    {
        mat3 out = constant * other.mat;
        return LieGroup(out);
    }

    std::ostream& operator<<(std::ostream& out, const LieAlgebra A)
    {
        return out << A.m;
    } 


    ExpCoordinates::ExpCoordinates(vec3 _omega, double _theta) : omega(_omega), theta(_theta) {}

    LieAlgebra ExpCoordinates::GetLieAlgebra()
    {
        return LieAlgebra(omega*theta);
    }
}