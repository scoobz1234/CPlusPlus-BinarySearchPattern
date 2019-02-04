/*
Copyright© 2019, Stephen R Ouellette
CSC215 C/C++ Programming
04 Assignment SkyNet Search Program
*/

//PREPROCESSOR DIRECTIVES
#include "aiDrone.h"

// These using directives makes it so we dont have to keep typing std::...
using std::cout;
using std::endl;

aiDrone::aiDrone(int enemyLocation)
{
	//because were using the same name, I needed to use a scope identifier
	aiDrone::enemyLocation = enemyLocation;
}

// This public function takes in a reference to the counters from main. and runs the searches, then returns the values to main.
int aiDrone::beginSearching(int & aiBinarySearchPredictionCounter, int & aiLinearSearchPredictionCounter, int & aiRandomSearchPredictionCounter)
{
	performBinarySearch();
	performLinearSearch();
	performRandomSearch();
	//set the referenced values to our local values...
	aiBinarySearchPredictionCounter = aiBinarySearchCounter;
	aiLinearSearchPredictionCounter = aiLinearSearchCounter;
	aiRandomSearchPredictionCounter = aiRandomSearchCounter;

	//now we return the referenced values back to main, so we can tell the user what the results were...
	return aiBinarySearchPredictionCounter, aiLinearSearchPredictionCounter, aiRandomSearchPredictionCounter;
}

// here we are performing the Binary Search...
void aiDrone::performBinarySearch()
{
	while (isAIBinaryTargetFound == false)
	{
		aiBinaryTargetLocationPrediction = ((binarySearchGridHighNumber - binarySearchGridLowNumber) / 2) + binarySearchGridLowNumber;
		aiBinarySearchCounter++;

		//tell user how large search grid bool is now, this changes for each guess.
		cout << "The current size of the gird to search is " << binarySearchGridLowNumber << " to " << binarySearchGridHighNumber << endl;
		//tell the user where the enemy location is predicted.
		cout << "Our prediction where the enemy is located is " << aiBinaryTargetLocationPrediction << endl;
		// radar ping of enemy location
		cout << "==================================================" << endl;
		cout << "Skynet HK-Aerial Radar performing search # " << aiBinarySearchCounter << endl;
		
		//if the ai prediction is greater than the actual enemy location...
		if (aiBinaryTargetLocationPrediction > enemyLocation)
		{
			//we set the grid high number to the prediction -1...
			binarySearchGridHighNumber = aiBinaryTargetLocationPrediction - 1;
			cout << "The target location prediction of " << aiBinaryTargetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
			cout << "The search grid low number remains the same at " << binarySearchGridLowNumber << endl;

		}

		//if the ai prediction is less than the actual enemy location...
		else if (aiBinaryTargetLocationPrediction < enemyLocation)
		{
			//set the grid low number to the prediction + 1...
			binarySearchGridLowNumber = aiBinaryTargetLocationPrediction + 1;
			cout << "The target location prediction of " << aiBinaryTargetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
			cout << "The new search grid low number = " << binarySearchGridLowNumber << endl;
			cout << "The search grid low number remains the same at " << binarySearchGridLowNumber << endl;
		}

		//if the ai prediction is the actual enemy location...
		else if (aiBinaryTargetLocationPrediction == enemyLocation)
		{
			cout << "Target is found!!!!!" << endl;
			cout << "Enemy was hiding and found at location # " << aiBinaryTargetLocationPrediction << endl;
			//set the target found flag to true...
			isAIBinaryTargetFound = true;
		}

		//if something wrong happened and we got an error...
		else
		{
			//something wrong
			cout << "something went wrong" << endl;
			isAIBinaryTargetFound = true;
		}
	}
}

// here we are performing the linear search...
void aiDrone::performLinearSearch()
{
	while (isAILinearTargetFound == false)
	{
		aiLinearTargetLocationPrediction++;
		aiLinearSearchCounter++;

		//tell user where enemy is hiding...
		cout << "The Enemy is hiding at location  " << enemyLocation << " on the grid." << endl;
		//tell user how large search grid bool is now, this changes for each guess.
		cout << "The current size of the grid to search left is " << linearSearchGridLowNumber << " to " << linearSearchGridHighNumber << endl;
		//tell the user where the enemy location is predicted.
		cout << "Our prediction where the enemy is located is at " << aiLinearTargetLocationPrediction << endl;
		// radar ping of enemy location
		cout << "==================================================" << endl;
		cout << "SkyNet HK-Aerial Radar performing search # " << aiLinearSearchCounter << endl;

		//if the ai prediction is greater than the actual enemy location...
		if (aiLinearTargetLocationPrediction > enemyLocation)
		{
			cout << "The target location prediction of " << aiLinearTargetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
		}

		//if the ai prediction is less than the actual enemy location...
		else if (aiLinearTargetLocationPrediction < enemyLocation)
		{
			cout << "The target location prediction of " << aiLinearTargetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
		}

		//if the ai prediction is the actual enemy location...
		else if (aiLinearTargetLocationPrediction == enemyLocation)
		{
			cout << "Target is found!!!!!" << endl;
			cout << "Enemy was hiding and found at location # " << aiLinearTargetLocationPrediction << endl;
			isAILinearTargetFound = true;

		}
		else
		{
			//something wrong
			cout << "something went wrong" << endl;
			isAILinearTargetFound = true;
		}
	}


}

// here we are performing the random search...
void aiDrone::performRandomSearch()
{
	while (isAIRandomTargetFound == false)
	{
		aiRandomTargetLocationPrediction = rand() % 64 + 1;
		//TODO add searched numbers to an array and make sure guessed number isnt in here.
		aiRandomSearchCounter++;

		cout << "Our prediction where the enemy is located is at " << aiRandomTargetLocationPrediction << endl;
		// radar ping of enemy location
		cout << "==================================================" << endl;
		cout << "SkyNet HK-Aerial Radar performing search #" << aiRandomSearchCounter << endl;

		//if the prediction is greater than the enemy location...
		if (aiRandomTargetLocationPrediction > enemyLocation)
		{
			cout << "The target location prediction of " << aiRandomTargetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
		}

		//if the prediction is less than enemy location...
		else if (aiRandomTargetLocationPrediction < enemyLocation)
		{
			cout << "The target location prediction of " << aiRandomTargetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
		}

		//this is the win scenario, prediction is the enemy location...
		else if (aiRandomTargetLocationPrediction == enemyLocation)
		{
			cout << "Target is found!!!!!" << endl;
			cout << "Enemy was hiding and found at location # " << aiRandomTargetLocationPrediction << endl;
			isAIRandomTargetFound = true;
		}

		//this is where something went wrong...
		else
		{
			//something wrong
			cout << "something went wrong" << endl;
			isAIRandomTargetFound = true;
		}
	}
}


