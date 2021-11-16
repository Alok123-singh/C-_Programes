#include <iostream>
#include <stdio.h>
#include <iomanip>

typedef int line;

int main()
{
	float a1=-1,a2=7;
	float a=(float)a1/a2,b=(float)7/1;
    float f=a*b;
    
    std::cout<<"Output : "<<std::fixed<<f<<std::endl;
    
	return(0);
}
