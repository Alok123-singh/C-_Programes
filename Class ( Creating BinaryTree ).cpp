#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

using namespace std;

template<class T>
class Node
{
    public:
	    T data;
		Node *lchild;
		Node *rchild;
		
		Node();
		Node(T data);	
};

template<class T>
class Stack
{
    private:
	    int last;
	    int size;
	    Node<T> **q;
	public:
		Stack();
		Stack(int size);
		Stack(Stack<T> &stk);
		void setlast(int last);
		void setsize(int size);
		int getlast();
		int getsize();
		Node<T> ** getq();
		void Push(Node<T> *key);
		Node<T> * Pop();
		bool isEmpty();
		bool isFull();
		~Stack();
};

template<class T>
class Queue
{
    private:
	    int front;
		int rear;
		int size;
		Node<T> **q;
	public:
	    Queue();
		Queue(int size);
		Queue(Queue<T> &Q);
        void setfront(int front);
        void setrear(int rear);
        void setsize(int size);
        int getfront();
        int getrear();
        int getsize();
        Node<T> ** getq();
		void Enqueue(Node<T> *key);
		Node<T> * Dequeue();
		bool isEmpty();
		bool isFull();
		~Queue();
};

template<class T>
class BinaryTree
{
    private:
	    Node<T> *root;
		int ne;
	public:
	    BinaryTree();
		void setroot(Node<T> *root);
		void setne(int ne);
		Node<T> * getroot();
		int getne();
		void CreateTree();
		void Preorder(Node<T> *root);
		void IPreorder1();
		void IPreorder2();
		void Inorder(Node<T> *root);
		void IInorder();
		void Postorder(Node<T> *root);
		void IPostorder();
		void Levelorder();
		int CountExternalNodes(Node<T> *root);
		int CountInternalNodes(Node<T> *root);
		int CountNodesDegree1(Node<T> *root);
		int CountMaximumDegreeNodes(Node<T> *root);
		int CountTotalNodes(Node<T> *root);
		int Height(Node<T> *root);
		template<class P>
		friend istream & operator>>(istream &i,BinaryTree<P> &BT);
		~BinaryTree();
};

template<class T>
istream & operator>>(istream &i,BinaryTree<T> &BT)
{
	Node<T> *p=NULL,*q=NULL;
	
	cout<<"\nEnter Total Number Of Elements In The Binary Tree :\n";
	i>>BT.ne;
	
	Queue<T> Q(BT.ne);
	
	cout<<"\nEnter Data In All The Node Of The Binary Tree :\n";
	
    p=new Node<T>;
	cout<<"\nEnter Data In Root Node :\n";
	i>>p->data;
	BT.root=p;
	Q.Enqueue(p);
	
	while(!Q.isEmpty())
	{
		q=Q.Dequeue();
		
		p=new Node<T>;
		cout<<"\nEnter Data In left Child Of "<<q->data<<endl;
		i>>p->data;
		if(p->data!=-1)
		{
		    q->lchild=p;
		    Q.Enqueue(p);
	    }
	    
		p=new Node<T>;
		cout<<"\nEnter Data In Right Child Of "<<q->data<<endl;
		i>>p->data;
		if(p->data!=-1)
		{
		    q->rchild=p;
		    Q.Enqueue(p);
        }
	}
	return(i);
}

int main()
{
	BinaryTree<int> BT;
	
	cin>>BT; // BT.CreateTree();
	
	BT.Levelorder();
	
	return(0);
}

template<class T>
Node<T>::Node()
{
	data=0;
	lchild=rchild=NULL;
}

template<class T>
Node<T>::Node(T data)
{
	this->data=data;
	lchild=rchild=NULL;
}

template<class T>
Stack<T>::Stack()
{
	last=-1;
	size=16;
	q=new Node<T>*[size];
}

template<class T>
Stack<T>::Stack(int size)
{
	last=-1;
	this->size=size;
    q=new Node<T>*[size];	
}

template<class T>
Stack<T>::Stack(Stack<T> &stk)
{
	size=stk.size;
	q=new Node<T>*[size];
	
	for(last=0;last<=stk.last;last++)
	    *(q+last)=*(stk.q+last);
}

template<class T>
void Stack<T>::setlast(int last)
{
	this->last=last;
}

template<class T>
void Stack<T>::setsize(int size)
{
	this->size=size;
	delete []q;
	last=-1;
	q=new Node<T>*[size];
}

template<class T>
int Stack<T>::getlast()
{
	return(last);
}

template<class T>
int Stack<T>::getsize()
{
	return(size);
}

template<class T>
Node<T> ** Stack<T>::getq()
{
	return(q);
}

template<class T>
void Stack<T>::Push(Node<T> * key)
{
	if(last==size-1)
	    cout<<"\nStack Overflow\n";
	else
	{
		last++;
		*(q+last)=key;
	}
}

template<class T>
Node<T> * Stack<T>::Pop()
{
	Node<T> *x=NULL;
	
	if(last==-1)
	    cout<<"\nStack Underflow\n";
    else
    {
    	x=*(q+last);
    	last--;
	}
	return(x);
}

template<class T>
bool Stack<T>::isEmpty()
{
	if(last==-1)
	    return(true);
	return(false);
}

template<class T>
bool Stack<T>::isFull()
{
	if(last==size-1)
	    return(true);
	
}

template<class T>
Stack<T>::~Stack()
{
	delete []q;
}

template<class T>
Queue<T>::Queue()
{
	size=16;
	front=rear=-1;
	q=new Node<T>*[size];
}

template<class T>
Queue<T>::Queue(int size)
{
	this->size=size;
	front=rear=-1;
	q=new Node<T>*[size];
}

template<class T>
Queue<T>::Queue(Queue<T> &Q)
{
	size=Q.size;
	front=Q.front;
	rear=front;
	q=new Node<T>*[size];

	do
	{
		rear=(rear+1)%size;
		*(q+rear)=*(Q.q+rear);
	}while((rear+1)%size!=front);
}

template<class T>
void Queue<T>::setfront(int front)
{
	this->front=front;
}

template<class T>
void Queue<T>::setrear(int rear)
{
	this->rear=rear;
}

template<class T>
void Queue<T>::setsize(int size)
{
	this->size=size;
	front=rear=-1;
	delete []q;
	q=new Node<T>*[size];
}

template<class T>
int Queue<T>::getfront()
{
	return(front);
}

template<class T>
int Queue<T>::getrear()
{
	return(rear);
}

template<class T>
int Queue<T>::getsize()
{
	return(size);
}

template<class T>
Node<T> ** Queue<T>::getq()
{
	return(q);
}

template<class T>
void Queue<T>::Enqueue(Node<T> *key)
{
	if((rear+1)%size==front)
	    cout<<"\nQueue Overflow\n";
	else
	{
		rear=(rear+1)%size;
		*(q+rear)=key;
	}
}

template<class T>
Node<T> * Queue<T>::Dequeue()
{
    Node<T> * p=NULL;
	
	if(front==rear)
	    cout<<"\nQueue Underflow\n";
	else
	{
	    front=(front+1)%size;
		p=*(q+front);	
	}
	return(p);
}

template<class T>
bool Queue<T>::isEmpty()
{
	if(front==rear)
	    return(true);
	return(false);
}

template<class T>
bool Queue<T>::isFull()
{
	if((rear+1)%size==front)
	    return (true);
	return (false);
}

template<class T>
Queue<T>::~Queue()
{
	delete []q;
}

template<class T>
BinaryTree<T>::BinaryTree()
{
	ne=0;
	root=NULL;
}

template<class T>
void BinaryTree<T>::setne(int ne)
{
	this->ne=ne;
}

template<class T>
void BinaryTree<T>::setroot(Node<T> *root)
{
	this->root=root;
}

template<class T>
int BinaryTree<T>::getne()
{
	return(ne);
}

template<class T>
Node<T> * BinaryTree<T>::getroot()
{
	return(root);
}

template<class T>
void BinaryTree<T>::CreateTree()
{
	Node<T> *p=NULL,*q=NULL;
	
	cout<<"\nEnter Total Number Of Elements In The Binary Tree :\n";
	cin>>ne;
	
	Queue<T> Q(ne);
	
	cout<<"\nEnter Data In All The Node Of The Binary Tree :\n";
	
    p=new Node<T>;
	cout<<"\nEnter Data In Root Node :\n";
	cin>>p->data;
	root=p;
	Q.Enqueue(p);
	
	while(!Q.isEmpty())
	{
		q=Q.Dequeue();
		
		p=new Node<T>;
		cout<<"\nEnter Data In left Child Of "<<q->data<<endl;
		cin>>p->data;
		if(p->data!=-1)
		{
		    q->lchild=p;
		    Q.Enqueue(p);
	    }
	    
		p=new Node<T>;
		cout<<"\nEnter Data In Right Child Of "<<q->data<<endl;
		cin>>p->data;
		if(p->data!=-1)
		{
		    q->rchild=p;
		    Q.Enqueue(p);
        }
	}
}

template<class T>
void BinaryTree<T>::Preorder(Node<T> *root)
{
	if(root)
	{
	    cout<<root->data<<"  ";
	    Preorder(root->lchild);
	    Preorder(root->rchild);
    }
}

template<class T>
void BinaryTree<T>::Inorder(Node<T> *root)
{
	if(root)
	{
		Inorder(root->lchild);
		cout<<root->data<<"  ";
		Inorder(root->rchild);
	}
}

template<class T>
void BinaryTree<T>::Postorder(Node<T> *root)
{
	if(root)
	{
		Postorder(root->lchild);
		Postorder(root->rchild);
		cout<<root->data<<"  ";
	}
}

template<class T>
void BinaryTree<T>::IPreorder1()
{
	Node<T> *p=root;
	Stack<T> stk(ne);
	
	cout<<"\nPreorder Traversal : ";
	
	while(p!=NULL || !stk.isEmpty())
	{
		if(p)
		{
			cout<<p->data<<"  ";
			stk.Push(p);
			p=p->lchild;
		}
		else
		{
			p=stk.Pop();
			p=p->rchild;
		}
	}
	cout<<endl;
}

template<class T>
void BinaryTree<T>::IPreorder2()
{
	Node<T> *p=NULL;
	Stack<T> stk(ne);
	
	stk.Push(root);
	
	cout<<"\nPreorder Traversal : ";
	while(!stk.isEmpty())
	{
		p=stk.Pop();
		cout<<p->data<<"  ";
		if(p->lchild)
		{
			if(p->rchild)
			    stk.Push(p->rchild);
			stk.Push(p->lchild);
		}
		else if(p->rchild)
		    stk.Push(p->rchild);
	}
	cout<<endl;
}

template<class T>
void BinaryTree<T>::IInorder()
{
	Node<T> *p=root;
	Stack<T> stk(ne);
	
	cout<<"\nInorder Traversal : ";
	
	while(p!=NULL || !stk.isEmpty())
	{
		if(p)
		{
			stk.Push(p);
			p=p->lchild;
		}
		else
		{
			p=stk.Pop();
			cout<<p->data<<"  ";
			p=p->rchild;
		}
	}
	cout<<endl;
}

template<class T>
void BinaryTree<T>::Levelorder()
{
	Node<T> *p=root;
	Queue<T> Q(ne);
	
	cout<<"\nLevelorder Traversal : ";
	cout<<p->data<<"  ";
	Q.Enqueue(p);
	
	while(!Q.isEmpty())
	{
		p=Q.Dequeue();
		
		if(p->lchild)
		{
			cout<<p->lchild->data<<"  ";
			Q.Enqueue(p->lchild);
		}
		
		if(p->rchild)
		{
			cout<<p->rchild->data<<"  ";
            Q.Enqueue(p->rchild);
		}
	}
	cout<<endl;
}

template<class T>
void BinaryTree<T>::IPostorder()
{
	
}

template<class T>
int BinaryTree<T>::CountTotalNodes(Node<T> *root)
{
	int x,y;
	
	if(root)
	{
		x=CountTotalNodes(root->lchild);
		y=CountTotalNodes(root->rchild);
		return(x+y+1);
	}
	return(0);
}

template<class T>
int BinaryTree<T>::CountMaximumDegreeNodes(Node<T> *root)
{
	int x,y;
	
	if(root)
	{
		x=CountMaximumDegreeNodes(root->lchild);
		y=CountMaximumDegreeNodes(root->rchild);
		
		if(root->lchild && root->rchild)
		    return(x+y+1);
		else
		    return(x+y);
	}
	return(0);
}

template<class T>
int BinaryTree<T>::CountNodesDegree1(Node<T> *root)
{
	int x,y;
	
	if(root)
	{
		x=CountNodesDegree1(root->lchild);
		y=CountNodesDegree1(root->rchild);
		
		if((root->lchild && root->rchild==NULL) || (root->lchild==NULL && root->rchild))
	        return(x+y+1);
	    else
	        return(x+y);
	}
	return(0);
}

template<class T>
int BinaryTree<T>::CountInternalNodes(Node<T> *root)
{
	int x,y;
	
	if(root)
	{
		x=CountInternalNodes(root->lchild);
		y=CountInternalNodes(root->rchild);
		if(root->lchild || root->rchild)
		    return(x+y+1);
		else
		    return(x+y);
	}
	return(0);
}

template<class T>
int BinaryTree<T>::CountExternalNodes(Node<T> *root)
{
	int x,y;
	
	if(root)
	{
		x=CountExternalNodes(root->lchild);
		y=CountExternalNodes(root->rchild);
		
		if(root->lchild==NULL && root->rchild==NULL)
		    return(x+y+1);
		else
		    return(x+y);
	}
	return(0);
}

template<class T>
int BinaryTree<T>::Height(Node<T> *root)
{
	int x,y;
	
	if(root)
	{
		x=Height(root->lchild);
		y=Height(root->rchild);
		
		if(x>y)
		    return(x+1);
		else
		    return(y+1);
	}
	return(0);
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	
}

