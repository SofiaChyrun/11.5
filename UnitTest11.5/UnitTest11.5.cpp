#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab11.5/ChyrunSofialab11.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest115
{
	TEST_CLASS(UnitTest115)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t, x;
			x=9;
			t = NN(x);
			Assert::AreEqual(t, 10);
		}
	};
}
