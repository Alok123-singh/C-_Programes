#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

using namespace std;

template<class T>
class MinHeap
{
    private:
	    T *q;
		int size;
		int length;
	public:
	    MinHeap();
		MinHeap(int size);
		MinHeap(MinHeap<T> &mh);
		void setsize(int size);
		void setlength(int length);
		T * getq();
		int getsize();
		int getlength();
		void Insert(T key);
		T Delete();
		void CreateMinHeap();
		void Heapify();
		void HeapSort();
		bool isEmpty();
		bool isFull();
		void Display();
		template<class P>
		friend ostream & operator<<(ostream &o,MinHeap<P> &mh);
		template<class P>
		friend istream & operator>>(istream &in,MinHeap<P> &mh);
		~MinHeap();	
};

template<class T>
ostream & operator<<(ostream &o,MinHeap<T> &mh)
{
	int i;
	
	o<<"\n-------------------------------------------------------------------------\n\n";
	o<<"Size Of The MinHeap Is : "<<mh.size;
	o<<"\nTotal Number Of Elements In MinHeap Are : "<<mh.length;
	o<<"\n\nMinHeap Is As Follows : \n";
	for(i=1;i<=mh.length;i++)
	    o<<*(mh.q+i)<<"  ";
	o<<"\n\n-------------------------------------------------------------------------\n";
	return(o);
}

template<class T>
istream & operator>>(istream &in,MinHeap<T> &mh)
{
	int i,j,k;
	T temp;
	
	cout<<"\nEnter Size Of The MinHeap :\n";
	in>>mh.size;
	delete []mh.q;
	mh.q=new T[mh.size];
	cout<<"\nEnter Total Number Of Elements In MinHeap :\n";
	in>>mh.length;
	
	*mh.q=INT_MIN; // Very Important Action Statement
	for(i=1;i<mh.size;i++)
	    *(mh.q+i)=INT_MAX;
	
	for(i=1;i<=mh.length;i++)
	{
		cout<<"\nEnter "<<i<<" Element :\n";
		in>>*(mh.q+i);
	}
	
	i=mh.length;
	while(i>=1)
	{
		if(*(mh.q+2*i)!=INT_MAX || *(mh.q+2*i+1)!=INT_MAX)
		{
			k=i;
			while(2*k<=mh.length || 2*k+1<=mh.length)
			{
				j=k;
				k=*(mh.q+2*k)<*(mh.q+2*k+1)?2*k:2*k+1;
				
				if(*(mh.q+k)<*(mh.q+j))
				{
					temp=*(mh.q+j);
					*(mh.q+j)=*(mh.q+k);
					*(mh.q+k)=temp;
				}
				else
				    break;
			}
		}
		--i;
	}
	return(in);
}

int main()
{
	MinHeap<int> mh(40);
	
	cin>>mh;
	
	cout<<mh;
	
	mh.HeapSort();
	
	return(0);
}

template<class T>
MinHeap<T>::MinHeap()
{
	size=16;
	length=0;
	q=new T[size];
	*q=INT_MIN; // Very Important Action Statement
	
	for(int i=1;i<size;i++)
	    *(q+i)=INT_MAX;
}

template<class T>
MinHeap<T>::MinHeap(int size)
{
	this->size=size;
	length=0;
	q=new T[size];
	*q=INT_MIN; // Very Important Action Statement
	
	for(int i=1;i<size;i++)
	    *(q+i)=INT_MAX;
}

template<class T>
MinHeap<T>::MinHeap(MinHeap<T> &mh)
{
	size=mh.size;
	q=new T[size];
	*q=INT_MIN; // Very Important Action Statement
	
	for(length=1;length<=mh.length;length++)
	    *(q+length)=*(mh.q+length);
	
	for(int i=length+1;i<size;i++)
	    *(q+i)=INT_MAX;
}

template<class T>
void MinHeap<T>::setsize(int size)
{	
	this->size=size;
	length=0;
	delete []q;
	q=new T[size];
	*q=INT_MIN; // Very Important Action Statement
	
	for(int i=1;i<size;i++)
	    *(q+i)=INT_MAX;
}

template<class T>
void MinHeap<T>::setlength(int length)
{
	this->length=length;
}

template<class T>
T * MinHeap<T>::getq()
{
	return(q);
}

template<class T>
int MinHeap<T>::getlength()
{
	return(length);
}

template<class T>
int MinHeap<T>::getsize()
{
	return(size);
}

template<class T>
void MinHeap<T>::Insert(T key)
{
	int i=length+1,j;
	T temp;
	
	if(length==size-1)
	    cout<<"\nHeap Overflow\n";
	else
	{
		*(q+i)=key;
		while(i>=1)
		{
			j=i;
			i=i/2;
			
			if(*(q+j)<*(q+i))
			{
				temp=*(q+j);
				*(q+j)=*(q+i);
				*(q+i)=temp;
			}
			else
			    break;
		}
		length++;
	}
}

template<class T>
T MinHeap<T>::Delete()
{
	int i,j;
	T temp,del=-1;
	T *p=new T[size];
	
	for(i=0;i<size;i++)
	    *(p+i)=INT_MAX;
	
	for(i=0,j=length+1;*(q+j)!=INT_MAX;i++,j++)
	{
	    *(p+i)=*(q+j);
	    *(q+j)=INT_MAX;
    }
	
	if(length==0)
	    cout<<"\nHeap Underflow\n";
	else
	{
		del=*(q+1);
		*(q+1)=*(q+length);
		*(q+length)=INT_MAX;
		i=1;
		
		while((*(q+2*i)!=INT_MAX && *(q+2*i+1)!=INT_MAX) || (2*i<size || 2*i+1<size))
		{
			j=i;
			i=*(q+2*i)<*(q+2*i+1)?2*i:2*i+1;
			
			if(*(q+i)<*(q+j))
			{
				temp=*(q+i);
				*(q+i)=*(q+j);
				*(q+j)=temp;
			}
			else
			    break;
		}
		
		*(q+length)=del;
		length--;
	}
	
	for(i=length+2,j=0;*(p+j)!=INT_MAX;i++,j++)
	    *(q+i)=*(p+j);
	
	return(del);
}

template<class T>
void MinHeap<T>::CreateMinHeap()
{
	int i,ne;
	T temp;
	
	cout<<"\nEnter Size Of The MinHeap :\n";
	cin>>size;
	delete []q;
	q=new T[size];
	cout<<"\nEnter Total Number Of Elements In MinHeap :\n";
	cin>>ne;
	
	*q=INT_MIN; // Very Important Action Statement
	for(i=1;i<size;i++)
	    *(q+i)=INT_MAX;
	
	for(i=1;i<=ne;i++)
	{
		cout<<"\nEnter "<<i<<" Element :\n";
		cin>>temp;
		Insert(temp);
	}
}

template<class T>
void MinHeap<T>::Heapify()
{
	int i,j,k;
	T temp;
	
	cout<<"\nEnter Size Of The MinHeap :\n";
	cin>>size;
	delete []q;
	q=new T[size];
	cout<<"\nEnter Total Number Of Elements In MinHeap :\n";
	cin>>length;
	
	*q=INT_MIN; // Very Important Action Statement
	for(i=1;i<size;i++)
	    *(q+i)=INT_MAX;
	
	for(i=1;i<=length;i++)
	{
		cout<<"\nEnter "<<i<<" Element :\n";
		cin>>*(q+i);
	}
	
	i=length;
	while(i>=1)
	{
		if(*(q+2*i)!=INT_MAX || *(q+2*i+1)!=INT_MAX)
		{
			k=i;
			while(2*k<=length || 2*k+1<=length)
			{
				j=k;
				k=*(q+2*k)<*(q+2*k+1)?2*k:2*k+1;
				
				if(*(q+k)<*(q+j))
				{
					temp=*(q+j);
					*(q+j)=*(q+k);
					*(q+k)=temp;
				}
				else
				    break;
			}
		}
		--i;
	}
}

template<class T>
void MinHeap<T>::HeapSort()
{
	int i,l=length;
	
	for(i=1;i<=l;i++)
	    Delete();
	
	cout<<"\nAfter HeapSort :\n";
	for(i=1;*(q+i)!=INT_MAX;i++)
	    cout<<*(q+i)<<"  ";
	
    cout<<endl;
}

template<class T>
void MinHeap<T>::Display()
{
	int i;
	
	cout<<"\n-------------------------------------------------------------------------\n\n";
	cout<<"Size Of The MinHeap Is : "<<size;
	cout<<"\nTotal Number Of Elements In MinHeap Are : "<<length;
	cout<<"\n\nMinHeap Is As Follows : \n";
	for(i=1;i<=length;i++)
	    cout<<*(q+i)<<"  ";
	cout<<"\n\n-------------------------------------------------------------------------\n";
}

template<class T>
MinHeap<T>::~MinHeap()
{
	delete []q;
}

