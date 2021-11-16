#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <cstdarg>

using namespace std;

template<class T>
class HashTable
{
    private:
	    T *q;
		int size;
		int ne;
	public:
	    HashTable();
		HashTable(int size);
		HashTable(HashTable<T> &HT);
		void setsize(int size);
		void setne(int ne);
		T * getq();
		int getsize();
		int getne();
		int Hash1(int key);
		int Hash2(int key);
		int Probe(int key);
		void SetElements(int n,...);
		void Insert(T key);
		bool Search(T key);
		bool isEmpty();
		void Display();
		template<class P>
		friend ostream & operator<<(ostream &o,HashTable<P> &HT);
        ~HashTable();	
};

template<class T>
ostream & operator<<(ostream &o,HashTable<T> &HT)
{
	o<<"\n-----------------------------------------------------------------------------------\n\n";
	o<<"Size Of The HashTable Is : "<<HT.size;
	o<<"\nTotal Number Of Elements In The HashTable Are : "<<HT.ne;
	o<<"\n\nHashTable Using Linear Probing Is As Follows :\n";
	for(int i=0;i<HT.size;i++)
	{
		if(*(HT.q+i)!=-1)
		{
		    o<<"\nElement At Index "<<i<<" : ";
		    o<<*(HT.q+i);
		    o<<endl;
        }
	}
	o<<"\n-----------------------------------------------------------------------------------\n\n";
	return(o);
}

int main()
{
	HashTable<int> HT(13);
	
	HT.SetElements(6,5,15,25,35,45,55);
	
	/*
	HT.Insert(5.1f);
	HT.Insert(15.4f);
	HT.Insert(25.7f);
	HT.Insert(35.2f);
	HT.Insert(45.6f);
	HT.Insert(55.9f);
	*/
	cout<<HT;
	
	return(0);
}

template<class T>
HashTable<T>::HashTable()
{
	ne=0;
	size=11;
	q=new T[size];
	
	for(int i=0;i<size;i++)
	    *(q+i)=-1;
}

template<class T>
HashTable<T>::HashTable(int size)
{
	ne=0;
	this->size=size;
	q=new T[size];
	
	for(int i=0;i<size;i++)
	    *(q+i)=-1;
}

template<class T>
HashTable<T>::HashTable(HashTable<T> &HT)
{
	size=HT.size;
	ne=HT.ne;
	q=new T[size];
	
	for(int i=0;i<size;i++)
	    *(q+i)=*(HT.q+i);
}

template<class T>
void HashTable<T>::setsize(int size)
{
	delete []q;
	this->size=size;
	q=new T[size];
	ne=0;
	
	for(int i=0;i<size;i++)
	    *(q+i)=-1;
}

template<class T>
void HashTable<T>::setne(int ne)
{
	this->ne=ne;
}

template<class T>
T * HashTable<T>::getq()
{
	return(q);
}

template<class T>
int HashTable<T>::getsize()
{
	return(size);
}

template<class T>
int HashTable<T>::getne()
{
	return(ne);
}

template<class T>
int HashTable<T>::Hash1(int key)
{
	return(key%10);
}

template<class T>
int HashTable<T>::Hash2(int key)
{
	return(7-key%7);
}

template<class T>
int HashTable<T>::Probe(int key)
{
	int index=Hash1(key);
	int i=0;
	
	while(*(q+(index+i*Hash2(key))%size)!=-1)
	    i++;
	
	return((index+i*Hash2(key))%size);
}

template<class T>
void HashTable<T>::SetElements(int n,...)
{
	va_list list;
	va_start(list,n);
	
	for(int i=1;i<=n;i++)
	    Insert(va_arg(list,int));
	va_end(list);
}

template<class T>
void HashTable<T>::Insert(T key)
{
	int index=Hash1(key);
	float t=ne/size;
	
	if(t>0.5)
	    cout<<"\nLoading Factor Is Greater Than "<<t<<endl;
	else
	{
		if(*(q+index)!=-1)
	        index=Probe(key);
	    
	    *(q+index)=key;
	    ne++;
	}
}

template<class T>
bool HashTable<T>::Search(T key)
{
	int index=Hash1(key);
	int i=0;
	
	while(*(q+(index+i*Hash2(key))%size)!=-1)
	{
		if(*(q+(index+i*Hash2(key))%size)==key)
		    return(true);
		i++;
	}
	return(false);
}

template<class T>
bool HashTable<T>::isEmpty()
{
	if(ne==0)
	    return(true);
	return(false);
}

template<class T>
void HashTable<T>::Display()
{
	cout<<"\n-----------------------------------------------------------------------------------\n\n";
	cout<<"Size Of The HashTable Is : "<<size;
	cout<<"\nTotal Number Of Elements In The HashTable Are : "<<ne;
	cout<<"\n\nHashTable Using Linear Probing Is As Follows :\n";
	for(int i=0;i<size;i++)
	{
		if(*(q+i)!=-1)
		{
		    cout<<"\nElement At Index "<<i<<" : ";
		    cout<<*(q+i);
		    cout<<endl;
        }
	}
	cout<<"\n-----------------------------------------------------------------------------------\n\n";
}

template<class T>
HashTable<T>::~HashTable()
{
	delete []q;
	q=NULL;
}

