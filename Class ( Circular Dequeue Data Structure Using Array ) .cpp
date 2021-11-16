#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

using namespace std;

template<class T>
class CircularQueue
{
    private:
		int front;
		int rear;
		int size;
		T *q;
		
	public:
		CircularQueue();
		CircularQueue(int size);
		CircularQueue(CircularQueue<T> &q);
		void setsize(int size);
		void setarrayandsize(T *q,int size);
		int getsize();
		T * getq();
		int getfront();
		int getrear();
		void create();
		void Enqueue(T x);
	    T Dequeue();
	    bool isEmpty();
	    bool isFull();
	    T Front();
	    T Rear();
	    void Display();
		~CircularQueue();	
};

int main()
{
	CircularQueue<int> cq(5);
	
	cq.Enqueue(12);
	cq.Enqueue(24);
	cq.Enqueue(36);
	cq.Enqueue(48);
	
	cq.Dequeue();
	
	cq.Enqueue(60);
	
	cq.Display();
	
	return(0);
}

template<class T>
CircularQueue<T>::CircularQueue()
{
	front=rear=0;
	size=16;
	q=new int[16];
	
	for(int i=1;i<16;i++)
	    *(q+i)=0;
}

template<class T>
CircularQueue<T>::CircularQueue(int size)
{
	front=rear=0;
	this->size=size;
	q=new int[size];
	
	for(int i=1;i<size;i++)
	    *(q+i)=0;
}

template<class T>
CircularQueue<T>::CircularQueue(CircularQueue<T> &q)
{
	this->front=q.front;
	this->rear=q.rear;
	this->size=q.size;
	this->q=new int[size];
	
	for(int i=1;i<size;i++)
	    *(this->q+i)=0;
}

template<class T>
void CircularQueue<T>::setsize(int size)
{
	delete []q;
	this->size=size;
	
	front=rear=0;
	
	for(int i=1;i<size;i++)
	    *(q+i)=0;
}

template<class T>
void CircularQueue<T>::setarrayandsize(T *q,int size)
{
	delete []q;
	this->q=q;
	front=rear=0;
	this->size=size;
}

template<class T>
int CircularQueue<T>::getsize()
{
	return(size);
}

template<class T>
T * CircularQueue<T>::getq()
{
	return(q);
}

template<class T>
void CircularQueue<T>::create()
{	
	cout<<"Enter Size Of The Queue :\n";
	cin>>size;
	
	delete []q;
	q=new int[size];
	
	front=rear=0;
	
	cout<<"Enter Information About Element Of The Queue :\n";
	for(int i=1;i<size;i++)
	{
		cout<<"\nEnter "<<i<<" Element :\n";
		cin>>*(q+i);
		rear=(rear+1)%size;
	}
}

template<class T>
void CircularQueue<T>::Display()
{
	int x,size;
	
	if(rear>front)
	    size=rear-front;
	    
	else if(rear<front)
	    size=this->size-front+rear;
	
	cout<<"\n--------------------------------------------------------\n\n";
	cout<<"Size Of The Queue Is : "<<size<<endl<<endl;
	
	cout<<"Queue Is As Follows :\n\n";
	if(rear<front)
	    x=size;
	else
	    x=rear;
	
	for(int i=front+1;i<=x;i++)
	    cout<<*(q+i)<<" ";
	
	if(rear<front) 
	{
	    for(int j=0;j<=rear;j++)
	        cout<<*(q+j)<<" ";
    }
    
	cout<<"\n\n--------------------------------------------------------\n";
}

template<class T>
void CircularQueue<T>::Enqueue(T x)
{
	if((rear+1)%size==front)
	{
		cout<<"\nQueue Overflow\n";
		return;
	}
	
	else
	{
		rear=(rear+1)%size;
		*(q+rear)=x;
	}
}

template<class T>
T CircularQueue<T>::Dequeue()
{
	T x=0;
	
	if(front==rear)
		cout<<"\nQueue Underflow\n";
	
	else
	{
		front=(front+1)%size;
		x=*(q+front);
	}
	
	return(x);
}

template<class T>
bool CircularQueue<T>::isEmpty()
{
	if(rear==front)
	    return(true);
	    
	return (false);
}

template<class T>
bool CircularQueue<T>::isFull()
{
	if((rear+1)%size==front)
	    return(true);
	    
	return(false);
}

template<class T>
T  CircularQueue<T>::Front()
{
	return(*(q+(front+1)%size));
}

template<class T>
T CircularQueue<T>::Rear()
{
	return(*(q+rear));
}

template<class T>
CircularQueue<T>::~CircularQueue()
{
	delete []q;
}
