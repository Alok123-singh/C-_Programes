#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
class Node
{
    public:
	    T data;
		int height;
		Node<T> *lchild;
		Node<T> *rchild;
		
		Node();
		Node(T data,int height);	
};

template<class T>
class AVL
{
	private:
		Node<T> *root;
		int ne;
	public:
		AVL();
		void setne(int ne);
		Node<T> * getroot();
		int getne();
		Node<T> * RInsert(Node<T> *p,T key);
		Node<T> * RDelete(Node<T> *p,T key);
		int BalanceFactor(Node<T> *p);
		int NodeHeight(Node<T> *p);
		Node<T> * RInpre(Node<T> *p);
		Node<T> * RInsucc(Node<T> *p);
		Node<T> * IInpre(Node<T> *p);
		Node<T> * IInsucc(Node<T> *p);
		int Height(Node<T> *p);
		Node<T> * LLRotation(Node<T> *p);
		Node<T> * LRRotation(Node<T> *p);
		Node<T> * RRRotation(Node<T> *p);
		Node<T> * RLRotation(Node<T> *p);
		void Preorder(Node<T> *p);
		void Inorder(Node<T> *p);
		void Postorder(Node<T> *p);
		~AVL();
};

int main()
{
    AVL<float> avl;
	
	avl.RInsert(avl.getroot(),5.5);
	avl.RInsert(avl.getroot(),2.2);
	avl.RInsert(avl.getroot(),1.1);
	avl.RInsert(avl.getroot(),3.3);
	avl.RInsert(avl.getroot(),8.8);
	avl.RInsert(avl.getroot(),6.6);
	avl.RInsert(avl.getroot(),10.1);
	avl.RInsert(avl.getroot(),9.9);
	
	cout<<"\nBefore Deletion :\n";
	cout<<"\nInorder : ";
	avl.Inorder(avl.getroot());
	cout<<endl;
	
	avl.RDelete(avl.getroot(),5.5);
	avl.RDelete(avl.getroot(),3.3);
	avl.RDelete(avl.getroot(),2.2);
	
	cout<<"\nAfter Deletion :\n";
	cout<<"\nInorder : ";
	avl.Inorder(avl.getroot());
	cout<<endl;
	
	return(0);
}

template<class T>
Node<T>::Node()
{
	data=0;
	height=1;
	lchild=rchild=NULL;
}

template<class T>
Node<T>::Node(T data,int height)
{
	this->data=data;
	this->height=height;
	lchild=rchild=NULL;
}

template<class T>
AVL<T>::AVL()
{
	root=NULL;
	ne=0;
}

template<class T>
void AVL<T>::setne(int ne)
{
	this->ne=ne;
}

template<class T>
Node<T> * AVL<T>::getroot()
{
	return(root);
}

template<class T>
int AVL<T>::getne()
{
	return(ne);
}

template<class T>
int AVL<T>::BalanceFactor(Node<T> *p)
{
	int hl,hr;
	
	hl=(p && p->lchild)?p->lchild->height:0;
	hr=(p && p->rchild)?p->rchild->height:0;
	
	return(hl-hr);
}

template<class T>
int AVL<T>::NodeHeight(Node<T> *p)
{
	int hl,hr;
	
	hl=(p && p->lchild)?p->lchild->height:0;
	hr=(p && p->rchild)?p->rchild->height:0;
	
	return (hl>hr?hl+1:hr+1);
}

template<class T>
int AVL<T>::Height(Node<T> *p)
{
	int x,y;
	
	if(p!=NULL)
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

template<class T>
Node<T> * AVL<T>::IInpre(Node<T> *p)
{
	while(p->rchild)
	    p=p->rchild;
	
	return(p);
}

template<class T>
Node<T> * AVL<T>::IInsucc(Node<T> *p)
{
	while(p->lchild)
	    p=p->lchild;
	
	return(p);
}

template<class T>
Node<T> * AVL<T>::RInpre(Node<T> *p)
{
	if(p->rchild==NULL)
	    return(p);
	
	return RInpre(p->rchild);
}

template<class T>
Node<T> * AVL<T>::RInsucc(Node<T> *p)
{
	if(p->lchild==NULL)
	    return(p);
	
	return RInsucc(p->lchild);
}

template<class T>
Node<T> * AVL<T>::LLRotation(Node<T> *p)
{
	Node<T> *q=p->lchild;
	
	p->lchild=q->rchild;
	q->rchild=p;
	
	p->height=NodeHeight(p);
	q->height=NodeHeight(q);
	
	if(root==p)
	    root=q;
	
	return(q);
}

template<class T>
Node<T> * AVL<T>::LRRotation(Node<T> *p)
{
	Node<T> *q=p->lchild,*r=p->lchild->rchild;
	
	q->rchild=r->lchild;
	p->lchild=r->rchild;
	r->lchild=q;
	r->rchild=p;
	
	p->height=NodeHeight(p);
	q->height=NodeHeight(q);
	r->height=NodeHeight(r);
	
	if(root==p)
	    root=r;
	
	return(r);
}

template<class T>
Node<T> * AVL<T>::RRRotation(Node<T> *p)
{
	Node<T> *q=p->rchild;
	
	p->rchild=q->lchild;
	q->lchild=p;
	
	p->height=NodeHeight(p);
	q->height=NodeHeight(q);
	
	if(root==p)
	    root=q;
	
	return(q);
}

template<class T>
Node<T> * AVL<T>::RLRotation(Node<T> *p)
{
	Node<T> *q=p->rchild,*r=p->rchild->lchild;
	
	p->rchild=r->lchild;
	q->lchild=r->rchild;
	r->lchild=p;
	r->rchild=q;
	
	p->height=NodeHeight(p);
	q->height=NodeHeight(q);
	r->height=NodeHeight(r);
	
	if(root==p)
	    root=r;
	
	return(r);
}

template<class T>
void AVL<T>::Preorder(Node<T> *p)
{
	if(p)
	{
	    cout<<p->data<<"  ";
	    Preorder(p->lchild);
	    Preorder(p->rchild);
    }
}

template<class T>
void AVL<T>::Inorder(Node<T> *p)
{
	if(p)
	{
	    Inorder(p->lchild);
	    cout<<p->data<<"  ";
	    Inorder(p->rchild);
    }
}

template<class T>
void AVL<T>::Postorder(Node<T> *p)
{
	if(p)
	{
	    Postorder(p->lchild);
	    Postorder(p->rchild);
	    cout<<p->data<<"  ";
    }
}

template<class T>
Node<T> * AVL<T>::RInsert(Node<T> *p,T key)
{
	if(p==NULL)
	{
		Node<T> *temp=new Node<T>(key,1);
		
		if(root==NULL)
		    root=temp;
		ne++;
		return(temp);
	}
	
	if(key==p->data)
	    return(p);
	
	else if(key<p->data)
	    p->lchild=RInsert(p->lchild,key);
	
	else
	    p->rchild=RInsert(p->rchild,key);
	
	p->height=NodeHeight(p);
	
	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
	    return LLRotation(p);
	
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
	    return LRRotation(p);
	
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
	    return RRRotation(p);
	
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
	    return RLRotation(p);
	
	return(p);
}

template<class T>
Node<T> * AVL<T>::RDelete(Node<T> *p,T key)
{
	Node<T> *q=NULL;
	
	if(p==NULL)
	    return(p);
	
	if(p->lchild==NULL && p->rchild==NULL)
	{
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
	
	p->height=NodeHeight(p);
	
	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1) // L1 Rotation
	    return LLRotation(p);
	
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1) // L-1 Rotation
	    return LRRotation(p);
	
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0) // L0 Rotation
	    return LLRotation(p); // or LRRotation(p);
	
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1) // R-1 Rotation
	    return RRRotation(p);
	
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1) // R1 Rotation
        return RLRotation(p);
    
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0) // R0 Rotation
        return RRRotation(p); // or RLRotation(p);
    
    return(p);
}

template<class T>
AVL<T>::~AVL()
{
	delete root;
}

