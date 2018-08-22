#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void Getword(string &w,string &g);
void InitializeBoard(char b[7][7]);
void PrintBoard(char b[7][7]);
bool Guess(char gletter, string &garray, int size);
void Redraw(char b[7][7]);
bool GameOver(string g);
void Print(string guess);
string word;
int misses, guesses;

int main(int argc, char** argv)
{
        string guess;
	Getword(word,guess);
	char board[7][7];
        InitializeBoard(board);
        PrintBoard(board);
        cout<<"\t"<<guess<<endl;
	misses=0;
        guesses=0;
        while (GameOver(guess)==false)
        {
		char letter;
                cout<<"Enter a letter guess: ";
                cin>>letter;
                Guess(letter, guess, word.size());
                Redraw(board);
                Print(guess);
                cout<<"misses="<<misses<<endl;
        }
        cout<<"The word was: ";
        Print(word);
return 0; 
}

void InitializeBoard(char b[7][7])
{
        for (int i=0; i<7; i++)
        {
                for (int j=0; j<7; j++)
                        b[i][j]=' ';
        }
        b[1][4]='|';
        for (int j=0; j<=4; j++)
                b[0][j]='-';
        for (int i=1; i<=6; i++)
                b[i][0]='|';
}
void PrintBoard(char b[7][7])
{
	for (int i=0; i<7; i++)
	{
		for (int j=0; j<7; j++)
		        cout<<b[i][j];
		cout<<endl;
	}
}

bool Guess(char gletter, string &garray, int size)
{
        bool flag=false;
        for (int i=0; i<size; i++)
        {
                if (gletter==word[i])
                {
                        garray[i]=gletter;
                        flag=true;
                        guesses++;
		}
	}
        if (flag==false)
                misses++;
return flag;
}

void Redraw(char b[7][7])
{
        switch (misses)
        {
        case 1:
                b[2][3]='(';
                b[2][5]=')';
                break;
        case 2:
                b[3][4]='|';
                b[4][4]='|';
                break;
        case 3:
                b[3][3]='/';
                break;
        case 4:
                b[3][5]='\\';
                break;
        case 5:
                b[5][3]='/';
        	break;
	case 6:
        	b[5][5]='\\';
        	break;
	case 7:
		b[2][4]='X';
		break;
	default:
        	break;
	}
	PrintBoard(b);
}

void Print(string guess)
{
        cout<<guess<<endl;
}

bool GameOver(string g)
{
        if (misses==7)
        {
                cout<<"You lose!"<<endl;
                return true;
        }
        else if (guesses==word.size())
        {
		cout<<"You win!"<<endl;
		return true;
        }
return false;
}

void Getword(string &w,string &g)
{
	string filename="words.txt";
	ifstream myfile;
	myfile.open(filename, ios::in);
	char *word= (char *)malloc(20*sizeof(char));
	srand(time(NULL));
	int num=rand()% 20;
	for (int i = 0;i<20;i++) 
	{
		myfile.get (word,20,'\n');
      		int cursor=myfile.tellg();
		cursor++;
		myfile.seekg(cursor);
		if (i == num)
        	{	
			w = string(word);
			int sw=w.size();
			g.insert(0,sw,'-');
		}
	}
	myfile.close();	
}
