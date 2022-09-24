#include "BlackBoxTest.h"
#include "pch.h"

// BlackBoxTest Case #1 
// MyOtherMatrix operator-(const MyOtherMatrix& rhs);
MyOtherMatrix substract(MyOtherMatrix rhs, MyOtherMatrix lhs) {
	return rhs - lhs;
}
// BlackBoxTest Case #2
// MyOtherMatrix operator*(const float rhs);
MyOtherMatrix multiplication(MyOtherMatrix rhs, float lhs) {
	return rhs * lhs;
}
// BlackBoxTest Case #3
// MyOtherMatrix operator/(const float rhs);
MyOtherMatrix division(MyOtherMatrix rhs, float scalar) {
	return rhs * scalar;
}
// BlackBoxTest Case #4
// MyOtherMatrix getIdentityMatrix();
MyOtherMatrix substract(MyOtherMatrix m) {
	return m.getIdentityMatrix();
}
// BlackBoxTest Case #5
// MyOtherMatrix getInverseMatrix2x2();
MyOtherMatrix substract(MyOtherMatrix m) {
	return m.getInverseMatrix2x2();
}