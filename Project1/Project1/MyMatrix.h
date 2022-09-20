#pragma once
#include <vector>

class MyMatrix {
private:

public:
	// Size of rows and columns of the Matrix
	unsigned int rows;
	unsigned int columns;

	// Values of the Matrix
	std::vector< std::vector<int> > matrixValues;

	// Default Constructor
	MyMatrix();

	// Overloaded Constructor
	// Accepts a 2D vector and assignt it to the Matrix 
	MyMatrix(std::vector< std::vector<int> > newValues);

	// Overloaded Constructor
	// Accepts another Matrix
	MyMatrix(const MyMatrix& newMatrix);

	// Destructor
	~MyMatrix();

	// Assignment Operator Overload
	// WhiteBoxTest Case #1 (?)
	MyMatrix operator+(const MyMatrix& rhs);

	// Subtract Operator Overload
	// BlackBoxTest Case #1 (?)
	MyMatrix operator-(const MyMatrix& rhs);

	// Multiply Operator Overload
	// WhiteBoxTest Case #2 (?)
	MyMatrix operator*(const MyMatrix& rhs);

	// Multiply Operator Overload - By a Scalar
	// BlackBoxTest Case 2 (?)
	MyMatrix operator*(const int rhs);

	// Division Operator Overload
	// WhiteBoxTest Case #3 (?)
	MyMatrix operator/(const MyMatrix& rhs);

	// Division Operator Overload - By a Scalar
	// BlackBoxTest Case #3 (?)
	MyMatrix operator/(const int rhs);

	// Assignment Operator Overload
	MyMatrix operator=(const MyMatrix& rhs);

	// Verifies if this Matrix is defined in relation to rhs
	// Based a specified mathematical operation ( + - * / )
	// On + and - it is Defined when both Matrices rows and columns matches
	// On * and / it is Defined when 1st Matrix Columns matches 2nd Matrix Rows
	// Returns a boolean which allows or not that denoted operation
	// WhiteBoxTest Case #4 (?)
	bool isDefined(char operation, const MyMatrix& rhs);

	// Returns its Identity Matrix
	// Identity Matrix is always a Square matrix 
	// Defined by the row size of given matrix
	// | 1 0 0 |
	// | 0 1 0 |
	// | 0 0 1 |
	// BlackBoxTest Case #4 (?)
	MyMatrix getIdentityMatrix();

	// Returns the Determinant of a 2x2 Matrix
	// | a b | Determinant = ( a * d ) - ( b * c )
	// | c d | 
	// WhiteBoxTest Case #5 (?)
	int getDeterminant2x2();

	// Returns the Inverted Matrix of a 2x2 Matrix
	// 1 / Det ( Matrix ) * Adjugate ( Matrix )
	// ------Scalar------   -------Matrix-------
	// 
	// | a b | Adjugate = |  d  -b |
	// | c d |            | -c   a |
	// Matrix * Its Inverted Matrix = Identity Matrix
	// BlackBoxTest Case #5 (?)
	MyMatrix getInverseMatrix2x2();
};