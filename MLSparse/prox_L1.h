#pragma once

#include <cassert>
#include "Vector.h"

namespace MLSparse
{
	
inline Vector prox_L1(double lambda, const Vector &y)
{
	assert(lambda >= 0);
	return y.unaryExpr([lambda](double d) {
		if (d < -lambda) { return d + lambda; }
		if (d > lambda) { return d - lambda; }
		return 0.;
	});
}

} // namespace MLSparse
