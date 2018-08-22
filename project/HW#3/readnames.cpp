#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	string filename="names.txt";
	fstream myfile;
	myfile.open(filename, ios::in);
	if(myfile.is_open())
	{
		cout<<"File "<<filename<<" is open."<<endl;
	}
	else
	{
		cerr<<"Error: file "<<filename<<" could not be opened."<<endl;
		return 1;
	}
	cout<<"Reading data from the file..."<<endl;
	char *data=(char *)malloc(50*sizeof(char));
	
	for (int i=0; i<5; i++)
	{
		myfile>>data;
		cout<<data<<endl;
	}
	myfile.close();
	return 0;
}
