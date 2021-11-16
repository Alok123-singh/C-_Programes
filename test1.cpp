#include <iostream>
#include <cstdarg>
#include <stdbool.h>

#ifndef nullptr
#define nullptr NULL
#endif

using namespace std;

template<class T>
class Node
{
	public:
		T data;
		Node<T> *next;
		Node(T data);
};

template<class T>
class HashTable
{
    private:
	    int ne;
	    int size;
		Node<T> **q;
	public:
		HashTable();
	    HashTable(int size);
		HashTable(HashTable<T> &HT);
        void setsize(int size);
        int getsize();
        int getne();
        Node<T> ** getq();
		void setElements(int n,...);
		void Insert(T key);
		int Delete(T key);
		bool Search(T key);
		int Hash(int key);
		void Display();
		bool isEmpty();
		bool isFull();
		template<class P>
		friend ostream & operator<<(ostream &o,HashTable<P> &HT);
		~HashTable();	
};

template<class T>
ostream & operator<<(ostream &o,HashTable<T> &HT)
{
	Node<T> *p=nullptr;
	
	o<<"\n--------------------------------------------------------------------\n\n";
	o<<"Size Of The HashTable : "<<HT.size<<endl;
	o<<"Total Number Of Elements : "<<HT.ne<<endl<<endl;
	o<<"Hash Table Is As Follows :"<<endl;
	for(int i=0;i<HT.size;i++)
	{
		p=*(HT.q+i);
		if(p)
		    o<<"\nElements At Index "<<i<<" :";
		while(p)
		{
			o<<p->data<<"  ";
			p=p->next;
		}
		if(*(HT.q+i))
		    o<<endl;
	}
	o<<"\n--------------------------------------------------------------------\n";
}

int main()
{
	HashTable<char> HT(11);
	
	for(int i=65;i<=90;i++)
	    HT.Insert(i);
	
	HashTable<char> HT1(HT);
	
	cout<<HT1; // HT1.Display();
	
	return(0);
}

template<class T>
Node<T>::Node(T data)
{
	this->data=data;
	next=nullptr;
}

template<class T>
HashTable<T>::HashTable()
{
	ne=0;
	q=nullptr;
	size=0;
}

template<class T>
HashTable<T>::HashTable(int size)
{
	this->size=size;
	ne=0;
	q=new Node<T>*[size];
	
	for(int i=0;i<size;i++)
	    *(q+i)=nullptr;
}

template<class T>
HashTable<T>::HashTable(HashTable<T> &HT)
{
	Node<T> *p=nullptr,*temp=nullptr,*r=nullptr;
	
	ne=HT.ne;
	size=HT.size;
	q=new Node<T>*[size];
	
	for(int i=0;i<size;i++)
	    *(q+i)=nullptr;
	
	for(int i=0;i<size;i++)
	{
		p=*(HT.q+i);
		
		while(p)
		{
			temp=new Node<T>(p->data);
			
			if(*(q+i)==nullptr)
			    r=*(q+i)=temp;
			else
			{
				r->next=temp;
				r=temp;
			}
			p=p->next;
		}
	}
}

template<class T>
void HashTable<T>::setsize(int size)
{
	this->size=size;
	q=new Node<T>*[size];
	
	for(int i=0;i<size;i++)
	    *(q+i)=nullptr;
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
Node<T> ** HashTable<T>::getq()
{
	return(q);
}

template<class T>
int HashTable<T>::Hash(int key)
{
	return (key%10);
}

template<class T>
void HashTable<T>::Insert(T key)
{
	int index=Hash(key);
	Node<T> *p=new Node<T>(key),*q1=nullptr,*r=nullptr;
	
	if(p==nullptr)
	    cout<<"\nHash Table Overflow\n";
	else
	{
        if(*(q+index)==nullptr)
		    *(q+index)=p;
		else
		{
			r=*(q+index);
		    while(r && r->data<key)
		    {
		    	q1=r;
		    	r=r->next;
			}
			
			if(q1==nullptr)
			{
				p->next=*(q+index);
				*(q+index)=p;
			}
			else
			{
				p->next=q1->next;
				q1->next=p;
			}
		}
		ne++;
	}
}

template<class T>
void HashTable<T>::setElements(int n,...)
{
	va_list obj;
	
	va_start(obj,n);
	
	for(int i=0;i<n;i++)
	    Insert(va_arg(obj,int));
	
	va_end(obj);
}

template<class T>
int HashTable<T>::Delete(T key)
{
	int index=Hash(key),x=0;
	Node<T> *p=*(q+index),*q=nullptr;
	
	if(p->data==key)
	{
		x=1;
		*(q+index)=p->next;
		delete p;
		ne--;
	}
	while(p)
	{
		q=p;
		p=p->next;
        		
		if(p->data==key)
		    break;
	}
	
	if(p->data==key)
	{
		x=1;
		q->next=q->next->next;
		delete p;
		ne--;
	}
	return(x);
}

template<class T>
bool HashTable<T>::Search(T key)
{
	int index=Hash(key);
	Node<T> *p=*(q+index);
	
	while(p && p->data<key)
	{
		if(p->data==key)
		    return(true);
		p=p->next;
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
bool HashTable<T>::isFull()
{
	Node<T> *test=new Node<T>;
	
	if(test==nullptr)
	    return(true);
	return(false);
}

template<class T>
void HashTable<T>::Display()
{
	Node<T> *p=nullptr;
	
	cout<<"\n--------------------------------------------------------------------\n\n";
	cout<<"Size Of The HashTable : "<<size<<endl;
	cout<<"Total Number Of Elements : "<<ne<<endl<<endl;
	cout<<"Hash Table Is As Follows :"<<endl;
	for(int i=0;i<size;i++)
	{
		p=*(q+i);
		if(p)
		    cout<<"\nElements At Index "<<i<<" :";
		while(p)
		{
			cout<<p->data<<"  ";
			p=p->next;
		}
		if(*(q+i))
		    cout<<endl;
	}
	cout<<"\n--------------------------------------------------------------------\n";
}

template<class T>
HashTable<T>::~HashTable()
{
	Node<T> *p=nullptr,*q1=nullptr;
	
	for(int i=0;i<size;i++)
	{
		p=*(q+i);
		
		while(p)
		{
			q1=p;
			p=p->next;
			delete q1;
		}
		*(q+i)=nullptr;
	}
	delete []q;
}

