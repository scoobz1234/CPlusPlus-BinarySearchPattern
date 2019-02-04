/*
Copyright© 2019, Stephen R Ouellette
CSC215 C/C++ Programming
04 Assignment SkyNet Search Program
*/

#pragma once
#include <iostream>

class human
{
public:
	human(int enemyLocation);
	int beginSearching(int & humanSearchPredictionCounter);
private:

	void performHumanSearch();
	// This variable stores the number of repititions the human (user) takes to find the enemy location...
	int humanSearchCounter = 0;
	// is target found / destroyed these are all flags for the particular search...
	bool isHumanTargetFound = false;
	// these variables are where we store the search predictions...
	int humanTargetLocationPrediction = 0;
	// Variable that holds the enemy location passed in when main creates an instance of the drone...
	int enemyLocation = 0;
};

