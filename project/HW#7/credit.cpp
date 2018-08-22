#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float rate;
int mos;

void Input(float &b, float &r, int &n);
void Interest(float &b, float r, int n, float &t);
void Output(float b, float t);

int main(int argc, char **argv)
{
	float balance, finalBalance, totalInterest;
	// input vaiables
        Input(balance, rate, mos);	
	
	//calculate interest
	Interest(balance, rate, mos, totalInterest);

	//print
	Output(balance, totalInterest);
return 0;
}
void Input(float &b, float &r, int &n)
{
	cout<<"Please enter initial balance: ";
	cin>>b;
	cout<<"Please enter the interest rate: ";
	cin>>r;
	cout<<"Please enter the number of months: ";
	cin>>n;
}
void Interest(float &b, float r, int n, float &t)
{
	float II;
	II=b;
	for (int i=0; i<n; i++)
	{
		b=b*(1+r);
	}
	t=b-II;
}
void Output(float f, float t)
{
	cout<<"Current balance is: $"
	<<setprecision(2)<<fixed<<f<<endl;
	cout<<"Interest earned is: $"
	<<setprecision(2)<<fixed<<t<<endl;
}
