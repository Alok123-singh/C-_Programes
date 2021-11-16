#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class warrior
{
private:
    string name;
    int trtime;
    float money;
public:
    warrior();
    warrior(string name,int trtime,float money);
    warrior(warrior &w);
    void setname(string name);
    void settrtime(int trtime);
    void setmoney(float money);
    string getname();
    int gettrtime();
    float getmoney();
    ~warrior(){}
};

class archer:public warrior
{
 public:
    archer();
    archer(string name,int trtime,float money);
    archer(archer &ar);
    friend ostream & operator<<(ostream &out,archer &ar);
    friend istream & operator>>(istream &in,archer &ar);    
    ~archer(){}
};

ostream & operator<<(ostream &out,archer &ar)
{
    out<<"Name Of Archer Is :\t\t\t"<<ar.getname()<<endl;
    out<<"Training Time Is :\t\t\t"<<ar.gettrtime()<<endl;
    out<<"Money Required To Train Him Is :\t"<<ar.getmoney();
    return(out);    
}

istream & operator>>(istream &in,archer &ar)
{
    string name;
    int trtime;
    float money;
    cout<<"Enter Name Of Archer:\t\t\t";
    getline(in,name);
    cout<<"Enter Training Time:\t\t\t";
    in>>trtime;
    cout<<"Enter Money Required To Train Him:\t";
    in>>money;
    ar.setname(name);
    ar.settrtime(trtime);
    ar.setmoney(money);
    return(in);
}

class barbarion:public warrior
{
  public:
    barbarion();
    barbarion(string name,int trtime,float money);
    barbarion(barbarion &bn);
    friend ostream & operator<<(ostream &out,barbarion &bn);
    friend istream & operator>>(istream &in,barbarion &bn);
    ~barbarion(){}  
};

ostream & operator<<(ostream &out,barbarion &bn)
{
    out<<"Name Of Barbarion Is:\t\t\t"<<bn.getname()<<endl;
    out<<"Training Time Is:\t\t\t"<<bn.gettrtime()<<endl;
    out<<"Money Required To Train Him Is:\t"<<bn.getmoney();
    return(out);
}

istream & operator>>(istream &in,barbarion &bn)
{
    string name;
    int trtime;
    float money;
    cout<<"Enter Name Of Barbarion:\t\t\t";
    getline(in,name);
    cout<<"Enter Training Time:\t\t\t";
    in>>trtime;
    cout<<"Enter Money Required To Train Him:\t";
    in>>money;
    bn.setname(name);
    bn.settrtime(trtime);
    bn.setmoney(money);
    return(in);
}

class ArmyCamp
{
  private:
    archer ar[300];
    barbarion bn[300];
  public:
    ArmyCamp() {}
    ArmyCamp(ArmyCamp &ac,int i1,int i2,int j1,int j2);
    archer * getaddressar();
    barbarion * getaddressbn();
    ~ArmyCamp(){}
};

void Delay()
{
	for(int i=0;i<INT_MAX/13;i++);
}

void SDelay()
{
	for(int i=0;i<INT_MAX/34;i++);
}

int main()
{
    ArmyCamp ac1;
    archer *ptr1=ac1.getaddressar();
    barbarion *ptr2=ac1.getaddressbn();
    int test=0;
    
    int x;
    while(1)
    {
        cout<<"\n*Troops Training* \t\tWELCOME\t\t\t *Start-Training*";
        cout<<"\n----------------------------------------------------------------------------\n";   
        cout<<"*(Warning)* :- Provide Only 10 Or Less Than 10 Total Troops Once At A Time.\n\n";
        
		cout<<"1.Train Troops\n2.View Troop Camp Or Army Camp\n3.Exit\n\n";
        cout<<"What Do You Want To Do ? :\n";
        cin>>x;
        static long n1,n2,t1,t2;
        n1=0; t1=0;
        n2=0 ;t2=0;
        static long t3=0,t4=0;
        switch(x)
        {
            case 1:
            {
				system("CLS");
				cout<<"\n*(Warning)* :- Provide Only 10 Or Less Than 10 Total Troops Once At A Time.\n\n";
				while(n1+n2+t1+t2<10)
                {
					cout<<"\nHow Many Archers You Want To Train ? :\n";
                    cin>>n1;
                    if(1)
                    {
                        cout<<"\nHow Many Barbarians You Want To Train ? :\n";
                        cin>>n2;
                        if(n1+n2+t1+t2>10)
                        {
                            cout<<endl;
                            system("CLS");
                            cout<<"\n*(Warning)* :- Provide Only 10 Or Less Than 10 Total Troops Once At A Time.\n\n";
							cout<<setw(65)<<"ERROR 404!\n";
							printf("%33cotal Number Of Troops Provided Are Greater Than 10.\n",'T');
                            printf("%21ctart From The Beginning After Error. Game Before This Error Has Been Saved.\n",'S');
							n1=0;
                            n2=0;
                            test=1;
                        }
                        if(t1>10) t1=0;
                        
                        if(t2>10) t2=0;
                    }
                    for(int i=0;i<n1;i++)
                    {
                        archer ar;
                        ar.setname("INDIAN ARMY");
                        *(ptr1+t3)=ar;
                        t1++;
                        t3++;
                    }
                    for(int j=0;j<n2;j++)
                    {
                        barbarion bn;
                        bn.setname("MUGHAL ARMY");
                        *(ptr2+t4)=bn;
                        t2++;
                        t4++;
                    }
                    if(n1+n2<10)
                        n1=n2=0;
                    
                    if(n1+n2+t1+t2<10)
					{
				        cout<<"\nPlease Provide Some More Archers Or Barbarians To Start Training:\n";
				        if(test==1)
						    t1=t2=0;
						test=0;
                    }
				}
                cout<<"\nPlease Wait. Training Is In Progress...\n";
				printf("\n%20c",'[');
	            for(int i1=0;i1<79;i1++)
	            {
		            printf("*"); 
		            if(i1==78)
			            printf("]");					
		            SDelay();
	            }
                cout<<endl<<"\nTraining Completed. Troops Are Available In Army Camp.\n\n";
                cout<<"Press Any Key To Continue... ";
                getch();
                system("CLS");
                break;
            }
            case 2:
            {
                system("CLS");
				cout<<"\nGathering Information . . .\n\n\n\n\n\n\n\n\n\n\n";
				printf("\n%38c",'[');
				for(int j=0;j<40;j++)
				{
					printf("*");
					if(j==39)
					    printf("]");					
					SDelay();
				}
				SDelay();
                system("CLS");
				cout<<"\n-------------------";
                cout<<"\nTroops Camp :\n\n";
                cout<<"Archers    : "<<t3<<endl;
                cout<<"Barbarions : "<<t4<<endl;
                cout<<"-------------------"<<endl<<endl;
                cout<<"Press Any Key To Continue... ";
                getch();
                system("CLS");
                break;
            }
			case 3:
            {
                char ch;
				cout<<"\nAre You Sure You Want To Quit The Game? Enter Y For Yes And N For No :\n";
				cin>>ch;
				if(ch=='Y') exit(0);
				system("CLS"); // For Clearing The Screen
				break;
            }
            default:
			{
			    cout<<"\nInvalid Entry. Press Any Key To Continue...\n";
                getch();
                system("CLS");
			}
        }
    }
    return(0);
}

warrior::warrior()
{
    name="Warrior Does Not Exist";
    trtime=0;
    money=0;
}

warrior::warrior(string name,int trtime,float money)
{
    this->name=name;
    this->trtime=trtime;
    this->money=money;
}

warrior::warrior(warrior &w)
{
    name=w.name;
    trtime=w.trtime;
    money=w.money;
}

void warrior::setname(string name)
{
    this->name=name;
}

void warrior::settrtime(int trtime)
{
    this->trtime=trtime;
}

void warrior::setmoney(float money)
{
    this->money=money;
}

string warrior::getname()
{
    return(name);
}

int warrior::gettrtime()
{
    return(trtime);
}

float warrior::getmoney()
{
    return(money);
}

archer::archer()
{
    setname("Archer Does Not Exist");
    settrtime(0);
    setmoney(0.00f);
}

archer::archer(string name,int trtime,float money)
{
    setname(name);
    settrtime(trtime);
    setmoney(money);
}

archer::archer(archer &ar)
{
    setname(ar.getname());
    settrtime(ar.gettrtime());
    setmoney(ar.getmoney());
}

barbarion::barbarion()
{
    setname("Barbarion Does Not Exist");
    settrtime(0);
    settrtime(0.00);
}

barbarion::barbarion(string name,int trtime,float money)
{
    setname(name);
    settrtime(trtime);
    setmoney(money);
}

barbarion::barbarion(barbarion &bn)
{
    setname(bn.getname());
    settrtime(bn.gettrtime());
    setmoney(bn.getmoney());
}

ArmyCamp::ArmyCamp(ArmyCamp &ac,int i1,int i2,int j1,int j2)
{
    for(int i=i1;i<=i2;i++)
    {
        this->ar[i]=ac.ar[i];
    }
    for(int j=j1;j<j2;j++)
    {
        this->bn[j]=ac.bn[j];
    }
}

archer * ArmyCamp::getaddressar()
{
    return(ar);
}

barbarion * ArmyCamp::getaddressbn()
{
    return(bn);
}

