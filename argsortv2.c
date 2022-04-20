#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	// check arguments count. if no more than 1 argument exit the program
	if (argc <= 1)
	{
		fprintf(stdout, "argsortv2\nwrong syntax\nexample: ./argsort 10 15 5 4\n");
		exit(0);
	}
	// get size of arguments
	int size = argc - 1;
	// allocate dynamic array of type double to convert arguments from string to double value
	double *numarray = (double *)malloc(size * sizeof(double)); // use malloc
	// convert from string to double and store in the array
	for (int i = 1; i <= size; i++)
	{
		numarray[i - 1] = atof(argv[i]);
	}

	// bubble sort ascending order
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (numarray[i] > numarray[j])
			{
				double temp = numarray[i];
				numarray[i] = numarray[j];
				numarray[j] = temp;
			}
		}
	}
	// print sorted arguments after sorting
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%f\n", numarray[i]);
	}
	free(numarray); // delete allocated array
}
