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
	this->matrixValues.resize(rows);
	for (int i = 0; i < rows; i++) {
		this->matrixValues[i].resize(columns, 0);
	}
}

// Overloaded Constructor
// Accepts a value and number of rows and columns and fill the matrix with the same value
MyMatrix::MyMatrix(unsigned int rows, unsigned int columns, float value) {
	// Set values for rows and columns
	this->rows = rows;
	this->columns = columns;

	// Resize the Vector rows and columns accordingly
	this->matrixValues.resize(rows);
	for (int i = 0; i < rows; i++) {
		this->matrixValues[i].resize(columns, value);
	}
}

// Overloaded Constructor
// Accepts a 2D vector and assignt it to the Matrix 
MyMatrix::MyMatrix(std::vector< std::vector<float> > newValues) {
	// Set values for rows and columns
	this->rows = newValues.size();
	this->columns = newValues[0].size();

	// Resize the Vector rows and columns accordingly
	// And pass the values to each position
	this->matrixValues.resize(rows);
	for (int i = 0; i < rows; i++) {
		this->matrixValues[i].resize(columns);
	}
	this->matrixValues = newValues;
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
	this->rows			 = rhs.rows;
	this->columns		 = rhs.columns;
	this->matrixValues	 = rhs.matrixValues;
}

// Destructor
MyMatrix::~MyMatrix() {

}

// Addition Operator Overload
// WhiteBoxTest Case #1 (?)
MyMatrix MyMatrix::operator+(const MyMatrix& rhs) {
	MyMatrix operationResult(this->rows, this->columns, 0);
	if (this->isDefined('+', rhs)) {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				operationResult.matrixValues[i][j] = this->matrixValues[i][j] + rhs.matrixValues[i][j];
			}
		}
	}
	else {
		std::cout << "Addition operation could not be done. Matrices are not Defined.";
	}
	return operationResult;
}

// Subtract Operator Overload
// BlackBoxTest Case #1 (?)
MyMatrix MyMatrix::operator-(const MyMatrix& rhs) {
	MyMatrix operationResult(this->rows, this->columns, 0);
	if (this->isDefined('-', rhs)) {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				operationResult.matrixValues[i][j] = this->matrixValues[i][j] - rhs.matrixValues[i][j];
			}
		}
	}
	else {
		throw("Subtraction operation could not be done. Matrices are not Defined.");
		//std::cout << "Subtraction operation could not be done. Matrices are not Defined.";
	}
	return operationResult;
}

// Multiply Operator Overload
// WhiteBoxTest Case #2 (?)
MyMatrix MyMatrix::operator*(const MyMatrix& rhs) {
	MyMatrix operationResult(this->rows, rhs.columns, 0);

	if (this->isDefined('*', rhs)) {

		// Matrix A Iteration Loop
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < rhs.columns; j++) {
				// Matrix B Column Loop
				for (int k = 0; k < rhs.rows; k++) {
					// Result [i][j]
					// A | a00 a01 a02 | * B | b00 b01 |
					//   | a10 a11 a12 |     | b10 b11 |
					//						 | b20 b21 |
					// = R | (a00*b00 + a01*b10 + a02*b20) (a00*b01 + a01*b11 + a02*b21) |
					//	   | (a10*b00 + a11*b10 + a12*b20) (a10*b01 + a11*b11 + a12*b21) |
					// 
					// 1st Iteration
					// (a00*b00 + a01*b10 + a02*b20)	i = 0
					//   ik  kj    ik  kj    ik  kj 	j = 0
					//									k = 0 ... 2
					// 2nd Iteration
					// (a00*b01 + a01*b11 + a02*b21)	i = 0
					//   ik  kj    ik  kj    ik  kj		j = 1
					//									k = 0 ... 2
					operationResult.matrixValues[i][j] = operationResult.matrixValues[i][j]
														 + (this->matrixValues[i][k] * rhs.matrixValues[k][j]);
				}
			}
		}
	}
	else {
		std::cout << "Addition operation could not be done. Matrices are not Defined.";
	}
	return operationResult;
}

// Multiply Operator Overload - By a Scalar
// BlackBoxTest Case 2 (?)
MyMatrix MyMatrix::operator*(const float rhs) {
	MyMatrix operationResult(this->rows, this->columns, 0);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			operationResult.matrixValues[i][j] = this->matrixValues[i][j] * rhs;
		}
	}
	return operationResult;
}

// Division & Assign Operator Overload - By a Scalar
// WhiteBoxTest Case #3 (?)
MyMatrix& MyMatrix::operator/=(const float rhs) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			this->matrixValues[i][j] = this->matrixValues[i][j] / rhs;
		}
	}
	return *this;
}

// Division Operator Overload - By a Scalar
// BlackBoxTest Case #3 (?)
MyMatrix MyMatrix::operator/(const float rhs) {
	MyMatrix operationResult(this->rows, this->columns, 0);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			operationResult.matrixValues[i][j] = this->matrixValues[i][j] / rhs;
		}
	}
	return operationResult;
}

// Assignment Operator Overload
MyMatrix& MyMatrix::operator=(const MyMatrix& rhs) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			this->matrixValues[i][j] = rhs.matrixValues[i][j];
		}
	}
	return *this;
}

// Verifies if this Matrix is defined in relation to rhs
// Based a specified mathematical operation ( + - * / )
// On + and - it is Defined when both Matrices rows and columns matches
// On * and / it is Defined when 1st Matrix Columns matches 2nd Matrix Rows
// Returns a boolean which allows or not that denoted operation
// WhiteBoxTest Case #4 (?)
bool MyMatrix::isDefined(char operation, const MyMatrix& rhs) {
	if (operation == '+' || operation == '-') {
		if (this->rows == rhs.rows && this->columns == rhs.columns) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (operation == '*' || operation == '/') {
		if (this->columns == rhs.rows) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		throw std::invalid_argument("Invalid Operation argument on isDefined() method.");
	}
}

// Returns its Identity Matrix
// Identity Matrix is always a Square matrix 
// Defined by the row size of given matrix
// | 1 0 0 |
// | 0 1 0 |
// | 0 0 1 |
// BlackBoxTest Case #4 (?)
MyMatrix MyMatrix::getIdentityMatrix() {
	MyMatrix operationResult(this->rows, this->columns, 0);
	if (this->rows == this->columns) {
		for (int i = 0; i < this->rows; i++) {
			operationResult.matrixValues[i][i] = 1;
		}
	}
	else {
		std::cout << "Exception: Given matrix isn't a square matrix." << std::endl;
	}
	return operationResult;
}

// Returns the Determinant of a 2x2 Matrix
// | a b | Determinant = ( a * d ) - ( b * c )
// | c d | 
// WhiteBoxTest Case #5 (?)
float MyMatrix::getDeterminant2x2() {
	if (this->rows == 2 && this->columns == 2) {
		return (	(this->matrixValues[0][0] * this->matrixValues[1][1])
			      -	(this->matrixValues[0][1] * this->matrixValues[1][0]) );
	}
	else {
		return 0;
	}
	std::cout << "Exception: Matrix type missmatch. Determinant2x2 is Requires Matrix2x2!" << std::endl;
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
	MyMatrix invertedMatrix2x2(this->rows, this->columns, 0);
	if (this->rows == 2 && this->columns == 2) {
		float det = this->getDeterminant2x2();
		
		invertedMatrix2x2.matrixValues = { {this->matrixValues[1][1],	 this->matrixValues[0][1]*-1},
						                   {this->matrixValues[1][0]*-1, this->matrixValues[0][0]} };

		invertedMatrix2x2 /= det;
	}
	else {
		throw("Exception: Matrix type missmatch. getInverseMatrix2x2() requires Matrix2x2!" );
	}

	return invertedMatrix2x2;
}

// Outputs the values of the matrix visually on the console
void MyMatrix::printMatrix() {
	std::cout << "This is a " << this->rows << "x" << this->columns << " matrix" << std::endl;
	for (int i = 0; i < this->rows; i++) {
		std::cout << "|   ";
		for (int j = 0; j < this->columns; j++) {
			std::cout << this->matrixValues[i][j] << "   ";
		}
		std::cout << "|" << std::endl;
	}
}


// Compare Operator Overload
bool operator==(const MyMatrix& rhs, const MyMatrix& lhs) {
	if (rhs.rows == rhs.rows && rhs.columns == rhs.columns) {
		for (int i = 0; i < rhs.rows; i++) {
			for (int j = 0; j < rhs.columns; j++) {
				if (rhs.matrixValues[i][j] != rhs.matrixValues[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}