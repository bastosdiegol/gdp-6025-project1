#include "MyMatrix.h"

#include <iostream>
#include <gtest/gtest.h>
#include <MyOtherMatrix.h>

// Variables for White Box Tests
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


/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/


// Variables for Black Box Tests
MyOtherMatrix g_mOa({ {1, 2},
					  {3, 4} });
MyOtherMatrix g_mOb({ {0, 1},
					  {2, 3} });
MyOtherMatrix g_mOc({ {10, 20},
					  {30, 40} });
MyOtherMatrix g_mOcase1Result({ {1, 1},
							    {1, 1} });
MyOtherMatrix g_mOcase2Result({ {7,  14},
								{21, 28} });
MyOtherMatrix g_mOcase3Result({ {5,  10},
								{15, 20} });
MyOtherMatrix g_mOcase4ResultC({ {1, 0},
								 {0, 1} });
MyOtherMatrix g_mOcase4ResultW({ {1, 0, 0},
							 	 {0, 1, 0},
							 	 {0, 0, 1} });
MyOtherMatrix g_mOcase5Result({ { -2,    1},
								{1.5, -0.5} });

// BlackBoxTest Case #1 MyOtherMatrix operator-(const MyOtherMatrix& rhs);
TEST(BlackBoxTestCases, BBTCase1) {
	EXPECT_EQ(g_mOcase1Result, g_mOa - g_mOb);
}

// BlackBoxTest Case #2 MyOtherMatrix operator*(const float rhs);
TEST(BlackBoxTestCases, BBTCase2) {
	EXPECT_EQ(g_mOcase2Result, g_mOa * 7);
}

// BlackBoxTest Case #3 MyOtherMatrix operator/(const float rhs);
TEST(BlackBoxTestCases, BBTCase3) {
	EXPECT_EQ(g_mOcase3Result, g_mOc / 2);
}

// BlackBoxTest Case #4 MyOtherMatrix getIdentity(MyOtherMatrix m);
TEST(BlackBoxTestCases, BBTCase4) {
	EXPECT_EQ(g_mOcase4ResultC, g_mOa.getIdentityMatrix());
}

// BlackBoxTest Case #5 MyOtherMatrix getInverse2x2(MyOtherMatrix m);
TEST(BlackBoxTestCases, BBTCase5) {
	EXPECT_EQ(g_mOcase5Result, g_mOa.getInverseMatrix2x2());
}


int main(int argc, char** argv) {

	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();

	return result;
}
