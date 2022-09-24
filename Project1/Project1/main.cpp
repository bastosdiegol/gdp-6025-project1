#include "MyMatrix.h"

#include <iostream>
#include <gtest/gtest.h>

// Global Variables for Test Purpose
MyMatrix g_ma(3, 3, 1);
MyMatrix g_mb(3, 3, 2);
MyMatrix g_mc({ {10, 20},
				{30, 40} });
MyMatrix g_md({ {1, 2},
				{3, 4} });

MyMatrix g_maADDb(3, 3, 3);
MyMatrix g_maMULb(3, 3, 6);
MyMatrix g_mcDIV2({ { 5, 10},
				    {15, 20} });

void myMatrixTests() {

	try {
		std::cout << "Matrix A:" << std::endl;
		MyMatrix ma(2, 2, 2);
		ma.printMatrix();
		std::cout << "\nMatrix B:" << std::endl;
		MyMatrix mb(3, 3, 1);
		mb.printMatrix();
		std::cout << "\nMatrix C:" << std::endl;
		MyMatrix mc({ {1, 4, 5},
					   {3,-1, 9},
					   {0, 2, 6} });
		mc.printMatrix();
		mc.getIdentityMatrix().printMatrix();


		MyMatrix madd = mb + mc;
		madd.printMatrix();

		// Matrices Not Defined - Exception
		// MyMatrix msub = mb - ma; 
		// msub.printMatrix();

		MyMatrix md({ {1, 2, 3},
					  {4, 5, 6} });
		md.printMatrix();
		MyMatrix me({ {7,   8},
					  {9,  10},
					  {11, 12} });
		me.printMatrix();
		MyMatrix mx = md * me;
		mx.printMatrix();

		MyMatrix mf({ {1, 2},
					  {3, 4} });
		mf.printMatrix();
		float det = mf.getDeterminant2x2();
		std::cout << "Previous matrix determinant is: " << det << std::endl;

		MyMatrix mxs = mf * 10;
		mxs.printMatrix();
		mxs = mxs / 2;
		mxs.printMatrix();

		ma.matrixValues = { {3, 4},
							{1, 2} };
		std::cout << "Identity Matrix: \n";
		MyMatrix id2x2 = ma.getIdentityMatrix();
		id2x2.printMatrix();


		std::cout << "Inverse of a Identity Matrix: \n";
		id2x2.getIdentityMatrix().printMatrix();

		std::cout << "Inverted Matrix: \n";
		MyMatrix invertedMxs = ma.getInverseMatrix2x2();
		invertedMxs.printMatrix();

		std::cout << "Matrix( ma * invertedMxs ): \n";
		MyMatrix invertedXmatrix = ma * invertedMxs;
		invertedXmatrix.printMatrix();

	}
	catch (const char* error) {
		std::cout << error << std::endl;
	}
	return;
}

// WhiteBoxTest Case #1 MyMatrix operator+(const MyMatrix& rhs);
TEST(WhiteBoxTestCases, WBTCase1) {
	EXPECT_EQ(g_maADDb, g_ma + g_mb);
}

// WhiteBoxTest Case #2 MyMatrix operator*(const MyMatrix& rhs);
TEST(WhiteBoxTestCases, WBTCase2) {
	EXPECT_EQ(g_maMULb, g_ma * g_mb);
}

// WhiteBoxTest Case #3 MyMatrix& operator/=(const float rhs);
TEST(WhiteBoxTestCases, WBTCase3) {
	EXPECT_EQ(g_mcDIV2, g_mc /= 2);
}

// WhiteBoxTest Case #4 bool isDefined(char operation, const MyMatrix& rhs);
// Operation '%' mod is not a valid argument for isDefined method
TEST(WhiteBoxTestCases, WBTCase4) {
	EXPECT_THROW( g_ma.isDefined('%', g_mb), std::invalid_argument);
}

// WhiteBoxTest Case #5 float getDeterminant2x2();
TEST(WhiteBoxTestCases, WBTCase5) {
	EXPECT_EQ(-2, g_md.getDeterminant2x2());
}

int main(int argc, char** argv) {
	//myMatrixTests();

	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();

	return result;
}
