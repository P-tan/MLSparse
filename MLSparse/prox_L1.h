#pragma once

#include <cassert>
#include <Eigen/Dense>

inline Eigen::VectorXd prox_L1(double lambda, const Eigen::VectorXd &y)
{
	assert(lambda >= 0);
	return y.unaryExpr([lambda](double d) {
		if (d < -lambda) { return d + lambda; }
		if (d > lambda) { return d - lambda; }
		return 0.;
	});
}
