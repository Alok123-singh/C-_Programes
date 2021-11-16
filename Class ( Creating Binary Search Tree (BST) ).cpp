#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

class Node
{
    public:
	    int data;
		Node *lchild;
		Node *rchild;
		
		Node();
		Node(int data);	
};

class Stack
{
    private:
	    int last;
	    Node **q;
	    int size;
	public:
		Stack();
		Stack(int size);
		void setlast(int last);
		void setsize(int size);
		int getlast();
		int getsize();
		Node ** getq();
		void Push(Node *key);
		Node * Pop();
		Node * StackTop();
		bool isEmpty();
		bool isFull();
		~Stack(); 
};

class BST
{
    private:
        Node *root;
        int ne;
	public:
	    BST();
	    void setne(int ne);
	    Node * getroot();
	    int getne();
	    void CreateBSTFromPreorder(int pre[],int n);
	    void CreateBSTFromPostorder(int post[],int n);
	    void IInsert(int key);
	    Node * RInsert(Node *p,int key);
	    Node * RDelete(Node *p,int key);
	    Node * RSearch(Node *p,int key);
	    Node * ISearch(int key);
	    int Height(Node *p);
	    Node *IInpre(Node *p);
	    Node *RInpre(Node *p);
	    Node *IInsucc(Node *p);
	    Node *RInsucc(Node *p);
	    void Preorder(Node *root);
	    void Inorder(Node *root);
	    void Postorder(Node *root);
		~BST();	
};

int main()
{
	BST B;
	
	B.IInsert(2);
	B.IInsert(1);
	B.IInsert(3);
	
	B.RDelete(B.getroot(),1);
	
	cout<<endl<<"Inorder : ";
	B.Inorder(B.getroot());
	cout<<endl;
	
	return(0);
}

Node::Node()
{
	data=0;
	lchild=rchild=NULL;
}

Node::Node(int data)
{
	this->data=data;
	lchild=rchild=NULL;
}

Stack::Stack()
{
	last=-1;
	size=16;
	q=new Node*[size];
}

Stack::Stack(int size)
{
	last=-1;
	this->size=size;
	q=new Node*[size];
}

void Stack::setlast(int last)
{
	this->last=last;
}

void Stack::setsize(int size)
{
	this->size=size;
	last=-1;
	delete []q;
	q=new Node*[size];
}

int Stack::getlast()
{
	return (last);
}

int Stack::getsize()
{
	return size;
}

Node ** Stack::getq()
{
	return(q);
}

void Stack::Push(Node *key)
{
	if(last==size-1)
	    cout<<"\nStack Overflow\n";
	else
	{
		last++;
		*(q+last)=key;
	}
}

Node * Stack::Pop()
{
	Node *p=NULL;
	
	if(last==-1)
	    cout<<"\nStack Underflow\n";
	else
	{
		p=*(q+last);
		last--;
	}
	return(p);
}

Node * Stack::StackTop()
{
	Node *p=NULL;
	
	if(last!=-1)
	    p=*(q+last);
	
	return (p);
}

bool Stack::isEmpty()
{
	if(last==-1)
	    return(true);
	return(false);
}

bool Stack::isFull()
{
	if(last==size-1)
	    return(true);
	return(false);
}

Stack::~Stack()
{
	delete []q;
}

BST::BST()
{
	root=NULL;
	ne=0;
}

void BST::setne(int ne)
{
	this->ne=ne;
}

Node * BST::getroot()
{
	return(root);
}

int BST::getne()
{
	return(ne);
}

void BST::CreateBSTFromPreorder(int pre[],int n)
{
	Node *p=NULL,*temp=NULL;
	int i=0;
	Stack stk(n);
	
	temp=new Node;
	temp->data=*(pre+i++);
	p=root=temp;
	
	while(i<n)
	{
		if(*(pre+i)<p->data)
		{
			temp=new Node;
			temp->data=*(pre+i++);
			p->lchild=temp;
			stk.Push(temp);
			p=temp;
			ne++;
		}
		else
		{
		    if(*(pre+i) > p->data && *(pre+i) < (stk.isEmpty() ? INT_MAX : stk.StackTop()->data))
		    {
			    temp=new Node;
			    temp->data=*(pre+i++);
			    p->rchild=temp;
			    stk.Push(temp);
			    p=temp;
			    ne++;
		    }
		    else
		        p=stk.Pop();
        }
	}
}

void BST::CreateBSTFromPostorder(int post[],int n)
{
    Node *p=NULL,*temp=NULL;
	int i=n-1;
	Stack stk(n);
	
	temp=new Node;
	temp->data=*(post+i--);
	p=root=temp;
	
	while(i>=0)
	{
		if(*(post+i)>p->data)
		{
			temp=new Node;
			temp->data=*(post+i--);
			p->rchild=temp;
			p=temp;
			stk.Push(temp);
			ne++; 
		}
		else
		{
			if(*(post+i) < p->data && *(post+i) > (stk.isEmpty() ? INT_MIN : stk.StackTop()->data))
			{
				temp=new Node;
                temp->data=*(post+i--);
				p->lchild=temp;
				p=temp;
				stk.Push(temp);
				ne++;				
			}
			else
			    p=stk.Pop();
		}
	}
}

void BST::IInsert(int key)
{
	Node *p=root,*q=NULL;
	Node *temp=new Node(key);
	if(root==NULL)
    {
    	root=temp;
    	ne++;
		return;
	}
	while(p!=NULL)
	{
		q=p;
		if(key==p->data)
		    return;
		else if(key<p->data)
            p=p->lchild;
        else
            p=p->rchild;
	}
	if(key<q->data)
	    q->lchild=temp;
	else
	    q->rchild=temp;
	ne++;
}

Node * BST::RInsert(Node *p,int key)
{
	if(p==NULL)
	{
		Node *temp=new Node(key);
		if(root==NULL)
		    root=temp;
		ne++;
		return(temp);
	}
	
	if(key==p->data)
	    return(p);
	
	else if(key<p->data)
	    p->lchild=RInsert(p->lchild,key);
	
	else if(key>p->data)
	    p->rchild=RInsert(p->rchild,key);
	
	return(p);
}

Node * BST::RDelete(Node *p,int key)
{
	Node *q=NULL;
	
	if(p==NULL)
	    return(NULL);
	
	if(p->lchild==NULL && p->rchild==NULL)
	{
		if(root==p)
		    root=NULL;
		delete p;
		ne--;
		return(NULL);
	}
	
	if(key<p->data)
	    p->lchild=RDelete(p->lchild,key);
	
	else if(key>p->data)
	    p->rchild=RDelete(p->rchild,key);
	
	else
	{
	    if(Height(p->lchild)>Height(p->rchild))
		{
			q=IInpre(p->lchild);
			p->data=q->data;
			p->lchild=RDelete(p->lchild,q->data);
		}
		else
		{
			q=IInsucc(p->rchild);
			p->data=q->data;
			p->rchild=RDelete(p->rchild,q->data);
		}
	}
	
	return(p);
}

Node * BST::RSearch(Node *p,int key)
{
	if(p==NULL)
	    return(NULL);
	
	if(key==p->data)
	    return(p);
	
	else if(key<p->data)
	    return(RSearch(p->lchild,key));
	
	else if(key>p->data)
	    return(RSearch(p->rchild,key));
}

Node * BST::ISearch(int key)
{
	Node *p=root;
	
	while(p!=NULL)
	{
		if(key==p->data)
		    return(p);
	    
	    else if(key<p->data)
	        p=p->lchild;
	    
	    else if(key>p->data)
	        p=p->rchild;
	}
	return(NULL);
}

int BST::Height(Node *p)
{
	int x,y;
	
	if(p)
	{
		x=Height(p->lchild);
		y=Height(p->rchild);
		
		if(x>y)
		    return(x+1);
		else
		    return(y+1);
	}
	return(0);
}

Node * BST::IInpre(Node *p)
{	
	while(p->rchild!=NULL)
	    p=p->rchild;
	
	return(p);
}

Node * BST::RInpre(Node *p)
{
	if(p->rchild==NULL)
	    return(p);
	
	return RInpre(p->rchild);
}

Node * BST::IInsucc(Node *p)
{
	while(p->lchild!=NULL)
	    p=p->lchild;
	
	return(p);
}

Node * BST::RInsucc(Node *p)
{
	if(p->lchild==NULL)
	    return (p);
	
	return (RInsucc(p->lchild));
}

void BST::Preorder(Node *root)
{
	if(root)
	{
	    cout<<root->data<<"  ";
	    Preorder(root->lchild);
	    Preorder(root->rchild);
    }
}

void BST::Inorder(Node *root)
{
	if(root)
	{
	    Inorder(root->lchild);
	    cout<<root->data<<"  ";
	    Inorder(root->rchild);
    }
}

void BST::Postorder(Node *root)
{
	if(root)
	{
	    Postorder(root->lchild);
	    Postorder(root->rchild);
	    cout<<root->data<<"  ";
    }
}

BST::~BST()
{
	delete root;
}


