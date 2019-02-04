#pragma once


// number of target location predictions each player took to find enemy.
int aiBinarySearchTargetLocationPredictionCounter = 0;
int aiLinearSearchTargetLocationPredictionCounter = 0;
int aiRandomSearchTargetLocationPredictionCounter = 0;
int aiHumanSearchTargetLocationPredictionCounter = 0;

// is target found / destroyed
bool isAIBinarySearchTargetFound = false;
bool isAILinearSearchTargetFound = false;
bool isAIRandomSearchTargetFound = false;
bool isHumanSearchTargetFound = false;

//int vars to hold drone predictions
int aiBinarySearchTargetLocationPrediction = 0;
int aiLinearSearchTargetLocationPrediction = 0;
int aiRandomSearchTargetLocationPrediction = 0;
int humanSearchTargetLocationPrediction = 0;