#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class Car
{
public:
    virtual void setname(string name)=0;
    virtual void setprice(float price)=0;
    virtual void setmodel(string model)=0;
    virtual string getname()=0;
    virtual float getprice()=0;
    virtual string getmodel()=0;
};

class i20:public Car
{
private:
    string name;
    float price;
    string model;
    static int i;
    
public:
    i20();
    i20(string name,float price,string model);
    i20(i20 &i);
    void setname(string name);
    void setprice(float price);
    void setmodel(string model);
    string getname();
    float getprice();
    string getmodel();
    void upgrade();
    ~i20();
};

int i20::i=1;

class Ferari:public Car
{
private:
    string name;
    float price;
    string model;
    static int f;
    
public:
    Ferari();
    Ferari(string name,float price,string model);
    Ferari(Ferari &f);
    void setname(string name);
    void setprice(float price);
    void setmodel(string model);
    string getname();
    float getprice();
    string getmodel();
    void upgrade();
    ~Ferari();
};

int Ferari::f=1;

class Polo:public Car
{
private:
    string name;
    float price;
    string model;
    static int p;
    
public:
    Polo();
    Polo(string name,float price,string model);
    Polo(Polo &p);
    void setname(string name);
    void setprice(float price);
    void setmodel(string model);
    string getname();
    float getprice();
    string getmodel();
    void upgrade();
    ~Polo();
};

int Polo::p=1;

class Creta:public Car
{
private:
    string name;
    float price;
    string model;
    static int c;
    
public:
    Creta();
    Creta(string name,float price,string model);
    Creta(Creta &c);
    void setname(string name);
    void setprice(float price);
    void setmodel(string model);
    string getname();
    float getprice();
    string getmodel();
    void upgrade();
    ~Creta();
};

int Creta::c=1;

class Garage
{
public:
    i20 *I20=NULL;
    Ferari *ferari=NULL;
    Polo *polo=NULL;
    Creta *creta=NULL;

    Garage();
    Garage(int i1,int i2,int i3,int i4);
    Garage(Garage &g);
    void setsizei20(int size);
    void setsizeFerari(int size);
    void setsizePolo(int size);
    void setsizeCreta(int size);
    ~Garage();
};

long long money=50000;
int i=1,j=1,k=1,l=1;
/*
void Delay() throw()
{
    for(int i1=1;i1<INT_MAX/12;i1++);
}

void SDelay() throw()
{
	for(int i_1=1;i_1<INT_MAX/40;i_1++);
}

void RDelay() throw()
{
	for(int i1=1;i1<INT_MAX/30;i1++);
}
*/
void DisplayRacingManual()
{
    cout<<"\nGathering Information . . .\n";
	printf("\n%38c",'[');
	for(int j1=0;j1<40;j1++)
	{
		printf("*");
		if(j1==39) printf("]");					
		Sleep(150);
		//SDelay();
	}
	Sleep(150);
	cout<<endl;
	
	cout<<"\nRacing Manual :\n";
    cout<<"-------------------------------------------------------";
    cout<<"\n"<<"                                        Money: "<<money<<endl;
    cout<<"Manual For Racing :\n\n";
    cout<<"1000 Rupees Required To Race If You Choose A i20    Car\n";
    cout<<"1500 Rupees Required To Race If You Choose A Ferari Car\n";
    cout<<"1700 Rupees Required To Race If You Choose A Polo   Car\n";
    cout<<"1950 Rupees Required To Race If You Choose A Creta  Car";
    cout<<"\n\n-------------------------------------------------------\n";
}

int Racing()
{
    string name;
	int x=0,y=-1;
    int money1=30000;
    int i2;
    char ch;
    
    cout<<"\nRacing Process :\n";
    cout<<"-------------------------------------------------------\n\n";
    
    cout<<"Do You Want To See Racing Manual ?\n";
    cout<<"Enter Y For Yes And N For No\n";
    cin>>ch;
    
    if(ch=='Y')
    {
        DisplayRacingManual();
        cout<<"\nDo You Want To Go Furthur ?\n";
        cout<<"Enter Y For Yes And N For No :\n";
        cin>>ch;
        if(ch=='N')
            return 2;
    }
    
    cout<<"\nWhich Car Do You Want To Choose In Racing ?\n";
    cin>>name;
    
    if(name=="i20")
    {
        if(money<1000)
        {
            cout<<"\nYou Do Not Have Enough Money To Race\n";
            return 2;
        }
        
        money=money-1000;
    }
    
    else if(name=="Ferari")
    {
        if(money<1500)
        {
            cout<<"\nYou Do Not Have Enough Money To Race\n";
            return 2;
        }
        
        money-=1500;
    }
    
    else if(name=="Polo")
    {
        if(money<1700)
        {
            cout<<"\nYou Do Not Have Enough Money To Race\n";
            return 2;
        }
        
        money-=1700;
    }
    
    else if(name=="Creta")
    {
        if(money<1950)
        {
            cout<<"\nYou Do Not Have Enough Money To Race\n";
            return 2;
        }
        
        money-=1950;
    }
    
    cout<<"\nPlease Wait. Racing Is Being Done...\n";
    
    srand(time(NULL));
	
	if(name=="i20")
	{
	    for(i2=0;i2<3;i2++)
	        x=rand() % 4 + 1;
    }
    
    else if(name=="Polo")
    {
    	for(i2=0;i2<3;i2++)
    	    x=rand() % 3 + 1;
	}
    
    else if(name=="Creta")
    {
    	for(i2=0;i2<2;i2++)
    	    x=rand() % 4 + 2;
	}
    
    else if(name=="Ferari")
    {
    	for(i2=0;i2<1;i2++)
    	    x=rand() % 2 + 1;
	}
    
	if(name=="i20")
	{
		if(x==1)
		{
		    y=1;
		    money+=money1;
		}
		else
		    y=0;
	}
	
	else if(name=="Ferari")
	{
		if(x==2)
		{
		    y=1;
		    money+=money1;
	    }
		else
		    y=0;
	}
    
    else if(name=="Polo")
    {
    	if(x==3)
    	{
    	    y=1;
    	    money=money+money1;
        }
		else
    	    y=0;
	}
	
	else if(name=="Creta")
	{
		if(x==4)
		{
		    y=1;
		    money+=money1;
        }
		else
		    y=0;
	}
	
	printf("\n%20c",'[');
	for(int i1=0;i1<79;i1++)
	{
		printf("*"); 
		if(i1==78)
			printf("]");					
		Sleep(200);
	}
	cout<<endl;
	
	return(y);
}

void SpinWheel()
{
    int money1=0;
    
    cout<<"\nSpinning Process :\n";
    cout<<"-------------------------------------------------------\n\n";
    
    cout<<"Please Wait. Spinning Is Being Done...\n";
    
    printf("\n%38c",'[');
	for(int i1=0;i1<40;i1++)
	{
		printf("*");
		if(i1==39)
			printf("]");					
		Sleep(300);
	}
    cout<<endl;
	
    srand(time(NULL));
    
    for(int i=1;i<5;i++)
        money1=rand() % 40000 + 101;
    
    Sleep(200);
    cout<<"\nThe Amount Of Money You Have Won Is : "<<money1<<" Rupees"<<endl;
    
    cout<<"\n-------------------------------------------------------\n";
    money+=money1;
    
}

void DisplayGarage(Garage &g)
{
    cout<<"\nGathering Information . . .\n\n\n\n\n\n\n\n\n\n\n";
	printf("\n%38c",'[');
	for(int j1=0;j1<40;j1++)
	{
		printf("*");
		if(j1==39)
			printf("]");					
		Sleep(150);
	}
	Sleep(150);
	system("CLS");
	
	cout<<"\nGarage :\n";
    cout<<"-------------------------------------------------------\n\n";
    
    cout<<"Total Money In Your Account Is : "<<money<<" Rupees"<<endl<<endl;
    
    cout<<"Total Number Of i20    Cars : "<<i<<endl;
    cout<<"Total Number Of Ferari Cars : "<<j<<endl;
    cout<<"Total Number Of Polo   Cars : "<<k<<endl;
    cout<<"Total Number Pf Creta  Cars : "<<l<<endl<<endl;
    
    cout<<"Information About i20 Cars :\n";
    cout<<"Model : "<<g.I20->getmodel()<<endl;
    cout<<"Price : "<<g.I20->getprice()<<endl<<endl;
    
    cout<<"Information About Ferari Cars :\n";
    cout<<"Model : "<<g.ferari->getmodel()<<endl;
    cout<<"Price : "<<g.ferari->getprice()<<endl<<endl;
    
    cout<<"Information About Polo Cars :\n";
    cout<<"Model : "<<g.polo->getmodel()<<endl;
    cout<<"Price : "<<g.polo->getprice()<<endl<<endl;
    
    cout<<"Information About Creta Cars :\n";
    cout<<"Model : "<<g.creta->getmodel()<<endl;
    cout<<"Price : "<<g.creta->getprice()<<endl<<endl;
    
    cout<<"-------------------------------------------------------\n";
}

void DisplayUpgradeManual()
{
    cout<<"\nGathering Information . . .\n";
	printf("\n%38c",'[');
	for(int j1=0;j1<40;j1++)
	{
		printf("*");
		if(j1==39)
			printf("]");					
		Sleep(150);
	}
	Sleep(150);
	cout<<endl;
	
	cout<<"\nUpgradation Manual : \n";
    cout<<"-------------------------------------------------------";
    cout<<"\n"<<"                                        Money: "<<money<<endl;
    cout<<"Manual For Survicing :\n\n";
    cout<<"1: 10,000 Rupess Are Required To Upgrade 1 i20    Car\n";
    cout<<"2: 17,000 Rupees Are Required To Upgrade 1 Ferari Car\n";
    cout<<"3: 21,000 Rupees Are Required To Upgrade 1 Polo   Car\n";
    cout<<"4: 26,500 Rupess Are Required To Upgrade 1 Creta  Car";
    cout<<"\n\n-------------------------------------------------------\n";
}

void Upgrade(Garage &g)
{
    string name;
    char ch;
    
    cout<<"\nUpgradation Process :\n";
    cout<<"-------------------------------------------------------\n\n";
    
    cout<<"Do You Want To See The Upgradation Manual ?\n";
    cout<<"Enter Y For Yes And N For No\n";
    cin>>ch;
    
    if(ch=='Y')
    {
        DisplayUpgradeManual();
        cout<<"\nDo You Want To Go Furthur ?\n";
        cout<<"Enter Y For Yes And N For No :\n";
        cin>>ch;
        
        if(ch=='N')
        {
            cout<<"\n\n-------------------------------------------------------\n";
			return;
        }
    }
        
    cout<<"\nWhich Car Do You Want To Upgrade ?\n";
    cin>>name;
            
    if(name=="i20")
    {
        if(money<10000*i)
        {
            cout<<"\nNot Enough Money. ";
            cout<<"You Require "<<10000*i-money<<" Rupees More To Repair All i20 Cars\n";
        }
            
        else
        {
            cout<<"\nPlease Wait. i20 Cars Are Upgrading...\n";
            g.I20->upgrade();
            printf("\n%38c",'[');
	        for(int i1=0;i1<40;i1++)
	        {
		        printf("*");
		        if(i1==39)
			        printf("]");					
	        	Sleep(300);
	        }
        }
    }
    
    else if(name=="Ferari")
    {
        if(money<17000*j)
        {
            cout<<"\nNot Enough Money. ";
            cout<<"You Require "<<17000*i-money<<" Rupees More To Repair All Ferari Cars\n";
        }
            
        else
        {
            cout<<"\nPlease Wait. Ferari Cars Are Upgrading...\n";
            g.ferari->upgrade();
            printf("\n%38c",'[');
			for(int i2=0;i2<40;i2++)
	        {
		        printf("*");
		        if(i2==39)
			        printf("]");					
	        	Sleep(300);
	        }
        }
    }
    
    else if(name=="Polo")
    {
        if(money<21000*k)
        {
            cout<<"\nNot Enough Money. ";
            cout<<"You Require "<<21000*i-money<<" Rupees More To Repair All Polo Cars\n";
        }
            
        else
        {
            cout<<"\nPlease Wait. Polo Cars Are Upgrading...\n";
            g.polo->upgrade();
            printf("\n%38c",'[');
            for(int i3=0;i3<40;i3++)
	        {
		        printf("*");
		        if(i3==39)
			        printf("]");					
	        	Sleep(300);
	        }
        }
    }
    
    else if(name=="Creta")
    {
        if(money<26000*l)
        {
            cout<<"\nNot Enough Money. ";
            cout<<"You Require "<<26000*i-money<<" Rupees More To Repair All Creta Cars\n";
        }
    
        else
        {
            cout<<"\nPlease Wait. Creta Cars Are Upgrading...\n";
            g.creta->upgrade();
            printf("\n%38c",'[');
            for(int i4=0;i4<40;i4++)
	        {
		        printf("*");
		        if(i4==39)
			        printf("]");					
	        	Sleep(300);
	        }
        }
    }
    cout<<"\nUpgradation Completed\n";
    cout<<"\n-------------------------------------------------------\n";
}

void DisplayBuyManual()
{
    cout<<"\nGathering Information . . .\n";
	printf("\n%38c",'[');
	for(int j1=0;j1<40;j1++)
	{
		printf("*");
		if(j1==39)
			printf("]");					
		Sleep(150);
	}
	Sleep(150);
	cout<<endl;
	
	cout<<"\nCar Showroom Prices :\n";
    cout<<"-------------------------------------------------------";
    cout<<"\n"<<"                                        Money: "<<money<<endl;
    cout<<"Car Price Manual Is As Follows :\n\n";
    cout<<"1: 30,000 Rupees Required To Buy 1 i20 \n";
    cout<<"2: 54,000 Rupees Required To Buy 1 Ferari\n";
    cout<<"3: 75,000 Rupees Required To Buy 1 Polo\n";
    cout<<"4: 90,000 Rupees Required To Buy 1 Creta";
    cout<<"\n\n-------------------------------------------------------\n";
}

void BuyCars(Garage &g)
{
    char ch;
    int count1,count2,count3,count4;
    
    cout<<"\nBuying Car :\n";
    cout<<"-------------------------------------------------------\n\n";
    
    cout<<"\nDo You Want To See The Car Price Manual ?\n";
    cout<<"Enter Y For Yes And N For No\n";
    cin>>ch;
    
    if(ch=='Y')
    {
        DisplayBuyManual();
        cout<<"\nDo You Want To Go Furthur ?\n";
        cout<<"Enter Y For Yes And N For No :\n";
        cin>>ch;
        if(ch=='N')
        {
            cout<<"\n-------------------------------------------------------\n";
			return;
        }
    }
        
    cout<<"\nGive The Report Of Buying Cars In Showroom :\n\n";
    cout<<"Number Of i20 Cars :\n";
    cin>>count1;
    
    cout<<"\nNumber Of Ferari Cars :\n";
    cin>>count2;
    
    cout<<"\nNumber Of Polo Cars :\n";
    cin>>count3;
    
    cout<<"\nNumber Of Creta Cars :\n";
    cin>>count4;
     
    if(count1*g.I20->getprice()>money)
        cout<<"\nYou Can Not Buy "<<count1<<" i20 Cars\n";
    
    else if(count1!=0)
    {
        for(int i11=0;i11<count1;i11++)
        {
            i20 i1;
            *(g.I20+i11)=i1;
        }
        
        cout<<"\nPlease Wait. Registration Process Of i20 Cars Is Being Done...\n";
        i+=count1;
        money=money-count1*g.I20->getprice();
        printf("\n%38c",'[');
        for(int i1=0;i1<40;i1++)
	    {
		    printf("*");
		    if(i1==39)
			printf("]");					
	        Sleep(300);
	    }
	    cout<<endl;
    }
    
    if(count2*g.ferari->getprice()>money)
        cout<<"\nYou Can Not Buy "<<count2<<" Ferari Cars\n";
    
    else if(count2!=0)
    {
        for(int j11=0;j11<count2;j11++)
        {
            Ferari f1;
            *(g.ferari+j11)=f1;
        }
        
        cout<<"\nPlease Wait. Registration Process Of Ferari Cars Is Being Done...\n";
        j+=count2;
        money=money-count2*g.ferari->getprice();
        printf("\n%38c",'[');
		for(int i2=0;i2<40;i2++)
	    {
		    printf("*");
		    if(i2==39)
			    printf("]");					
	        Sleep(300);
	    }
	    cout<<endl;
    }
    
    if(count3*g.polo->getprice()>money)
        cout<<"\nYou Can Not Buy "<<count3<<" Polo Cars\n";
    
    else if(count3!=0)
    {
        for(int k11=0;k11<count3;k11++)
        {
            Polo p1;
            *(g.polo+k)=p1;
        }
        
        
        cout<<"\nPlease Wait. Registration Process Of Polo Cars Is Being Done...\n";
        k+=count3;
        money-=count3*g.polo->getprice();
        printf("\n%38c",'[');
        for(int i3=0;i3<40;i3++)
	    {
		    printf("*");
		    if(i3==39)
			    printf("]");					
	        Sleep(300);
	    }
	    cout<<endl;
    }
    
    if(count4*g.creta->getprice()>money)
        cout<<"\nYou Can Not Buy "<<count4<<" Creta Cars\n";
    
    else if(count4!=0)
    {
        for(int l11=0;l11<count4;l11++)
        {
            Creta c1;
            *(g.creta+l11)=c1;
        }
        
        cout<<"\nPlease Wait. Registration Process Of Creta Cars Is Being Done...\n";
        l+=count4;
        money-=count4*g.creta->getprice();
        printf("\n%38c",'[');
        for(int i4=0;i4<40;i4++)
	    {
		    printf("*");
		    if(i4==39)
			    printf("]");					
	        Sleep(300);
	    }
	    cout<<endl;
    }
    cout<<"\n-------------------------------------------------------\n";
}

void DisplayMoney()
{
    cout<<"\nGathering Information . . .\n\n\n\n\n\n\n\n\n\n\n";
	printf("\n%38c",'[');
	for(int j1=0;j1<40;j1++)
	{
		printf("*");
		if(j1==39)
			printf("]");					
		Sleep(100);
	}
	Sleep(100);
	system("CLS");
	
	cout<<"\nBank :\n";
    cout<<"--------------------------------------\n\n";
    cout<<"Money In Your Account Is Rupees "<<money;
    cout<<"\n\n--------------------------------------\n";
}

int main()
{
    int x;
	Garage g1;
    
    while(1)
    {
        cout<<"**\t\t\tWelcome\t\t\t**\n\n";
        cout<<"-----------------------------------------------------------\n\n";
        cout<<"Notice : This Game Works On Prediction.\n\n";
		
		cout<<"\nStart Menu :"<<"                                 Money: "<<money;
        cout<<"\n-----------------------------------------------------------\n\n";
        cout<<"1: Racing Of Cars\n";
        cout<<"2: Upgrade A Specific Type Of Car At A Time\n";
        cout<<"3: Spin Wheel Of Money\n";
        cout<<"4: Buy Cars\n";
        cout<<"5: Garage\n";
        cout<<"6: Bank\n";
        cout<<"7: Quit Game";
        cout<<"\n\n-----------------------------------------------------------\n";
        cout<<"\nWhat Do You Want To Do ?\n";
        cin>>x;
    
        switch(x)
        {
            case 1:
            {
                int z;
                
                system("CLS"); // For Clearing The Screen
                cout<<"Cars Available In This Game Are As Follows :\n";
                cout<<"1: i20\n";
                cout<<"2: Ferari\n";
                cout<<"3: Polo\n";
                cout<<"4: Creta\n\n";
				z=Racing();
                
                if(z==1)
                    cout<<"\nYou Won 30,000 Rs In This Race. Money Has Been Transferred In Your Account\n";
                else if(z==0)
                    cout<<"\nYou Lose The Race!\n";
                
                cout<<"\n-------------------------------------------------------\n";
                
                cout<<"Press Any Key To Continue . . . ";
                getch();
                system("CLS"); // For Clearing The Screen
                
                break;
            }
            
            case 2:
            {
                system("CLS"); // For Clearing The Screen
				cout<<"Cars Available In This Game Are As Follows :\n";
                cout<<"1: i20\n";
                cout<<"2: Ferari\n";
                cout<<"3: Polo\n";
                cout<<"4: Creta\n\n";
				Upgrade(g1);
				
				cout<<"Press Any Key To Continue . . . ";
                getch();
                system("CLS"); // For Clearing The Screen
                break;
            }
                
            case 3:
            {
                system("CLS"); // For Clearing The Screen
				SpinWheel();
                
				cout<<"Press Any Key To Continue . . . ";
                getch();
                system("CLS"); // For Clearing The Screen
				break;
            }
                
            case 4:
            {
                system("CLS"); // For Clearing The Screen
				cout<<"Cars Available In This Game Are As Follows :\n";
                cout<<"1: i20\n";
                cout<<"2: Ferari\n";
                cout<<"3: Polo\n";
                cout<<"4: Creta\n\n";
				BuyCars(g1);
                
				cout<<"Press Any Key To Continue . . . ";
                getch();
                system("CLS"); // For Clearing The Screen
				break;
            }
                
            case 5:
            {
                system("CLS"); // For Clearing The Screen
				DisplayGarage(g1);
                
				cout<<"Press Any Key To Continue . . . ";
                getch();
                system("CLS"); // For Clearing The Screen
				break;
            }
                
            case 6:
            {
                system("CLS"); // For Clearing The Screen
				DisplayMoney();
                
				cout<<"Press Any Key To Continue . . . ";
                getch();
                system("CLS"); // For Clearing The Screen
				break;
            }
              
            case 7:
            {
			    char ch;
			    cout<<"\nAre You Sure You Want To Quit The Game? Enter Y For Yes And N For No :\n";
			    cin>>ch;
			    if(ch=='Y')
			        exit(0);
			    system("CLS"); // For Clearing The Screen
			    break;
            }
            
            default:
            {
				cout<<"\nInvalid Entry\n";
				cout<<"\n-------------------------------------------------------\n";
                printf("Press Any Key To Continue...\n");
                getch();
                system("CLS"); // For Clearing The Screen
            }
        }
    }
    return 0;
}

i20::i20(string name,float price,string model)
{
    setname(name);
    setprice(price);
    setmodel(model);
}

i20::i20():i20("i20",30000,"i20 1")
{
    
}

i20::i20(i20 &i)
{
    this->name=i.name;
    this->price=i.price;
    this->model=i.model;
}

void i20::setname(string name) {this->name=name;}

void i20::setprice(float price)
{
    this->price=price;
}

void i20::setmodel(string model)
{
    this->model=model;
}

string i20::getname()
{
    return(name);
}

float i20::getprice()
{
    return(price);
}

string i20::getmodel()
{
    return(model);
}

void i20::upgrade()
{
    i++;
    
    if(i==2)
        model="i20 2";
    
    else if(i==3)
        model="i20 3";
    
    else if(i==4)
        model="i20 4";
    
    else if(i==5)
        model="i20 5";
    
    else if(i==6)
        model="i20 6";
    
    else
        cout<<"This Type Of Cars Are Completely Upgraded";
}

i20::~i20() {}

Ferari::Ferari(string name,float price,string model)
{
    setname(name);
    setprice(price);
    setmodel(model);
}

Ferari::Ferari():Ferari("Ferari",54000,"Ferari 1")
{
    
}

Ferari::Ferari(Ferari &i)
{
    this->name=i.name;
    this->price=i.price;
    this->model=i.model;
}

void Ferari::setname(string name)
{
    this->name=name;
}

void Ferari::setprice(float price)
{
    this->price=price;
}

void Ferari::setmodel(string model)
{
    this->model=model;
}

string Ferari::getname()
{
    return(name);
}

float Ferari::getprice()
{
    return(price);
}

string Ferari::getmodel()
{
    return(model);
}

void Ferari::upgrade()
{
    f++;
    
    if(f==2)
        model="Ferari 2";
    
    else if(f==3)
        model="Ferari 3";
    
    else if(f==4)
        model="Ferari 4";
    
    else if(f==5)
        model="Ferari 5";
    
    else if(f==6)
        model="Ferari 6";
    
    else
        cout<<"This Type Of Cars Are Completely Upgraded";
}

Ferari::~Ferari() {}

Polo::Polo(string name,float price,string model)
{
    setname(name);
    setprice(price);
    setmodel(model);
}

Polo::Polo():Polo("Polo",75000,"Polo 1")
{
    
}

Polo::Polo(Polo &i)
{
    this->name=i.name;
    this->price=i.price;
    this->model=i.model;
}

void Polo::setname(string name)
{
    this->name=name;
}

void Polo::setprice(float price)
{
    this->price=price;
}

void Polo::setmodel(string model)
{
    this->model=model;
}

string Polo::getname()
{
    return(name);
}

float Polo::getprice()
{
    return(price);
}

string Polo::getmodel()
{
    return(model);
}

void Polo::upgrade()
{
    p++;
    
    if(p==2)
        model="Polo 2";
    
    else if(p==3)
        model="Polo 3";
    
    else if(p==4)
        model="Polo 4";
    
    else if(p==5)
        model="Polo 5";
    
    else if(p==6)
        model="Polo 6";
    
    else
        cout<<"This Type Of Cars Are Completely Upgraded";
}

Polo::~Polo() {}

Creta::Creta(string name,float price,string model)
{
    setname(name);
    setprice(price);
    setmodel(model);
}

Creta::Creta():Creta("Creta",90000,"Creta 1")
{
    
}

Creta::Creta(Creta &i)
{
    this->name=i.name;
    this->price=i.price;
    this->model=i.model;
}

void Creta::setname(string name)
{
    this->name=name;
}

void Creta::setprice(float price)
{
    this->price=price;
}

void Creta::setmodel(string model)
{
    this->model=model;
}

string Creta::getname()
{
    return(name);
}

float Creta::getprice()
{
    return(price);
}

string Creta::getmodel()
{
    return(model);
}

void Creta::upgrade()
{
    c++;
    
    if(c==2)
        model="Creta 2";
    
    else if(c==3)
        model="Creta 3";
    
    else if(c==4)
        model="Creta 4";
    
    else if(c==5)
        model="Creta 5";
    
    else if(c==6)
        model="Creta 6";
    
    else
        cout<<"This Type Of Cars Are Completely Upgraded";
}

Creta::~Creta() {}

Garage::Garage(int i1,int i2,int i3,int i4)
{
    I20=new i20[i1];
    ferari=new Ferari[i2];
    polo=new Polo[i3];
    creta=new Creta[i4];
}

Garage::Garage():Garage(200,200,200,200)
{
    
}

Garage::Garage(Garage &g)
{
    this->I20=g.I20;
    this->ferari=g.ferari;
    this->polo=g.polo;
    this->creta=g.creta;
}

void Garage::setsizei20(int size)
{
    delete []I20;
    I20=new i20[size];
}

void Garage::setsizeFerari(int size)
{
    delete []ferari;
    ferari=new Ferari[size];
}

void Garage::setsizePolo(int size)
{
    delete []polo;
    polo=new Polo[size];
}

void Garage::setsizeCreta(int size)
{
    delete []creta;
    creta=new Creta[size];
}

Garage::~Garage()
{
    delete []I20;
    delete []ferari;
    delete []polo;
    delete []creta;
}

