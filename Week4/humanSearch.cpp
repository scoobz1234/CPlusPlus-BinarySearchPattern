// *********************************************** start Human search here **************************************************************************
while (isHumanSearchTargetFound == false)
{

	cout << "\nPlease type in your target location guess: ";
	cin >> humanSearchTargetLocationPrediction;

	aiHumanSearchTargetLocationPredictionCounter++;


	cout << "\nOur prediction where the enemy is located is at " << humanSearchTargetLocationPrediction << endl;

	// radar ping of enemy location
	cout << "==================================================" << endl;
	cout << "Skynet HK-Aerial Radar Sending out ping # " << aiHumanSearchTargetLocationPredictionCounter << endl;

	//if the prediction is greater than the enemy location...
	if (humanSearchTargetLocationPrediction > enemyLocation)
	{
		cout << "the target location prediction of " << humanSearchTargetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
	}
	//if the prediction is less than enemy location...
	else if (humanSearchTargetLocationPrediction < enemyLocation)
	{
		cout << "the target location prediction of " << humanSearchTargetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
	}
	//this is the win scenario, prediction is the enemy location...
	else if (humanSearchTargetLocationPrediction == enemyLocation)
	{
		cout << "target is found!!!!!" << endl;
		cout << "Enemy was hiding at location # " << enemyLocation << endl;
		cout << "Target was found at location # " << humanSearchTargetLocationPrediction << endl;
		cout << "SkyNet hk-aerial Human Search software took " << aiHumanSearchTargetLocationPredictionCounter << endl;
		isHumanSearchTargetFound = true;

	}
	else
	{
		//something wrong
		cout << "something went wrong" << endl;
		isHumanSearchTargetFound = true;
	}
}