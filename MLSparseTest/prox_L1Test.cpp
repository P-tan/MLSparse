#include "stdafx.h"
#include "CppUnitTest.h"

#include "MLSparse/prox_L1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Eigen;

namespace MLSparseTest
{		

	TEST_CLASS(prox_L1Test)
	{
	public:
		
		TEST_METHOD(Testprox_L1)
		{
			VectorXd in{3};
			in << -1, 2, 3;
			const VectorXd result = prox_L1(2, in);
			VectorXd expected{3};
			expected << 0, 0, 1;
			Assert::IsTrue(expected == result);
		}

	};
}