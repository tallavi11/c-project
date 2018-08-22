#include <iostream>

using namespace std;

void FillArray(char A[3][3]);
void DrawBoard (char A[3][3]);
void UserMove (char A[3][3], int user);
bool GameOver(char A[3][3],int user);
int turn=0;

int main(int argc, char **argv)
{
    char Array[3][3];
    FillArray(Array);
    DrawBoard(Array);
	while (GameOver(Array, turn%2)==false)
	{
         	UserMove(Array, turn%2);
         	DrawBoard(Array);
		turn++;
	} 
return 0;
}

void FillArray(char A[3][3])
{
    for (int i=0; i<3; i++)
    {
         for (int j=0; j<3; j++)
         A[i][j]='*';
    }
}

void DrawBoard (char A[3][3])
{
    for (int i=0; i<3; i++)
    {
         cout<<" --- --- --- \n";
         for (int j=0; j<3; j++)
             cout<<"| "<<A[i][j]<<" ";
         cout<<"|\n";
    }
    cout<<" --- --- --- \n";
}

void UserMove (char A[3][3], int user)
{
        int X, Y;
        cout<<"Where would you like to place your character?"<<endl;
        cin>>Y>>X;
        X--;
	Y--;
	if (A[X][Y]!='*')
	{
	cerr<<"This point already has a value, try another one.\n";
	turn--;
	}
	else
	{
		if (user==0)
        	A[X][Y]='X';
		else
		A[X][Y]='O';
	}
}

bool GameOver(char A[3][3], int user)
{
    	bool flag;
    	for (int i=0; i<3; i++)
        {
        	if (A[i][0]==A[i][1] && A[i][2]==A[i][1] && A[i][0]!='*')
        	{
        		if (user==0)
			cout<<"User A wins!"<<endl;
			else if (user==1)
    			cout<<"User B wins!"<<endl;
			flag=true;
		} 
	}
	for (int j=0; j<3; j++)
	{
    		if ((A[0][j]==A[1][j]) && (A[2][j]==A[1][j]) && (A[0][j]!='*'))
    		{
         		if (user==0)
             		cout<<"User A wins!"<<endl;
         		else if (user==1)
    			cout<<"User B wins!"<<endl;
			flag=true;
		} 
	}
    	if ((((A[0][0]==A[1][1]) && (A[1][1]==A[2][2])) || ((A[0][2]==A[1][1]) && (A[1][1]==A[2][0]))) && (A[1][1]!='*'))
    	{
        	if (user==0)
             	cout<<"User O wins!"<<endl;
         	else if (user==1)
             	cout<<"User X wins!"<<endl;
         	flag = true;
	}
	if (turn==9 && flag==false)
	{
		cout<<" The Board is full and nobody wins so it is a tie.\n";
		flag=true;
	}
return flag;
}
