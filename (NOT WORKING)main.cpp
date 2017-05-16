#include <stdio.h>
#include <string>
#include <iostream>
#include <armadillo>


typedef struct track{
	double x;
	double y;
	int z;
} track;

typedef struct trackOut{
	int index;
	double squareDisp;
	double dx;
	double dy;
} trackOut;

/*typedef struct trackDt{
	int length;
	trackOut t[];
	trackDt(int length) : length(length) {t[length];}
} trackDt;*/

int main(){

	///////////////////////

	track trackTest[9];
	trackTest[0].x = 39.88;
	trackTest[0].y = 46.11;
	trackTest[0].z = 1;
	trackTest[1].x = 39.31;
	trackTest[1].y = 46.96;
	trackTest[1].z = 1;
	trackTest[2].x = 41.94;
	trackTest[2].y = 47.86;
	trackTest[2].z = 1;
	trackTest[3].x = 42.95;
	trackTest[3].y = 48.65;
	trackTest[3].z = 1;
	trackTest[4].x = 42.66;
	trackTest[4].y = 47.91;
	trackTest[4].z = 1;
	trackTest[5].x = 41.32;
	trackTest[5].y = 47.89;
	trackTest[5].z = 1;
	trackTest[6].x = 41.66;
	trackTest[6].y = 48.10;
	trackTest[6].z = 1;
	trackTest[7].x = 42.13;
	trackTest[7].y = 50.90;
	trackTest[7].z = 1;
	trackTest[8].x = 42.69;
	trackTest[8].y = 51.34;
	trackTest[8].z = 1;

	int dt = 2;
	double resolution = 0.107;
	///////////////////////

	int cols = sizeof(trackTest)/sizeof(trackTest[0])/dt + 1;
	int rows = dt;

	if (dt > sizeof(trackTest)){
		std::cout << "track length: " << sizeof(trackTest) + 1 << std::endl;
		std::cout <<"dt: " << dt << std::endl;
		std::cout << "Time interval (dt) greater than track length-1" << std::endl;
		return 0;
	}
	trackOut **trackDtOut = (trackOut**)malloc(rows * sizeof(trackOut*));
	for (int i = 0; i < rows; i++){
		trackDtOut[i] = (trackOut*)malloc(cols * sizeof(trackOut));
		for (int j = 0; j < cols; j++){
			//std::cout<< j;
			//trackDtOut[j][i].dx = trackTest[0].x-1;
			//trackDtOut[j][i].dy = trackTest[0].y-1;
			//std::cout <<trackDtOut[j][i].dx << " " << trackDtOut[j][i].dy;		
		}
	}
	free(trackDtOut);


	return 0;
}

//use armadillo
/*
import datastream into matrix
resize to 3xN table and make it easy to get
*/
