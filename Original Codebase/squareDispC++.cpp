#include <armadillo>
#include <vector>
#include <string>

using namespace arma;

int main (){

	//initialize track constants
	int dt = 8;
	double resolution = 0.107;

	//load and display input track
	mat track;
	track.load("track.csv",csv_ascii);
	std::cout << "         x         y          z" << std::endl;
	std::cout << track << std::endl;

	//throw error if dt is too high
	if (dt >= track.n_rows){
		std::cout << "track length: " << track.n_rows << std::endl;
		std::cout <<"dt: " << dt << std::endl;
		std::cout << "Time interval (dt) greater than track length" << std::endl;
		return 0;
	}

	//create dt matrices
	std::vector<mat> trackOut;
	trackOut.push_back(mat(track.n_rows/dt+1, 7));
	for (int i = 1; i < dt; i++){
		trackOut.push_back(mat(track.n_rows/dt, 7));
	}

	//fill and print in dt matrices
	int counter = 0;
	int j = 0;

	for (int i = 0; i < track.n_rows; i++){
			trackOut[counter](j, 0) = track (i, 0);
			trackOut[counter](j, 1) = track (i, 1);
			trackOut[counter](j, 2) = track (i, 2);
			trackOut[counter](j, 3) = i + 1;
			if (i < dt){
				trackOut[counter](j, 4) = datum::nan;
				trackOut[counter](j, 5) = datum::nan;
				trackOut[counter](j, 6) = datum::nan;
			} else {
				double dx = (track (i, 0)-track (i-dt, 0))*resolution;
				double dy = (track (i, 1)-track (i-dt, 1))*resolution;
				trackOut[counter](j, 4) = dx*dx + dy*dy;
				trackOut[counter](j, 5) = dx;
				trackOut[counter](j, 6) = dy;

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
			std::cout << trackOut[i] << std::endl;
	}

	return 0;
}
