#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	char arr[] = "0123456789ABCDEF";

	// 1 - read input
	 int N;
	 cout<<"Please, enter a nmber to convert between 0 and 255: ";
	 cin>>N;
	
	if (0<= N && 255 >= N) {
		
		// 2 - calculate
		int left = int(N / 16);
		int right = (N - left * 16);
		
		// 3 - convert to hex
		char cleft = arr[left]; 
		char cright = arr [right];
				
		// 4 - print
		cout<<"The Hex value of " <<N<< " is " <<cleft<<cright<<"\n";
	} else {
		cout<<"Please retry with a valid number \n" ;
	}
return 0; 
}
