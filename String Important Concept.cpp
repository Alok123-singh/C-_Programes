#include <iostream>

using namespace std;

int main()
{
	string str1,str2;
	int i;
	
	cout<<"Enter String :\n";
	getline(cin,str1);
	
	for(i=0;i<str1.length();i++)
	    str2=str2+str1[i];
    
    cout<<endl<<"Output String :\n";
	cout<<str2<<endl;
	
	return(0);
}
