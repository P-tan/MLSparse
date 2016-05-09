#include "stdafx.h"
#include "CppUnitTest.h"

#include "MLSparse/prox_L1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace MLSparse;

namespace MLSparseTest
{		

	TEST_CLASS(prox_L1Test)
	{
	public:
		
		TEST_METHOD(Testprox_L1)
		{
			Vector in{3};
			in << -1, 2, 3;
			const Vector result = prox_L1(2, in);
			Vector expected{3};
			expected << 0, 0, 1;
			Assert::IsTrue(expected == result);
		}

	};
}