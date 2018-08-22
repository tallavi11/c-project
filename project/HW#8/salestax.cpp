#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>

using namespace std;

float CalcSales(float );
float StateTaxAmount(float );
float CountyTaxAmount(float );
void Output(float, int);

int main(int argc, char **argv)
{
	float postTax;
	int month;	
	
	cout<<"Enter the number of the Month for which you want to know the taxes"<<endl;
	cin>>month;
	
	string filename="taxes.txt";
        fstream myfile;
        myfile.open(filename, fstream::in);
        char *line=(char *)malloc(30*sizeof(char));
	//text file can't have line larger than 30 characters
	for (int i=0; i<month; i++)
        {
		myfile.get(line, 30, '\n');
                int cursor=myfile.tellg();
                cursor++;
                myfile.seekg(cursor);
	}
	myfile.get(line, 30, ' ');
	postTax=stof (line);

	Output(postTax, month);
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
void Output(float total, int month)
{
    //s=sales, S=stateTax, C=countyTax
	float s, S, C;
    //Array made to be able to print out the Month
string mon[] = {"notAMonth", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //function calls to CalcSales(), StateTaxAmount() and CountyTaxAmount()
	s=CalcSales(total);
	S=StateTaxAmount(s);
	C=CountyTaxAmount(s);
    //print out these variables
	cout<<"\n";
	cout<<"\n";
	cout<<"Month: \t"<<setw(10)<<mon[month]<<endl;
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout<<"Total collected:		$ \t"<<fixed<<setprecision(2)<<total<<endl;
	cout<<"Sales:				$ \t"<<fixed<<setprecision(2)<<s<<endl;
	cout<<"County Sales Tax:		$ \t"<<fixed<<setprecision(2)<<C<<endl;
	cout<<"State Sales Tax:		$ \t"<<fixed<<setprecision(2)<<S<<endl;
	cout<<"Total Sales Tax:		$ \t"<<fixed<<setprecision(2)<<S+C<<endl;
}
