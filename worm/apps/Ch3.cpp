#include "Transformation.hpp"

int main()
{
    SO3::LieGroup rA = SO3::LieGroup::YPR(0, 0, 0.5);
    vec3 vA {0, 1, 1};
    SE3::LieGroup A(rA, vA);

    std::cout << "The transformation matrix A\n";
    std::cout << A << "\n";

    vec3 vB {0, 0, 3};
    std::cout << "The vector \n" << vB << "\nmodified by A \n";
    std::cout <<A.VectorTransform(vB) << "\n";

    pt3 pB {2, 1, 3};
    std::cout << "The point \n" << pB << "\nmodified by A \n";
    std::cout <<A.PointTransform(pB) << "\n";

    SO3::LieGroup rC = SO3::LieGroup::YPR(0, 0, -0.5);
    vec3 vC {0, 1, 1};
    SE3::LieGroup C(rC, vC);
    SE3::LieGroup D = A*C;
    std::cout << "The transformation matrix A\n";
    std::cout << A << "\nmultiplied by C:\n";
    std::cout << C << "\n A*C: \n" << D << "\n";

    SE3::LieGroup E = A.Inverse();
    std::cout << "Now we inverse the matrix A\n";
    std::cout << E << "\n";
    return 0;
}