#pragma once

#include <cassert>
#include <Eigen/Dense>
#include "prox_L1.h"

namespace MLSparse
{
	using Vector = Eigen::VectorXd;

	/// <summary>
	/// 加速付き近接勾配法 (p.77 アルゴリズム 6.1)
	/// </summary>
	template<class Nabla_L, class Is_converged>
	Vector FISTA(
		double lambda,
		double eta,
		const Vector &w_init,
		Nabla_L &nabla_L,
		Is_converged &is_converged
	)
	{
		assert(lambda >= 0);
		assert(eta > 0);

		Vector z = w_init;
		double s = 1;
		Vector w = w_init, w_pre;
		do
		{
			// w の更新 
			w_pre.swap(w);
			w = prox_L1(lambda, z - eta  * nabla_L(z));
			// z の更新 
			const double s_pre = s;
			s = (1. + sqrt(1. + 4. * s * s)) / 2.;
			z = w + (s_pre - 1) / s * (w - w_pre);
			
		} while (!is_converged(w_pre, w));
		return w;
	}
	
} // namespace MLSparse
