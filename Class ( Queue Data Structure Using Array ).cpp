#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

template<class T>
class Queue
{
	private:
		int front;
		int rear;
		int size;
		T *q;
		
	public:
		Queue();
		Queue(int size);
		Queue(Queue<T> &q);
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
		~Queue();
};

int main()
{
	Queue<int> q(5);
	
	q.Enqueue(12);
	q.Enqueue(24);
	q.Enqueue(36);
	q.Enqueue(48);
	q.Enqueue(60);
	
	q.Display();
	
	return(0);
}

template<class T>
Queue<T>::Queue()
{
	front=rear=-1;
	size=16;
	q=new int[16];
	
	for(int i=0;i<16;i++)
	    *(q+i)=0;
}

template<class T>
Queue<T>::Queue(int size)
{
	front=rear=-1;
	this->size=size;
	q=new int[size];
	
	for(int i=0;i<size;i++)
	    *(q+i)=0;
}

template<class T>
Queue<T>::Queue(Queue<T> &q)
{
	this->front=q.front;
	this->rear=q.rear;
	this->size=q.size;
	this->q=new int[size];
	
	for(int i=0;i<size;i++)
	    *(this->q+i)=0;
}

template<class T>
void Queue<T>::setsize(int size)
{
	delete []q;
	this->size=size;
	
	front=rear=-1;
	
	for(int i=0;i<size;i++)
	    *(q+i)=0;
}

template<class T>
void Queue<T>::setarrayandsize(T *q,int size)
{
	delete []q;
	this->q=q;
	front=rear=-1;
	this->size=size;
}

template<class T>
int Queue<T>::getsize()
{
	return(size);
}

template<class T>
T *  Queue<T>::getq()
{
	return(q);
}

template<class T>
void Queue<T>::create()
{	
	cout<<"Enter Size Of The Queue :\n";
	cin>>size;
	
	delete []q;
	q=new int[size];
	
	front=rear=-1;
	
	cout<<"Enter Information About Element Of The Queue :\n";
	for(int i=0;i<size;i++)
	{
		cout<<"\nEnter "<<i+1<<" Element :\n";
		cin>>*(q+i);
		rear++;
	}
}

template<class T>
void Queue<T>::Display()
{
	cout<<"\n--------------------------------------------------------\n\n";
	cout<<"Size Of The Queue Is : "<<rear-front<<endl<<endl;
	
	cout<<"Queue Is As Follows :\n\n";
	for(int i=front+1;i<=rear;i++)
	    cout<<*(q+i)<<" ";
	
	cout<<"\n\n--------------------------------------------------------\n";
}

template<class T>
void Queue<T>::Enqueue(T x)
{
	if(rear==size-1)
	{
		cout<<"\nQueue Overflow\n";
		return;
	}
	
	else
	{
		rear++;
		*(q+rear)=x;
	}
}

template<class T>
T Queue<T>::Dequeue()
{
	T x=0;
	
	if(front==rear)
		cout<<"\nQueue Underflow\n";
	
	else
	{
		front++;
		x=*(q+front);
		*(q+front)=0;
	}
	
	return(x);
}

template<class T>
bool Queue<T>::isEmpty()
{
	if(rear==front)
	    return(true);
	    
	return (false);
}

template<class T>
bool Queue<T>::isFull()
{
	if(rear==size-1)
	    return(true);
	    
	return(false);
}

template<class T>
T  Queue<T>::Front()
{
	return(*(q+front+1));
}

template<class T>
T Queue<T>::Rear()
{
	return(*(q+rear));
}

template<class T>
Queue<T>::~Queue()
{
	delete []q;
}
