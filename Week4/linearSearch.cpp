// *********************************************** start linear ai search here **************************************************************************
while (isAILinearSearchTargetFound == false)
{
	aiLinearSearchTargetLocationPrediction++;
	aiLinearSearchTargetLocationPredictionCounter++;

	//tell user where enemy is hiding...
	cout << "The Enemy is hiding at location  " << enemyLocation << " on the grid." << endl;
	//tell user how large search grid bool is now, this changes for each guess.
	cout << "The current size of the grid to search left is " << linearSearchAISearchGridLowNumber << " to " << linearSearchAISearchGridHighNumber << endl;
	//tell the user where the enemy location is predicted.
	cout << "Our prediction where the enemy is located is at " << aiLinearSearchTargetLocationPrediction << endl;

	// radar ping of enemy location
	cout << "==================================================" << endl;

	cout << "SkyNet HK-Aerial Radar Sending out ping # " << aiLinearSearchTargetLocationPredictionCounter << endl;

	if (aiLinearSearchTargetLocationPrediction > enemyLocation)
	{
		cout << "the target location prediction of " << aiLinearSearchTargetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
	}
	else if (aiLinearSearchTargetLocationPrediction < enemyLocation)
	{
		cout << "the target location prediction of " << aiLinearSearchTargetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
	}
	else if (aiLinearSearchTargetLocationPrediction == enemyLocation)
	{
		cout << "Target is found!!!!!" << endl;
		cout << "Enemy was hiding at location # " << enemyLocation << endl;
		cout << "Target was found at location # " << aiLinearSearchTargetLocationPrediction << endl;
		cout << "SkyNet HK-Aerial Linear Search software took " << aiLinearSearchTargetLocationPredictionCounter << endl;
		isAILinearSearchTargetFound = true;

	}
	else
	{
		//something wrong
		cout << "something went wrong" << endl;
		isAILinearSearchTargetFound = true;
	}
}