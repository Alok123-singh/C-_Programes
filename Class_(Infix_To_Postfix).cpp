#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

using namespace std;

template<class T>
class Node
{
	public:
		T data;
		Node *next;
		
		Node();
		Node(T data);
};

template<class T>
class Stack
{
	private:
		Node<T> *first;
		Node<T>  *last;
		int ne;
	public:
		Stack();
	    void setfirst(Node<T> *first);
		void setlast(Node<T> *last);
		void setne(int ne);
		Node<T> *getfirst();
		Node<T> * getlast();
		int getne();
		void Push(T key);
		T Pop();
		T StackTop();
		bool isEmpty();
		bool isFull(); 
		~Stack();
};

bool isBalanced(char *infix)
{
	Stack<char> stk;
	int i;
	
	if(*(infix)!='(')
	    return(false);
	
	for(i=0;*(infix+i)!='\0';i++)
	{
		if(*(infix+i)=='(')
			stk.Push(*(infix+i));
		else if(*(infix+i)==')')
		{
			if(stk.isEmpty())
			    return(false);
			stk.Pop();
		}
	}
	
	return(stk.isEmpty()?true:false);
}

bool isOperand(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='(' || ch==')')
	    return(false);
	
	return(true);
}

int Prec(char ch)
{
	if(ch=='+' || ch=='-')
	    return(1);
	
	else if(ch=='*' || ch=='/')
	    return(2);
	
	return(-1);
}

char * InfixToPostfix(char *infix)
{
	char *postfix;
	int i=0,j=0;
	Stack<char> stk;
	
	postfix=new char[strlen(infix)];
	
	while(*(infix+i)!='\0')
	{
		if(isOperand(*(infix+i)))
			*(postfix+j++)=*(infix+i++);
		
		else if(stk.isEmpty() || Prec(*(infix+i))>Prec(stk.StackTop()))
			stk.Push(*(infix+i++));
		
		else if(Prec(*(infix+i))<=Prec(stk.StackTop()))
		    *(postfix+j++)=stk.Pop();
	}
	
	while(!stk.isEmpty())
	    *(postfix+j++)=stk.Pop();
	
	*(postfix+j)='\0';
	
	return(postfix);
}

int OutStackPrec(char ch)
{
	if(ch=='+' || ch=='-')
	    return(1);
	
	else if(ch=='*' || ch=='/')
	    return(3);
	
	else if(ch=='^')
	    return(6);
	
	else if(ch=='(')
	    return(7);
	
	else if(ch==')')
	    return(0);
	
	return(-1);    
}

int InStackPrec(char ch)
{
	if(ch=='+' || ch=='-')
	    return(2);
	
	else if(ch=='*' || ch=='/')
	    return(4);
	
	else if(ch=='^')
	    return(5);
	
	else if(ch=='(')
	    return(0);
	
	return(-1);
}

char * InfixToPostfixWithBrackets(char *infix)
{
	Stack<char> stk;
	int i=0,j=0;
	char *postfix=NULL;
	
	postfix=new char[strlen(infix)];
	
	while(*(infix+i)!='\0')
	{
		if(isOperand(*(infix+i)))
			*(postfix+j++)=*(infix+i++);
		
		else if(stk.isEmpty() || OutStackPrec(*(infix+i))>InStackPrec(stk.StackTop()))
		    stk.Push(*(infix+i++));
		
		else if(OutStackPrec(*(infix+i))<InStackPrec(stk.StackTop()))
		    *(postfix+j++)=stk.Pop();
		
		else if(OutStackPrec(*(infix+i))==InStackPrec(stk.StackTop()))
		{
			stk.Pop();
			i++;
		}
	}
	
	while(!stk.isEmpty())
	    *(postfix+j++)=stk.Pop();
	
	*(postfix+j)='\0';
    
    return(postfix);
}

long double EvaluatePostfix(char *postfix)
{
	Stack<long double> stk;
	int i=0;
	long double res,x,y;
	
	while(*(postfix+i)!='\0')
	{
		if(isOperand(*(postfix+i)))
		    stk.Push(*(postfix+i++)-'0');
		
		else
		{
			y=stk.Pop();
			x=stk.Pop();
			
			if(*(postfix+i)=='+')
			    res=x+y;
			
			else if(*(postfix+i)=='-')
			    res=x-y;
			
			else if(*(postfix+i)=='*')
			    res=x*y;
			
			else if(*(postfix+i)=='/')
			    res=x/y;
			
			else if(*(postfix+i)=='^')
			    res=pow(x,y);
			
			stk.Push(res);
			i++;
		}
	}
	
	return(stk.Pop());
}

int main()
{
	char infix[40]="((a+b)-c)+d^e^f",*postfix=NULL;
	long double eval;
	
	//cout<<"\nEnter The Infix Form :\n";
	//cin>>infix;
	
	if(isBalanced(infix))
	    cout<<"\nBalanced\n";
	else
	    cout<<"\nNot Balanced\n";
	
	postfix=InfixToPostfixWithBrackets(infix);
	
	cout<<"\nPostfix Form : "<<postfix;
	cout<<endl;
	
	eval=EvaluatePostfix(postfix);
	cout<<fixed<<setprecision(10)<<"\nEvaluated Value : "<<eval<<endl;
	
	return(0);
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
Stack<T>::Stack()
{
	first=last=NULL;
	ne=0;
}

template<class T>
void Stack<T>::setfirst(Node<T> *first)
{
	this->first=first;
}

template<class T>
void Stack<T>::setlast(Node<T> *last)
{
	this->last=last;
}

template<class T>
void Stack<T>::setne(int ne)
{
	this->ne=ne;
}

template<class T>
Node<T> * Stack<T>::getfirst()
{
	return(first);
}

template<class T>
Node<T> * Stack<T>::getlast()
{
	return(last);
}

template<class T>
int Stack<T>::getne()
{
	return(ne);
}

template<class T>
void Stack<T>::Push(T key)
{
	Node<T> *p=new Node<T>(key);
	
	if(p==NULL)
	    cout<<"\nStack Overflow\n";
	else
	{
		if(first==NULL)
		    first=last=p;
		else
		{
			last->next=p;
			last=p;
		}
		ne++;
	}
}

template<class T>
T Stack<T>::Pop()
{
	T x=0;
	Node<T> *p=first;
	
	if(first==NULL)
	    cout<<"\nStack Underflow\n";
	else
	{
		x=last->data;
		
		if(first==last)
		{
			delete first;
			first=last=NULL;
		}
		else
		{
		    while(p->next!=last)
		        p=p->next;
		    last=p;
		    delete p->next;
		    p->next=NULL;
	    }
	    --ne;
	}
	return(x);
}

template<class T>
T Stack<T>::StackTop()
{
	T x=0;
	
	if(first!=NULL)
		x=last->data;
    
	return(x);
}

template<class T>
bool Stack<T>::isEmpty()
{
	if(first==NULL)
	    return(true);
	return(false);
}

template<class T>
bool Stack<T>::isFull()
{
	Node<T> *test=new Node<T>;
	
	if(test==NULL)
	    return(true);
	return(false);
}

template<class T>
Stack<T>::~Stack()
{
	Node<T> *p=first,*q=NULL;
	
	while(q!=last)
	{
		q=p;
		p=p->next;
		delete q;
	}
}

