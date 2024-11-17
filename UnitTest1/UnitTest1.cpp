#include <iostream>
#include <sstream>
#include "pch.h"
#include "CppUnitTest.h"
#include "../pds_15/pds_15.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestIsSafe)
        {
            const int n = 8;

            for (int i = 0; i < n; i++) position[i] = -1;

            position[0] = 0;
            Assert::IsTrue(isSafe(1, 2, n)); 
            Assert::IsFalse(isSafe(1, 0, n)); 
        }
	};
}
