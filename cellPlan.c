/*
	Cell Plan
	Kyle George
	1-15-2020
*/

#include <stdio.h>

//Calculate a rate given an amount of data and an amount of time.
double calculateRateOfUse(int days, int amount) {
	return (double)amount/(double)days;
}

//Executable Code
int main(void) {
	//Variable Definitions
	int totalGigs = 0; //Amount of data the user can use
	int currentDay = 0; //Number of days since the start of the period (1-30)
	int usedGigs = 0; //Amount of data already used
		
	//Gather Input from user
	printf("Enter Total GB in your plan: ");
	scanf("%d", &totalGigs);
	
	printf("Enter GB Used in since the start of the period: ");
	scanf("%d", &usedGigs);
	
	printf("Enter days since start of period: ");
	scanf("%d", &currentDay);
	
	//Calculate values used in program
	double usedRate = calculateRateOfUse(currentDay, usedGigs);
	double desiredRate = calculateRateOfUse(30, totalGigs);
	double changedRate = calculateRateOfUse(30 - currentDay, totalGigs-usedGigs);
	
	//Display to user. Display differs if the user's rate is above, at, or below what it should be.
	printf("\n%d days used. %d days remaining.\nAverage daily use %.2f GB/Day\n\n", currentDay, 30-currentDay, usedRate);
	if(usedRate > desiredRate) { //Execute if the user is using too much data.
		int excededData = usedRate * 30 - totalGigs; //Calculate the amount by which the user would excede the data cap.
	
		printf("You are EXCEDING your average daily use (%.2f).\n", desiredRate);
		printf("Continuing this usage, you'll exceed your data plan by %d GB.\n", excededData);
		printf("\n");
		printf("To stay below you data plan, use no more than %.2f GB/day.\n", changedRate);
	} 
	else if (usedRate < desiredRate) { //Execute if the user is using less data than available.
		int remainingData = totalGigs - usedRate * 30; //Calculate the amount of data the user will have at the end of period.
		
		printf("You are UNDER your average daily use (%.2f).\n", desiredRate);
		printf("Continuing this usage, you'll have %d GB extra data.\n", (int)(totalGigs-usedRate*30));
		printf("**Remaining data does not carry over into the next period.**\n");
		printf("\nYou may continue to use %.2f GB/day and remain under your limit.\n", changedRate);
	} 
	else { //Execute if the user is using exactly the correct amount of data.
		printf("You are EQUAL TO your average daily use (%.2f).\n", desiredRate);
		printf("Continuing at this usage, you will use all available data\n");
	}
		
	return 0;
}

/*
	Tested Data Sets
	Inputs: (Total = 15, Used = 13 Days = 10)
	Expected Outputs: (Avg Daily = 1.3, Excess GB = 24, Future Rate = 0.1)
	Outputs: (Avg Daily = 1.30, Excess GB = 24, Future Rate = 0.10)
	
	Inputs: (Total = 35, Used = 5, Days = 17)
	Expected Outputs: (Avg Daily = .29, Remaining GB = 26, Future Rate = 2.31)
	Outputs: (Avg Daily = .29, Remaining GB = 26, Future Rate = 2.31)
	
	Inputs: (Total = 10, Used = 5, Days = 15)
	Expected Outputs: (Avg Daily = .33, Remaining GB = 0, Future Rate = .33)
	Outputs: (Avg Daily = .33, Remaining GB = 0, Future Rate = .33)
	
	Test data sets were gathered via calculations done by my own calculator.
*/