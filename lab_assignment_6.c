#include <stdio.h>
#include <stdlib.h>

/*Write an efficient recursive function that takes in a sorted array of numbers, two integers, low and high,
representing indexes into the array, and another integer, value, and returns the index in the array where
value is found in the array in between index low and high, inclusive. If value is NOT found in the array in
between indexes low and high, inclusive, then the function should return -1*/

int search(int numbers[], int low, int high, int value) {
	if (low > high)
		return -1; //incase someone thinks 1 is more than 2.
	int mid = (low+high)/2; //for the value between low and high

	if(value<numbers[mid])//case value is lower than mid
		return search(numbers, low, mid-1, value);//mid become new high, mid is recalculated, search is called again
	else if(value>numbers[mid])//case value is higher than mid
		return search(numbers, mid+1, high, value);//mid becomes new low, mide is recalculated, search is called again
	else
		return mid;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}