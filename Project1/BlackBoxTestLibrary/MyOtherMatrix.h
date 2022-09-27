#pragma once
#include <vector>

#ifdef BLACKBOXTESTLIBRARY_EXPORTS
#define BLACKBOXTEST_API __declspec(dllexport)
#else
#define BLACKBOXTEST_API __declspec(dllimport)
#endif

	class BLACKBOXTEST_API MyOtherMatrix {
	private:

	public:
		// Size of rows and columns of the Matrix
		unsigned int rows;
		unsigned int columns;

		// Values of the Matrix
		std::vector< std::vector<float> > matrixValues;

		// Overloaded Constructor
		// Accepts the number of rows and columns and set the matrix
		// The values will be 0
		MyOtherMatrix(unsigned int rows, unsigned int columns);

		// Overloaded Constructor
		// Accepts a value and number of rows and columns and fill the matrix with the same value
		MyOtherMatrix(unsigned int rows, unsigned int columns, float value);

		// Overloaded Constructor
		// Accepts a 2D vector and assignt it to the Matrix 
		MyOtherMatrix(std::vector< std::vector<float> > newValues);

		// Copy Constructor
		// Accepts a reference of another Matrix
		MyOtherMatrix(const MyOtherMatrix& rhs);

		// Destructor
		~MyOtherMatrix();

		// Assignment Operator Overload
		// WhiteBoxTest Case #1
		MyOtherMatrix operator+(const MyOtherMatrix& rhs);

		// Subtract Operator Overload
		// BlackBoxTest Case #1
		MyOtherMatrix operator-(const MyOtherMatrix& rhs);

		// Multiply Operator Overload
		// WhiteBoxTest Case #2
		MyOtherMatrix operator*(const MyOtherMatrix& rhs);

		// Multiply Operator Overload - By a Scalar
		// BlackBoxTest Case #2
		MyOtherMatrix operator*(const float rhs);

		// Division & Assign Operator Overload - By a Scalar
		// WhiteBoxTest Case #3
		MyOtherMatrix& operator/=(const float rhs);

		// Division Operator Overload - By a Scalar
		// BlackBoxTest Case #3
		MyOtherMatrix operator/(const float rhs);

		// Assignment Operator Overload
		MyOtherMatrix& operator=(const MyOtherMatrix& rhs);

		// Verifies if this Matrix is defined in relation to rhs
		// Based a specified mathematical operation ( + - * / )
		// On + and - it is Defined when both Matrices rows and columns matches
		// On * and / it is Defined when 1st Matrix Columns matches 2nd Matrix Rows
		// Returns a boolean which allows or not that denoted operation
		// WhiteBoxTest Case #4
		bool isDefined(char operation, const MyOtherMatrix& rhs);

		// Returns its Identity Matrix
		// Identity Matrix is always a Square matrix 
		// Defined by the row size of given matrix
		// | 1 0 0 |
		// | 0 1 0 |
		// | 0 0 1 |
		// BlackBoxTest Case #4
		MyOtherMatrix getIdentityMatrix();

		// Returns the Determinant of a 2x2 Matrix
		// | a b | Determinant = ( a * d ) - ( b * c )
		// | c d | 
		// WhiteBoxTest Case #5
		float getDeterminant2x2();

		// Returns the Inverted Matrix of a 2x2 Matrix
		// 1 / Det ( Matrix ) * Adjugate ( Matrix )
		// ------Scalar------   -------Matrix-------
		// 
		// | a b | Adjugate = |  d  -b |
		// | c d |            | -c   a |
		// Matrix * Its Inverted Matrix = Identity Matrix
		// BlackBoxTest Case #5
		MyOtherMatrix getInverseMatrix2x2();

		// Outputs the values of the matrix visually on the console
		void printMatrix();

	};

	// Compare Operator Override
	BLACKBOXTEST_API bool operator==(const MyOtherMatrix& rhs, const MyOtherMatrix& lhs);