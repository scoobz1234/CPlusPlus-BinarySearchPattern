/*
Copyright© 2019, Stephen R Ouellette
CSC215 C/C++ Programming
04 Assignment SkyNet Search Program
*/

//this ensures that whats included does not get included more than once...
#pragma once
//PREPROCESSOR DIRECTIVES
#include <iostream>

using std::string;

class aiDrone
{
public:
	// this is our constructor. it takes in an integer as an argument...
	aiDrone(int enemyLocation);
	//this will be our public function that main will run, takes in references to counters from main, returns them once they are modified...
	int beginSearching(int & aiBinarySearchPredictionCounter, int & aiLinearSearchPredictionCounter, int & aiRandomSearchPredictionCounter);

private:

	//private functions that will perform our search functions...
	void performBinarySearch();
	void performLinearSearch();
	void performRandomSearch();

	// Variable that holds the enemy location passed in when main creates an instance of the drone...
	int enemyLocation = 0;

	// These variables store the number of repititions each search takes to find the enemy location...
	int aiBinarySearchCounter = 0;
	int aiLinearSearchCounter = 0;
	int aiRandomSearchCounter = 0;

	// is target found / destroyed these are all flags for the particular search...
	bool isAIBinaryTargetFound = false;
	bool isAILinearTargetFound = false;
	bool isAIRandomTargetFound = false;

	// these variables are where we store the search predictions...
	int aiBinaryTargetLocationPrediction = 0;
	int aiLinearTargetLocationPrediction = 0;
	int aiRandomTargetLocationPrediction = 0;

	// init var to hold the min number
	// setting upt grid size...
	int binarySearchGridHighNumber = 64;
	int binarySearchGridLowNumber = 1;
	int linearSearchGridHighNumber = 64;
	int linearSearchGridLowNumber = 1;
};

