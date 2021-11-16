#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

template<class T>
class MaxHeap
{
    private:
	    T *q;
		int size;
		int length;
	public:
	    MaxHeap();
		MaxHeap(int size);
		MaxHeap(MaxHeap<T> &mh);
		void setsize(int size);
		void setlength(int length);
		T * getq();
		int getsize();
		int getlength();
		void Insert(T key);
		T Delete();
		void HeapSort();
		void CreateMaxHeap();
		void Heapify();
		bool isEmpty();
		bool isFull();
		void Display();
		template<class P>
		friend ostream & operator<<(ostream &o,MaxHeap<P> &mh);
		template<class P>
		friend istream & operator>>(istream &in,MaxHeap<P> &mh);
		~MaxHeap();	
};

template<class P>
ostream & operator<<(ostream &o,MaxHeap<P> &mh)
{
	int i;
	
	o<<"\n------------------------------------------------------------------------\n\n";
	o<<"Size Of The MaxHeap Is : "<<mh.size;
	o<<"\nTotal Number Of Elements In MaxHeap Are : "<<mh.length;
	o<<"\n\nMaxHeap Is As Follows : \n";
	for(i=1;i<=mh.length;i++)
	    o<<*(mh.q+i)<<"  ";
	o<<"\n\n-------------------------------------------------------------------------\n";
	
	return(o);
}

template<class T>
istream & operator>>(istream &in,MaxHeap<T> &mh)
{
	int i,j,k;
	T temp;
	
	cout<<"\nEnter Size Of The MaxHeap :\n";
	in>>mh.size;
	delete []mh.q;
	mh.q=new T[mh.size];
	cout<<"\nEnter Total Number Of Elements In MaxHeap : \n";
	in>>mh.length;
	
	for(i=1;i<mh.size;i++)
	    *(mh.q+i)=-1;
	
	for(i=1;i<=mh.length;i++)
	{
		cout<<"\nEnter "<<i<<" Element :\n";
		in>>*(mh.q+i);
	}
	
	i=mh.length;
	while(i>=1)
	{
		if(*(mh.q+2*i)!=-1 || *(mh.q+2*i+1)!=-1)
		{
			k=i;
			while(2*k<=mh.length || 2*k+1<=mh.length)
			{
				j=k;
				k=*(mh.q+2*k)>*(mh.q+2*k+1)?2*k:2*k+1;
				
				if(*(mh.q+j)<*(mh.q+k))
				{
					temp=*(mh.q+j);
					*(mh.q+j)=*(mh.q+k);
					*(mh.q+k)=temp;
				}
				else
				    break;
			}
		}
		i--;
	}
	return(in);
}

int main()
{
	MaxHeap<float> mh;
	
	cin>>mh;
	
	cout<<mh;
	
	mh.HeapSort();
	
	return(0);
}

template<class T>
MaxHeap<T>::MaxHeap()
{
	int i;
	
	size=16;
	length=0;
	q=new T[size];
    
    for(i=1;i<size;i++)
        *(q+i)=-1;
}

template<class T>
MaxHeap<T>::MaxHeap(int size)
{
	int i;
	
	this->size=size;
	length=0;
	q=new T[size];
	
	for(i=1;i<size;i++)
	    *(q+i)=-1;
}

template<class T>
MaxHeap<T>::MaxHeap(MaxHeap<T> &mh)
{
	int i;
	
	size=mh.size;
	q=new T[size];
	
	for(length=1;length<=mh.length;length++)
	    *(q+i)=*(mh.q+i);
	
	for(i=length+1;i<size;i++)
	    *(q+i)=-1;
}

template<class T>
void MaxHeap<T>::setlength(int length)
{
	this->length=length;
}

template<class T>
void MaxHeap<T>::setsize(int size)
{
	int i;
	
	this->size=size;
	delete []q;
	length=0;
	q=new T[size];
	
	for(i=1;i<size;i++)
	    *(q+i)=-1;
}

template<class T>
T * MaxHeap<T>::getq()
{
	return(q);
}

template<class T>
int MaxHeap<T>::getlength()
{
	return(length);
}

template<class T>
int MaxHeap<T>::getsize()
{
	return(size);
}

template<class T>
void MaxHeap<T>::Insert(T key)
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
			
			if(*(q+i)<*(q+j))
			{
				temp=*(q+i);
				*(q+i)=*(q+j);
				*(q+j)=temp;
			}
			else
			    break;
		}
		length++;
	}
}

template<class T>
T MaxHeap<T>::Delete()
{
	T del=-1,temp;
	T *p=new T[size];
	int i,j;
	
	for(i=0;i<size;i++)
	    *(p+i)=-1;
	
	for(i=0,j=length+1;*(q+j)!=-1;i++,j++)
	    *(p+i)=*(q+j);
	
	for(i=length+1;*(q+i)!=-1;i++)
	    *(q+i)=-1;
	
	if(length==0)
	    cout<<"\nHeap Underflow\n";
	else
	{
		del=*(q+1);
		*(q+1)=*(q+length);
		*(q+length)=-1;
		i=1;
		
		while((*(q+2*i)!=-1 || *(q+2*i+1)!=-1) && (2*i<size || 2*i+1<size))
		{
			j=i;
			i=*(q+2*i)>*(q+2*i+1)?2*i:2*i+1;
			
			if(*(q+j)<*(q+i))
			{
				temp=*(q+j);
				*(q+j)=*(q+i);
				*(q+i)=temp;
			}
			else
			    break;
		}
		
		*(q+length)=del;
		length--;
	}
	
	for(i=0,j=length+2;*(p+i)!=-1;i++,j++)
	    *(q+j)=*(p+i);
	
	return(del);
}

template<class T>
void MaxHeap<T>::HeapSort()
{
	int i,l=length;
	
	for(i=1;i<=l;i++)
	    Delete();
	
	cout<<"\nAfter Heapsort : ";
	for(i=1;*(q+i)!=-1;i++)
	    cout<<*(q+i)<<"  ";
	
	cout<<endl;
}

template<class T>
void MaxHeap<T>::Heapify()
{
	int i,j,k;
	T temp;
	
	cout<<"\nEnter Size Of The MaxHeap :\n";
	cin>>size;
	delete []q;
	q=new T[size];
	cout<<"\nEnter Total Number Of Elements In MaxHeap : \n";
	cin>>length;
	
	for(i=1;i<size;i++)
	    *(q+i)=-1;
	
	for(i=1;i<=length;i++)
	{
		cout<<"\nEnter "<<i<<" Element :\n";
		cin>>*(q+i);
	}
	
	i=length;
	while(i>=1)
	{
		if(*(q+2*i)!=-1 || *(q+2*i+1)!=-1)
		{
			k=i;
			while(2*k<=length || 2*k+1<=length)
			{
				j=k;
				k=*(q+2*k)>*(q+2*k+1)?2*k:2*k+1;
				
				if(*(q+j)<*(q+k))
				{
					temp=*(q+j);
					*(q+j)=*(q+k);
					*(q+k)=temp;
				}
				else
				    break;
			}
		}
		i--;
	}
}

template<class T>
void MaxHeap<T>::CreateMaxHeap()
{
	int i,ne;
	T temp;
	
	cout<<"\nEnter Size Of The MaxHeap :\n";
	cin>>size;
	delete []q;
	q=new T[size];
	cout<<"\nEnter Total Number Of Elements In MaxHeap :\n";
	cin>>ne;
	
	for(i=1;i<size;i++)
	    *(q+i)=-1;
    
    for(i=1;i<=ne;i++)
    {
    	cout<<"\nEnter "<<i<<" Element :\n";
    	cin>>temp;
    	Insert(temp);
	}
}

template<class T>
bool MaxHeap<T>::isEmpty()
{
	if(length==0)
	    return(true);
	return(false);
}

template<class T>
bool MaxHeap<T>::isFull()
{
	if(length==size-1)
	    return(true);
	return(false);
}

template<class T>
void MaxHeap<T>::Display()
{
	int i;
	
	cout<<"\n------------------------------------------------------------------------\n\n";
	cout<<"Size Of The MaxHeap Is : "<<size;
	cout<<"\nTotal Number Of Elements In MaxHeap Are : "<<length;
	cout<<"\n\nMaxHeap Is As Follows : \n";
	for(i=1;i<=length;i++)
	    cout<<*(q+i)<<"  ";
	cout<<"\n\n-------------------------------------------------------------------------\n";
}

template<class T>
MaxHeap<T>::~MaxHeap()
{
	delete []q;
}

