/*
Copyright© 2019, Stephen R Ouellette
CSC215 C/C++ Programming
04 Assignment SkyNet Search Program
*/

//PREPROCESSOR DIRECTIVES
#include "human.h"

// These using directives makes it so we dont have to keep typing std::...
using std::cout;
using std::endl;
using std::cin;

human::human(int enemyLocation)
{
	human::enemyLocation = enemyLocation;
}

int human::beginSearching(int & humanSearchPredictionCounter) 
{
	performHumanSearch();

	humanSearchPredictionCounter = humanSearchCounter;
	return humanSearchPredictionCounter;
}

//this is where we perform our human search

/* NOTE...to expedite this process we are telling the user what the enemy location is..
we would normally not do this... */

void human::performHumanSearch() 
{
	while (isHumanTargetFound == false)
	{

		cout << "\nPlease type in your target location guess: ";
		cin >> humanTargetLocationPrediction;

		humanSearchCounter++;
		//remind the user where they predicted the enemy location is...
		cout << "\nYour prediction where the enemy is located is at " << humanTargetLocationPrediction << endl;
		// radar ping of enemy location
		cout << "==================================================" << endl;
		cout << "Skynet HK-Aerial Radar performing search # " << humanSearchCounter << endl;

		//if the prediction is greater than the enemy location...
		if (humanTargetLocationPrediction > enemyLocation)
		{
			cout << "The target location prediction of " << humanTargetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
		}
		//if the prediction is less than enemy location...
		else if (humanTargetLocationPrediction < enemyLocation)
		{
			cout << "The target location prediction of " << humanTargetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
		}
		//this is the win scenario, prediction is the enemy location...
		else if (humanTargetLocationPrediction == enemyLocation)
		{
			cout << "target is found!!!!!" << endl;
			cout << "Enemy was hiding and found at location # " << humanTargetLocationPrediction << endl;
			cout << "SkyNet HK-Aerial Human Search software took " << humanSearchCounter << endl;
			isHumanTargetFound = true;
		}
		else
		{
			//something wrong
			cout << "something went wrong" << endl;
			isHumanTargetFound = true;
		}
	}
}

