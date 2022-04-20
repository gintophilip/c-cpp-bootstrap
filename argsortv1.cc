#include <iostream>

int main(int argc, char **argv)
{
	using namespace std;
	// check arguments count. if no ore than 1 argument exit the program
	if (argc <= 1)
	{
		cout << "argsortv1\nwrong syntax\nexample: ./argsort 10 15 5 4\n";
		exit(0);
	}
	// get size of arguments
	int size = argc - 1;
	// allocate dynamic array of type double to convert arguments from string to double value
	double *numarray = new double[size];
	// convert from string to double and store in the array
	for (int i = 0; i < size; i++)
	{
		numarray[i] = atof(argv[i + 1]);
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
		cout << numarray[i] << "\n";
	}
	delete[] numarray; // delete allocaed array
}
