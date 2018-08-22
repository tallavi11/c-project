#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	if (argc==1)	
	{
		cout<<"You need a second argument. \n"<<endl;
		return 1;
	}
	
	else if (argc>2)
	{
		cout<<"You can have only 2 arguments. \n"<<endl;
                return 1;
	}
	else
	{
		string number=argv[1];
		cout<<"you entered "<<number<<endl;
	}
return 0;
}
