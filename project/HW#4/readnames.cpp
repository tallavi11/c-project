#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char **argv)
{
	string filename="names.txt";
	fstream myfile;
	myfile.open(filename, fstream::in);
	char *line=(char *)malloc(20*sizeof(char));
	while (myfile.eof()==false)
	{
		myfile.get(line, 20, '\n');
		cout<<line<<endl;
		int cursor=myfile.tellg();
		cursor++;
		if (myfile.eof()==false)
		{
			myfile.seekg(cursor);
		}
	}
	return 0;
}

