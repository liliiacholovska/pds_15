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
		
        TEST_METHOD(TestSolveNQueens)
        {
            const int n = 4;
            std::ostringstream output;
            std::streambuf* old_buf = std::cout.rdbuf(output.rdbuf());

            int position[MAX_N];

            auto isSafe = [&position](int row, int col, int n) -> bool {
                for (int i = 0; i < row; i++) {
                    if (position[i] == col || abs(position[i] - col) == abs(i - row)) {
                        return false;
                    }
                }
                return true;
                };

            auto printSolution = [&position](int n) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (position[i] == j)
                            std::cout << "Q ";
                        else
                            std::cout << ". ";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                };

            auto solveNQueens = [&position, &isSafe, &printSolution](int row, int n) {
                if (row == n) {
                    printSolution(n); 
                    return;
                }

                for (int col = 0; col < n; col++) {
                    if (isSafe(row, col, n)) {
                        position[row] = col; 
                    }
                }
                };

            solveNQueens(0, n); 

            std::cout.rdbuf(old_buf); 
        }
	};
}
