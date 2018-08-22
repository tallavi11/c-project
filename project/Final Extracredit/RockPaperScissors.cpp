#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
	bool cont=true;
	string Uturn;      // name of the user move
	string comline;    // name of the computer move
	string filename = "items.txt";  // input file name
	int comturn;       // value of computer move
	int Uval;          // value of user move
	
   	// core function logic
	while(cont==true)
	{
		ifstream myfile;
		myfile.open(filename, fstream::in);
		char *line=(char *)malloc(11*sizeof(char));
		cout<<"please type rock, paper, or scissors without any capitalization"<<endl;
		Uturn="undefined";
		cin>>Uturn;
		if(Uturn=="rock")
			Uval=0;
		if(Uturn=="scissors")
			Uval=1;
		if(Uturn=="paper")
			Uval=2;
		if (Uturn == "undefined")
			continue;
		int ran = rand() % 3;
		for(int i=0;i<3;i++)
		{
			myfile.get(line,11,'\n');
			int cursor=myfile.tellg();
			cursor++;
			myfile.seekg(cursor);
			if(i==ran)
				comline=line;
		}
		comturn=ran;
		cout<<"\n";
		cout<<"you played "<<Uturn<<" the computer played "<<comline<<endl;
		if(Uval<comturn && Uval+1==comturn)
			cout<<"you Win!"<<endl;
		if(comturn<Uval && comturn+1==Uval)
			cout<<"you Lose!"<<endl;
		if(Uval==comturn)
			cout<<"you Tie!"<<endl;
		if(Uval==2 && comturn==0)
			cout<<"you Win!"<<endl;
		if(comturn==2 && Uval==0)
			cout<<"you Lose!"<<endl;
		cout<<"do you wish to play again? (if yes then type 1, otherwise type 0)"<<endl;
		cin>>cont;
		myfile.close();
		}
return 0;
}
