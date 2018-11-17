// Course:  CS213 - Programming II  - 2018
// Title:   Assignment III - Task 2 - Problem 6
// Program: Recursion_Problem_6
// Purpose: Check if a weight can be measured by a set of another weights on a 2 pan balance.
// Author:  Mark Samuel Shawki
// ID: 20170206
// Date:    17 November 2018
// Version: 1.0

#include <iostream>
#include <vector>

using namespace std;

bool isMeasurable(int target, vector<int> & weights);

int main()
{
	vector<int> sampleWeights;
	sampleWeights.push_back(1);
	sampleWeights.push_back(3);
	sampleWeights.push_back(5);
	sampleWeights.push_back(10);
	cout << isMeasurable(20, sampleWeights);
	return 0;
}

bool isMeasurable(int target, vector<int> & weights)
{
	int sum = 0;
	for (int i = 0; i < weights.size(); i++)
	{
		if (target == weights[i])
			return true;
		sum += weights[i];
	}
	for (int i = 0; i < weights.size(); i++)
	{
		if (target == (sum - weights[i]))
			return true;
	}
	if (target > sum || weights.size() == 0) // base case
		return false;
	else if (target == sum)
		return true;
	else
	{
		for (int i = 1; i < weights.size(); i++)
		{
			if (target == (weights[0] + weights[i]))
				return true;
		}
		vector<int> newWeights;
		for (int i = 1; i < weights.size(); i++) 
		{
			newWeights.push_back(weights[i]); 
		}
		// remove first item from the weights and put it on the left side by adding it to target
		// OR send the new weights again to check for the case of the (target == (weights[0] + weights[i]))
		// which is going to check the 2nd item and the all other items and each item and the third item with the other items and so on..
		return isMeasurable(target + weights[0], newWeights) || isMeasurable(target, newWeights);
	}
}