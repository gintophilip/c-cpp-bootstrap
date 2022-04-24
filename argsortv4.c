#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// comparator function for gsort
double comparator(const void* a, const void* b){
	double arg1 = *(double*)a;
	double arg2 = *(double*)b;

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
void gsort(void *ptr,size_t count, size_t size, double (*comp)(const void* , const void* ))
{


	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			
			double result = (*comp)(&ptr[i],&ptr[j]);
			if (result == 0.1)
			{				 	
				swap(&ptr[i],&ptr[j],size);
			}
		}
	}
}
void swap(void* a,void* b,size_t size){
	printf("aa %f\n",*(double*)a);
		printf("aa %f\n",*(double*)b);
void* buffer=(void *)malloc(size);
				memcpy(buffer,a,size);
				memcpy(a,b,size);
				memcpy(b,buffer,size);
				free(buffer);
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
	gsort(numarray,size, sizeof(double), comparator);
	// print sorted arguments after sorting
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%f\n", numarray[i]);
	}
	free(numarray); // delete allocated array
}
