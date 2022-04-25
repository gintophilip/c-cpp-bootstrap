#include <stdio.h>
#include <stdlib.h>
#include<string.h>
double *numarray;
//method to swap data
void swap(void* a,void* b,size_t size);
//method to print array after sorting
void printArray(int size){
			fprintf(stdout, "[ ");
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%.2f ",numarray[i]);

	}
			fprintf(stdout, "]\n");
}

// comparator function for gsort
double comparator(const void* a, const void* b){
	double arg1 = *(double*)a;
	double arg2 = *(double*)b;
	if (arg1 > arg2)
	{

		return 2.0;
	}
	if (arg1 < arg2)
	{
		return 1.0;
	}
	return 0;
}

// this method accepts an array of type double, count of elements, its size and callback comparator function
void gsort(void *ptr,size_t count, size_t size, double (*comp)(const void* , const void* ))
{
char *base=(char*)ptr; 
char *p1=base;
	for (int i = 0; i < count; i++)
	{
char *p2=p1+size;
		for (int j = i + 1; j < count; j++)
		{
			double result = (*comp)((void *)p1,(void *)p2);
			if (result == 2.0)
			{		
				swap(p1,p2,size);
			}
			p2+=size;
		}

			p1+=size;	
	}
}
void swap(void* a,void* b,size_t size){
	//swap values using memcpy
void* buffer=(void *)malloc(size); //allocate temporary buffer
				memcpy(buffer,a,size);
				memcpy(a,b,size);
				memcpy(b,buffer,size);
				free(buffer); //free buffer after swap
				
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
	//printf("size %d",size);
	// allocate dynamic array of type double to convert arguments from string to double value
	numarray = (double *)malloc(size * sizeof(double)); // use malloc
	// convert from string to double and store in the array
	for (int i = 1; i <= size; i++)
	{
		numarray[i - 1] = atof(argv[i]);
		//printf("numarray[%d]=%f\n",i-1,atof(argv[i]));
	}
	// gsort
	gsort(numarray,size, sizeof(double), comparator);
	// print sorted arguments after sorting
	printArray(size);
	free(numarray); // delete allocated array
}
