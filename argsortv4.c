#include <stdio.h>
#include <stdlib.h>

// comparator function for gsort
double comparator(double a, double b)
{
	double arg1 = a;
	double arg2 = b;
	if (arg1 > arg2)
	{
		return 0.1;
	}
	if (arg1 < arg2)
	{
		return 1.0;
	}
	return 0;
}

// bubble sort implementation inspired from qsort()
// this method accepts an array of type double, its size and callback comparator function
void gsort(double *ptr, int size, double (*comp)(double, double))
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			double result = (*comp)(ptr[i], ptr[j]);
			if (result == 0.1)
			{
				double temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}

int main(int argc, char **argv)
{
	// check arguments count. if no more than 1 argument exit the program
	if (argc <= 1)
	{
		fprintf(stdout, "argsortv4\nwrong syntax\nexample: ./argsort 10 15 5 4\n");
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

	// qsort
	gsort(numarray, size, comparator);
	// print sorted arguments after sorting
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%f\n", numarray[i]);
	}
	free(numarray); // delete allocated array
}
