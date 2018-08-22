#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

float CalcSales(float );
float StateTaxAmount(float );
float CountyTaxAmount(float );
void Output(float );

int main(int argc, char **argv)
{
	float postTax;
	cout<<"Enter the post-tax amount: ";
	cin>>postTax;
	Output(postTax);
	return 0;
}
float CalcSales(float total)
{
    //declare the return variable
	float sales;
	sales=total/1.06;
	return sales;
}
float StateTaxAmount(float sales)
{
    //declare the return variable
	float stateTax;
	stateTax=sales*0.04;
return stateTax;
}

float CountyTaxAmount(float sales)
{
    //declare the return variable
	float countyTax;
	countyTax=sales*0.02;
	return countyTax;
}
void Output(float total)
{
    // s=sales, S=stateTax, C=countyTax
	float s, S, C;
	string month;
	cout<<"Now enter the Month: ";
	cin>>month;
    //function calls to CalcSales(), StateTaxAmount() and CountyTaxAmount()
	s=CalcSales(total);
	S=StateTaxAmount(s);
	C=CountyTaxAmount(s);
    //print out these variables
	cout<<"\n";
	cout<<"\n";
	cout<<"Month: \t"<<setw(10)<<month<<endl;
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout<<"Total collected:		$ \t"<<setw(5)<<total<<endl;
	cout<<"Sales:				$ \t"<<setw(5)<<s<<endl;
	cout<<"County Sales Tax:		$ \t"<<setw(5)<<C<<endl;
	cout<<"State Sales Tax:		$ \t"<<setw(5)<<S<<endl;
	cout<<"Total Sales Tax:		$ \t"<<setw(5)<<S+C<<endl;
}
