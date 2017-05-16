#include <armadillo>
#include <vector>

using namespace arma;

int main (){

	//display test
	mat test;
	test.load("test.csv",csv_ascii);
	std::cout << "   x         y          z" << std::endl;
	std::cout << test << std::endl;

	//initialize test constants
	int dt = 8;
	double resolution = 0.107;

	//throw error if dt too high
	if (dt >= test.n_rows){
		std::cout << "track length: " << test.n_rows << std::endl;
		std::cout <<"dt: " << dt << std::endl;
		std::cout << "Time interval (dt) greater than track length" << std::endl;
		return 0;
	}

	//create dt matrices
	std::vector<mat> testOut;
	testOut.push_back(mat(test.n_rows/dt+1, 7));
	for (int i = 1; i < dt; i++){
		testOut.push_back(mat(test.n_rows/dt, 7));
	}


	//fill in dt matrices
	int counter = 0;
	int j = 0;

	for (int i = 0; i < test.n_rows; i++){
			testOut[counter](j, 0) = test (i, 0);
			testOut[counter](j, 1) = test (i, 1);
			testOut[counter](j, 2) = test (i, 2);
			testOut[counter](j, 3) = i + 1;
			if (i < dt){
				testOut[counter](j, 4) = datum::nan;
				testOut[counter](j, 5) = datum::nan;
				testOut[counter](j, 6) = datum::nan;
			} else {
				double dx = (test (i, 0)-test (i-dt, 0))*resolution;
				double dy = (test (i, 1)-test (i-dt, 1))*resolution;
				testOut[counter](j, 4) = dx*dx + dy*dy;
				testOut[counter](j, 5) = dx;
				testOut[counter](j, 6) = dy;

			}
			counter++;
			if (counter == dt){
				counter = 0;
				j++;
			}
	}
	for (int i = 0; i < dt; i++){
			std::cout << "         x         y         z";
			std::cout << "     index      disp        dx        dy" << std::endl;
			std::cout << testOut[i] << "\n" <<std::endl;
	}

	return 0;
}
