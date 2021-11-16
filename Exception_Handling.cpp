#include <iostream>
#include <stdbool.h>
using namespace std;

class MyException1:public exception // Parent Class or Base Class
{
	
};

class MyException2:public MyException1 // Child Class or Derived Class
{
	
};
/* 
 we can throw any type of data to catch block 
*/ 
int division(int a,int b) throw(MyException2) // throw() means the funtion does not throws anything 
{
	if(b==0)
	    throw MyException2(); // throw MyException1(); // throw string("Div By 0"); // throw 1.5f; // throw 1.5; // throw 1.5l;
	return (a/b);
}

int main()
{
	int x=10,y=0,z;
	
	try
	{
		z=division(x,y);
		cout<<z<<endl;
	}
	catch(int e)
	{
		cout<<"Division By Zero "<<e<<endl;
    }
    catch(float e)
    {
    	cout<<"Division By Zero "<<e<<endl;
	}
	catch(double e)
	{
		cout<<"Division By Zero "<<e<<endl;
	}
	catch(long double e)
	{
		cout<<"Division By Zero "<<e<<endl;
	}
    catch(char e)
    {
    	cout<<"Division By Zero "<<e<<endl;
	}
	catch(bool e)
	{
	    cout<<"Division By Zero "<<e<<endl;
	}
	catch(string e)
	{
		cout<<"Division By Zero "<<e<<endl;
	}
	catch(MyException2 e)  // Child Class Catch Block Must Be Before Parent Class Catch Block
	{
		cout<<"Division By Zero "<<endl;
	}
	catch(MyException1 e)
	{
		cout<<"Division By Zero "<<endl;
	}
	catch(...)
	{
		cout<<"Division By Zero .Catch All"<<endl;
	}
    
	return (0);
}

/* 
 try and catch is used when we want to communicate between two functions for exception handling otherwise within the same 
 function we can use if and else block also for exception handling.
*/


