#include <iostream>
#include "Rotation.hpp"

int main()
{
	SO3::LieGroup A = SO3::LieGroup::YPR(0.5, 1, -0.25);
	std::cout << "Lie Group SO3: Rotation matrix corresponding to Y: 0.5 rad, P: 1 rad, R: -0.25 rad " << std::endl;
	std::cout << A << std::endl;

	vec3 v(0, 0.866,0.5);
	SO3::LieAlgebra w(v); // lie algebra
	std::cout << "Lie Algebra SO3: Skew matrix corresponding to vector " << v << std::endl;
	std::cout << w << std::endl;

	double theta = 0.524;
	SO3::LieGroup B = SO3::LieGroup::Rodrigues(w, theta);
	std::cout << "Lie Group SO3: Rodrigues formula for the lie algebra " << std::endl;
    std::cout << B << std::endl;
	return 0;
}
