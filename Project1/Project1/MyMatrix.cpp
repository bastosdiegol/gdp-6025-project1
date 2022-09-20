#include "MyMatrix.h"

#include <iostream>

// Overloaded Constructor
// Accepts the number of rows and columns and set the matrix
// The values will be 0
MyMatrix::MyMatrix(unsigned int rows, unsigned int columns) {
	// Set values for rows and columns
	this->rows	  = rows;
	this->columns = columns;

	// Resize the Vector rows and columns accordingly
	matrixValues.resize(rows);
	for (int i = 0; i < rows; i++) {
		matrixValues[i].resize(columns, 0);
	}
}

// Overloaded Constructor
// Accepts a value and number of rows and columns and fill the matrix with the same value
MyMatrix::MyMatrix(unsigned int rows, unsigned int columns, int value) {
	// Set values for rows and columns
	this->rows = rows;
	this->columns = columns;

	// Resize the Vector rows and columns accordingly
	matrixValues.resize(rows);
	for (int i = 0; i < rows; i++) {
		matrixValues[i].resize(columns, value);
	}
}

// Overloaded Constructor
// Accepts a 2D vector and assignt it to the Matrix 
MyMatrix::MyMatrix(std::vector< std::vector<int> > newValues) {
	// Set values for rows and columns
	rows = newValues.size();
	columns = newValues[0].size();

	// Resize the Vector rows and columns accordingly
	// And pass the values to each position
	matrixValues.resize(rows);
	for (int i = 0; i < rows; i++) {
		matrixValues[i].resize(columns);
	}
	matrixValues = newValues;
	/*for (int iR = 0; iR < rows; iR++) {
		matrixValues[iR].resize(columns);
		for (int iC = 0; iC < columns; iC++) {
			matrixValues[iR][iC] = newValues[iR][iC];
		}
	}*/
}

// Copy Constructor
// Accepts a reference of another Matrix
MyMatrix::MyMatrix(const MyMatrix& rhs) {
	// Copy the Class variables
	rows		 = rhs.rows;
	columns		 = rhs.columns;
	matrixValues = rhs.matrixValues;
}

// Destructor
MyMatrix::~MyMatrix() {

}

// Assignment Operator Overload
// WhiteBoxTest Case #1 (?)
MyMatrix MyMatrix::operator+(const MyMatrix& rhs) {
	return MyMatrix(1,1,1);
}

// Subtract Operator Overload
// BlackBoxTest Case #1 (?)
MyMatrix MyMatrix::operator-(const MyMatrix& rhs) {
	return MyMatrix(1, 1, 1);
}

// Multiply Operator Overload
// WhiteBoxTest Case #2 (?)
MyMatrix MyMatrix::operator*(const MyMatrix& rhs) {
	return MyMatrix(1, 1, 1);
}

// Multiply Operator Overload - By a Scalar
// BlackBoxTest Case 2 (?)
MyMatrix MyMatrix::operator*(const int rhs) {
	return MyMatrix(1, 1, 1);
}

// Division Operator Overload
// WhiteBoxTest Case #3 (?)
MyMatrix MyMatrix::operator/(const MyMatrix& rhs) {
	return MyMatrix(1, 1, 1);
}

// Division Operator Overload - By a Scalar
// BlackBoxTest Case #3 (?)
MyMatrix MyMatrix::operator/(const int rhs) {
	return MyMatrix(1, 1, 1);
}

// Assignment Operator Overload
MyMatrix MyMatrix::operator=(const MyMatrix& rhs) {
	return MyMatrix(1, 1, 1);
}

// Verifies if this Matrix is defined in relation to rhs
// Based a specified mathematical operation ( + - * / )
// On + and - it is Defined when both Matrices rows and columns matches
// On * and / it is Defined when 1st Matrix Columns matches 2nd Matrix Rows
// Returns a boolean which allows or not that denoted operation
// WhiteBoxTest Case #4 (?)
bool MyMatrix::isDefined(char operation, const MyMatrix& rhs) {
	return false;
}

// Returns its Identity Matrix
// Identity Matrix is always a Square matrix 
// Defined by the row size of given matrix
// | 1 0 0 |
// | 0 1 0 |
// | 0 0 1 |
// BlackBoxTest Case #4 (?)
MyMatrix MyMatrix::getIdentityMatrix() {
	return MyMatrix(1, 1, 1);
}

// Returns the Determinant of a 2x2 Matrix
// | a b | Determinant = ( a * d ) - ( b * c )
// | c d | 
// WhiteBoxTest Case #5 (?)
int MyMatrix::getDeterminant2x2() {
	return -1;
}

// Returns the Inverted Matrix of a 2x2 Matrix
// 1 / Det ( Matrix ) * Adjugate ( Matrix )
// ------Scalar------   -------Matrix-------
// 
// | a b | Adjugate = |  d  -b |
// | c d |            | -c   a |
// Matrix * Its Inverted Matrix = Identity Matrix
// BlackBoxTest Case #5 (?)
MyMatrix MyMatrix::getInverseMatrix2x2() {
	return MyMatrix(1, 1, 1);
}

// Outputs the values of the matrix visually on the console
void MyMatrix::printMatrix() {
	std::cout << "This is a " << rows << "x" << columns << " matrix" << std::endl;
	for (int i = 0; i < rows; i++) {
		std::cout << "|   ";
		for (int j = 0; j < columns; j++) {
			std::cout << matrixValues[i][j] << "   ";
		}
		std::cout << "|" << std::endl;
	}
}