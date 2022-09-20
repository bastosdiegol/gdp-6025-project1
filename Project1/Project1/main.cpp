#include "MyMatrix.h"

#include <iostream>

void operatorsTest() {
	std::cout << "Matrix A:" << std::endl;
	MyMatrix ma(2, 2, 2);
	ma.printMatrix();
	std::cout << "\nMatrix B:" << std::endl;
	MyMatrix mb(3, 3, 1);
	mb.printMatrix();
	std::cout << "\nMatrix C:" << std::endl;
	MyMatrix mc( { {1, 4, 5}, 
				   {3,-1, 9}, 
				   {0, 2, 6} } );
	mc.printMatrix();
}

int main(int argc, char** argv) {
	operatorsTest();
}
