#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

float Inflation(float oldp, float nowp);
float oldprice, nowprice, newprice, counter, average;

int main(int argc, char **argv)
{
	float inflationrate;
	bool start;
	start=true;
	while (start==true)
	{
		counter=0;
		average=0;
		
		string filename="products.txt";
		ifstream myfile;
        	myfile.open(filename, ios::in);
		
		string outp="output.txt";
		ofstream outfile;
		outfile.open(outp);//, ios::out);
		
		char *line=(char *)malloc(100*sizeof(char));
		string item;
		outfile<<"Item    	Oldprice	Currentprice	Next Years Price \n";
		int cursor = 0;
		while (myfile.eof()==false)
        	{
        	        myfile.get(line, 100, ' ');
			if (myfile.eof()==true)
			{
				break;	
			}
			item = line;
			outfile<<item<<"		";
       	        	cursor=myfile.tellg();
       	        	cursor++;	
                	myfile.seekg(cursor);
			
			myfile.get(line, 100, ' ');
                        oldprice = stof(line);
                        outfile<<oldprice<<"		";
                        cursor=myfile.tellg();
                        cursor++;
                        myfile.seekg(cursor);
			
			myfile.get(line, 100, '\n');
                        nowprice = stof(line);
                        outfile<<line<<"		";
                        counter++;
			cursor=myfile.tellg();
                        cursor++;
                        myfile.seekg(cursor);
			newprice=Inflation(oldprice, nowprice);
			outfile<<fixed<<setprecision(2)<<newprice<<"\n";
		}
		average=(average/counter);
		outfile<<"the average inflationrate of all "<<setprecision(0)<<counter<<" items is: "<<fixed<<setprecision(1)<<average<<"%\n";
		myfile.close();
		outfile.close();
		cout<< "finished writing into file"<<endl;
		string answer;
		cout<<counter<<"\n";
		cout<<average<<"\n";
		cout<<"Do you wish to reread the file? (y or n)"<<endl;
		cin>>answer;
		if (answer=="y" || answer=="Y")
		{
			start=true;
		}
		else
		{
			start=false;
		}
	}
return 0;
}


float Inflation(float oldp, float nowp)
{
	float rate=((nowp-oldp)/oldp)*100;
	average=(average+rate);
	newprice=((rate/100)+1)*nowprice;
	return newprice;
}
