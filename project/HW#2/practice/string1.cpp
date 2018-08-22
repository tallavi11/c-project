#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    string firstName, lastName;
    cout<<"Please, enter your name: ";
    cin>>firstName>>lastName;

    cout<<"You entered "<<firstName<<" "<<lastName<<"."<<endl;
    cout<<"The length of "<<firstName<<" is "<<firstName.length()<<" characters."<<endl;
return 0; 
}
