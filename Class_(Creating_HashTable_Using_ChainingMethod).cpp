#include <iostream>
#include <stdbool.h>
#include <cstdarg>

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
		
		Node();
		Node(T data);
};

template<class T>
class HashTable
{
    private:
	    int size;
		Node<T> **ht;
		int ne;
	public:
	    HashTable();
		HashTable(int size);
		HashTable(HashTable &HT);
		void setsize(int size);
		int getsize();
		Node<T> ** getht();
		int getne();
		void SetElements(int n,...);
		void Insert(T key);
		T Delete(T key);
		void Display();
		bool Search(T key);
		int Hash(int key);
		bool isEmpty();
		bool isFull();
		template<class P>
		friend ostream & operator<<(ostream &o,HashTable<P> &HT);
		~HashTable();
};

template<class T>
ostream & operator<<(ostream &o,HashTable<T> &HT)
{
	Node<T> *p=NULL;
	
	o<<"\n----------------------------------------------------------------------------------\n\n";
	o<<"Size Of The HashTable Is : "<<HT.size;
	o<<"\nTotal Number Of Elements In Hash Table Are : "<<HT.ne;
	o<<"\n\nHashTable Using Chaining Method Is As Follows :\n";
	for(int i=0;i<10;i++)
	{
		if(*(HT.ht+i)!=NULL)
		{
		    o<<"\nElements Having Last Digit As "<<i<<" Are : ";
		    p=*(HT.ht+i);
		    while(p)
		    {
			    o<<p->data<<"  ";
			    p=p->next;
		    }
		    o<<endl;
	    }
	}
	o<<"\n----------------------------------------------------------------------------------\n\n";
    return(o);
}

int main()
{
	HashTable<char> HT;
    
	for(int i=65;i<=90;i++)
        HT.Insert(i);
    
    cout<<HT; // HT.Display();
    
    return (0);
}

template<class T>
Node<T>::Node()
{
	data=0;
	next=NULL;
}

template<class T>
Node<T>::Node(T data)
{
	this->data=data;
	next=NULL;
}

template<class T>
HashTable<T>::HashTable()
{
	ne=0;
	size=10;
	ht=new Node<T>*[size];
	
	for(int i=0;i<size;i++)
	    *(ht+i)=NULL;
}

template<class T>
HashTable<T>::HashTable(int size)
{
	ne=0;
	this->size=size;
	ht=new Node<T>*[size];
	
	for(int i=0;i<size;i++)
	    *(ht+i)=NULL;
}

template<class T>
HashTable<T>::HashTable(HashTable<T> &HT)
{
	Node<T> *p=nullptr,*temp=nullptr,*r=nullptr;
	
	ne=HT.ne;
	size=HT.size;
	ht=new Node<T>*[size];
	
	for(int i=0;i<size;i++)
	    *(ht+i)=nullptr;
	
	for(int i=0;i<size;i++)
	{
		p=*(HT.ht+i);
		
		while(p)
		{
			temp=new Node<T>(p->data);
			
			if(*(ht+i)==nullptr)
			    r=*(ht+i)=temp;
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
	Node<T> *p=NULL,*q=NULL;
	
	for(int i=0;i<10;i++)
	{
		p=*(ht+i);
		
		while(q!=NULL)
		{
			q=p;
			p=p->next;
			delete q;
		}
		*(ht+i)=NULL;
	}
	
	delete []ht;
	ht=NULL;
	
	ne=0;
	this->size=size;
	ht=new Node<T>*[size];
	
	for(int i=0;i<size;i++)
	    *(ht+i)=NULL;
}

template<class T>
int HashTable<T>::getsize()
{
	return(size);
}

template<class T>
Node<T> ** HashTable<T>::getht()
{
	return(ht);
}

template<class T>
int HashTable<T>::getne()
{
    return(ne);
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
int HashTable<T>::Hash(int key)
{
	return(key%10);
}

template<class T>
void HashTable<T>::Insert(T key)
{
	Node<T> *temp=NULL,*p=NULL,*q=NULL;
	int index=Hash(key);
	
	temp=new Node<T>(key);
	if(temp==NULL)
	    cout<<"\nHashTable Overflow\n";
	else
	{
		if(*(ht+index)==NULL)
		    *(ht+index)=temp;
		else
		{
			p=*(ht+index);
			while(p!=NULL)
			{
				q=p;
				if(key<p->data)
				    break;
				p=p->next;
			}
			
			if(p==NULL)
			    q->next=temp;
			else if(p->data==(*(ht+index))->data)
			{
				temp->next=*(ht+index);
				*(ht+index)=temp;
			}
			else
			{
				temp->next=q->next;
				q->next=temp;
			}
		}
		ne++;
	}
}

template<class T>
T HashTable<T>::Delete(T key)
{
	T x=-1;
	int index=Hash(key);
	Node<T> *p=*(ht+index),*q=NULL;
	
	if(p==NULL)
	    cout<<"\nElement Is Not Present\n";
	else
	{
		if(key==p->data)
		{
			x=p->data;
			*(ht+index)=p->next;
			delete p;
			p=NULL;
			ne--;
	    }
		
	    while(p!=NULL)
		{
			q=p;
			if(key==p->data)
			    break;
			p=p->next;
		}
		
		if(p!=NULL)
		{
			q->next=q->next->next;
			x=p->data;
			delete p;
			ne--;
		}
	}
	return(x);
}

template<class T>
bool HashTable<T>::Search(T key)
{
	int index=Hash(key);
	Node<T> *p=*(ht+index);
	
	while(p!=NULL)
	{
		if(key==p->data)
		    return(true);
		p=p->next;
	}
	
	return(false);
}

template<class T>
void HashTable<T>::Display()
{
	Node<T> *p=NULL;
	
	cout<<"\n----------------------------------------------------------------------------------\n\n";
	cout<<"Size Of The HashTable Is : "<<size;
	cout<<"\nTotal Number Of Elements In Hash Table Are : "<<ne;
	cout<<"\n\nHashTable Using Chaining Method Is As Follows :\n";
	for(int i=0;i<10;i++)
	{
		if(*(ht+i)!=NULL)
		{
		    cout<<"\nElements Having Last Digit As "<<i<<" Are : ";
		    p=*(ht+i);
		    while(p)
		    {
			    cout<<p->data<<"  ";
			    p=p->next;
		    }
		    cout<<endl;
		}
	}
	cout<<"\n----------------------------------------------------------------------------------\n\n";
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
	Node<T> *p=NULL;
	
	p=new Node<T>;
	
	if(p==NULL)
	    return(true);
	return(false);
}

template<class T>
HashTable<T>::~HashTable()
{
	Node<T> *p=NULL,*q=NULL;
	
	for(int i=0;i<10;i++)
	{
		p=*(ht+i);
		
		while(q!=NULL)
		{
			q=p;
			p=p->next;
			delete q;
		}
		*(ht+i)=NULL;
	}
	
	delete []ht;
	ht=NULL;
}

