#pragma once
#include "MyOtherMatrix.h"
#include "pch.h"

#ifdef BLACKBOXTESTLIBRARY_EXPORTS
#define BLACKBOXTEST_API __declspec(dllexport)
#else
#define BLACKBOXTEST_API __declspec(dllimport)
#endif


// Use extern "C" so C++ compiler does not mess with
// the headers we defined
extern "C"
{
	// test
	BLACKBOXTEST_API int sum(int a, int b);
	// BlackBoxTest Case #1 MyOtherMatrix operator-(const MyOtherMatrix& rhs);
	BLACKBOXTEST_API MyOtherMatrix substract(MyOtherMatrix rhs, MyOtherMatrix lhs);
	// BlackBoxTest Case #2 MyOtherMatrix operator*(const float rhs);
	BLACKBOXTEST_API MyOtherMatrix multiplication(MyOtherMatrix rhs, float lhs);
	// BlackBoxTest Case #3 MyOtherMatrix operator/(const float rhs);
	BLACKBOXTEST_API MyOtherMatrix division(MyOtherMatrix rhs, float scalar);
	// BlackBoxTest Case #4 MyOtherMatrix getIdentityMatrix();
	BLACKBOXTEST_API MyOtherMatrix getIdentity(MyOtherMatrix m);
	// BlackBoxTest Case #5 MyOtherMatrix getInverseMatrix2x2();
	BLACKBOXTEST_API MyOtherMatrix getInverse2x2(MyOtherMatrix m);
}