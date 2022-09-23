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


	MyMatrix mr = mb + mc;
	mr.printMatrix();

	mr = mb - mc;
	mr.printMatrix();

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
	MyMatrix mxs = mf * 10;
	mxs.printMatrix();
	mxs = mxs / 2;
	mxs.printMatrix();
	
	return;
}

int main(int argc, char** argv) {
	operatorsTest();

	return EXIT_SUCCESS;
}
