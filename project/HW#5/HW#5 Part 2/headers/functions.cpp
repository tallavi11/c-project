#include <iostream>
#include "functions.h"

using namespace std;


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
        cout<<"Month: \t"<<month<<endl;
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
        cout<<"Total collected:         $ \t"<<total<<endl;
        cout<<"Sales:                   $ \t"<<s<<endl;
        cout<<"County Sales Tax:        $ \t"<<C<<endl;
        cout<<"State Sales Tax:         $ \t"<<S<<endl;
        cout<<"Total Sales Tax:         $ \t"<<S+C<<endl;
}
