#include "Transformation.hpp"

// remember Points have a 1 at the bottom, and vectors have a 0 at the bottom

namespace SE3
{
    LieGroup::LieGroup()
    {
        Rotation = SO3::LieGroup();
        Translation << 0, 0, 0;
    }

    LieGroup::LieGroup(mat4 mat)
    {
        mat3 a {{mat(0,0), mat(0,1), mat(0,2)}, 
            {mat(1,0), mat(1,1), mat(1,2)}, 
            {mat(2,0), mat(2,1), mat(2,2)}};
        Rotation = SO3::LieGroup(a);
        Translation = vec3(mat(0,3), mat(1,3), mat(2,3));
    }

    LieGroup::LieGroup(SO3::LieGroup rotation, vec3 translation)
    {
        Rotation = rotation;
        Translation = translation;
    }

    LieGroup::LieGroup(LieGroup& other)
    {
        Rotation = other.Rotation;
        Translation = other.Translation;
    }

    mat4 LieGroup::GetMatrix() const
    {
        mat4 out;
        out << Rotation.GetMatrix()(0), Rotation.GetMatrix()(1), Rotation.GetMatrix()(2), Translation(0),  
        Rotation.GetMatrix()(3), Rotation.GetMatrix()(4), Rotation.GetMatrix()(5), Translation(1), 
        Rotation.GetMatrix()(6), Rotation.GetMatrix()(7), Rotation.GetMatrix()(8), Translation(2), 
        0,                         0,                       0,                       1;
        return out;
    }

    LieGroup LieGroup::Identity()
    {
        return LieGroup();
    }
    
    pt3 LieGroup::PointTransform(pt3 target)
    {
        vec4 homoTgt {target(0), target(1), target(2), 1};
        vec4 out = GetMatrix()*homoTgt;
        return out(Eigen::seq(0,2)); // return only the first 3 elements
    }
    
    vec3 LieGroup::VectorTransform(vec3 target)
    {
        vec4 homoTgt {target(0), target(1), target(2), 0};
        vec4 out = GetMatrix()*homoTgt;
        return out(Eigen::seq(0,2)); // return only the first 3 elements
    }

    LieGroup LieGroup::Multiply(const LieGroup& other)
    {
        mat4 out = GetMatrix()*other.GetMatrix();
        return LieGroup(out);
    }

    LieGroup LieGroup::Inverse()
    {
        SO3::LieGroup Rt = Rotation.Inverse();
        vec3 pRt = -1.0*Rt*Translation;
        return LieGroup(Rt, pRt);
    }

    LieGroup LieGroup::operator*(const LieGroup& other)
    {
        return Multiply(other);
    }

    std::ostream& operator<<(std::ostream& out, LieGroup& other)
    {
        return out << other.GetMatrix();
    }

}