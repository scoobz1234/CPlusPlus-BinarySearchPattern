/*
Copyright© 2019, Stephen R Ouellette
CSC215 C/C++ Programming
04 Assignment SkyNet Search Program
*/

#include <ctime>
#include "human.h"  //our human
#include "aiDrone.h" //the drone...

using namespace std;

int main (int argc, char** argv)
{
	// required a really randomized number by help of seeding useing ctime.
	// this is seeding the random number generator.
	// randomizing the number between 1-64,
	// note this will have the same pattern without srand to seed the
	// random number sequence
	srand(time(0));
	// getting the secret enemy location, this will be the exact same for all players...
	// there is no need to make 4 of these. this will be shared.
	int enemyLocation = rand() % 64 + 1;
	
	// generate random enemy location on 8x8 grid.
	// setting up description for user
	cout << "Generate Random enemy location on 8x8 grid with 1-64 sectors... " << endl;
	cout << "SkyKet HK-Aerial Initializing software...." << endl;
	
	//Variable Declaration and initialization...
	int humanSearchPredictionCounter, aiBinarySearchPredictionCounter,
		aiLinearSearchPredictionCounter, aiRandomSearchPredictionCounter = 0;

	//create the aiDrone object instance...
	aiDrone aiDrone(enemyLocation);
	//create the Human object instance...
	human human(enemyLocation);
	//run the begin searching function for the human instanced object. pass in the required information..returns an int...
	human.beginSearching(humanSearchPredictionCounter);
	//run the begin searching function of the aiDrone instanced object. pass in the required information..returns an int x3...
	aiDrone.beginSearching(aiBinarySearchPredictionCounter, aiLinearSearchPredictionCounter, aiRandomSearchPredictionCounter);

	//display winner and stats...
	cout << "\n\n\n==============================================================" << endl;
	cout << "                 All drones have been found" << endl;
	cout << "==============================================================" << endl;
	cout << "\n\nSkyNet HK-Aerial Human Search Software Took " << humanSearchPredictionCounter << " Predictions" << endl;
	cout << "SkyNet HK-Aerial Binary Search Software Took " << aiBinarySearchPredictionCounter << " Predictions" << endl;
	cout << "SkyNet HK-Aerial Linear Search Software Took " << aiLinearSearchPredictionCounter << " Predictions" << endl;
	cout << "SkyNet HK-Aerial Random Search Software Took " << aiRandomSearchPredictionCounter << " Predictions" << endl;
	cout << "\n\n==============================================================" << endl;
	cout << "==============================================================" << endl;
	system("pause");

	return EXIT_SUCCESS;
}