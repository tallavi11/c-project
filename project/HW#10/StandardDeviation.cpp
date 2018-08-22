#include <iostream>
#include <math.h>

using namespace std;

// i'm assuming that the numbers are suppossed to be given as arguments from the commandline when starting the program, and for paramaters, there can not be more than 50 items in the array, and the number of array positions used is argc.


int main(int argc, char **argv)
{
	int used=argc-1;
	double numbers[used];
	double sum=0;
	for(int i=0;i<used;i++)
	{
		numbers[i] = strtod(argv[i+1], NULL);
		sum=sum+numbers[i];
	}
	double mean=sum/used;
	double totalsum=0;
	for(int i=0;i<used;i++)
	{
		double partsum=numbers[i]-mean;
		double partsum2= partsum*partsum;
		totalsum= totalsum + partsum2;
	}
	double total=totalsum/used;
	double StandDev= sqrt(total);
	cout<<StandDev<<endl;
	return 0;
}
