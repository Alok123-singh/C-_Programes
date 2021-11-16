#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Stack 
{
    struct Node *top;
	int len;	
};

void create(struct Stack *stk)
{
	struct Node *p=NULL,*temp=NULL;
	int l,i;
	
	stk->top=(struct Node *)malloc(sizeof(struct Node));
	
	printf("Enter The Length Of Stack :\n");
	scanf("%d",&stk->len);
	
	printf("Enter The Information About Elements In Stack :\n");
	
	if(stk->len==0)
	{
		stk->top=NULL;
		return;
	}
	
	printf("Enter 1 Element :\n");
	p=stk->top;
	scanf("%c",&p->data);
	p->next=NULL;
	
	for(i=1;i<stk->len;i++)
	{
		temp=(struct Node *)malloc(sizeof(struct Node));
		printf("\nEnter %d Element :\n",i+1);
		scanf("%c",&temp->data);
		temp->next=p->next;
		p->next=temp;
		p=temp;
	}
}

void I(struct Stack *stk,int size)
{
	struct Node *temp=NULL,*p=NULL;
	int i;
	
	stk->len=size;
	
	if(size==0)
	{
	    stk->top=NULL;
		return;
    }
	stk->top=(struct Node *)malloc(sizeof(struct Node));
	p=stk->top;
	p->data='0';
	p->next=NULL;
	
	for(i=1;i<size;i++)
	{
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->data='0';
		temp->next=p->next;
		p->next=temp;
		p=temp;
    }
}

void Push(struct Stack *stk,char x)
{
	struct Node *p=NULL,*test=NULL;
	
    test=(struct Node *)malloc(sizeof(struct Node));
    
    if(test==NULL)
    {
    	printf("\nStack Overflow\n");
    	return;
	}
	
	p=(struct Node *)malloc(sizeof(struct Node));
	p->data=x;
	p->next=stk->top;
	stk->top=p;
	++stk->len;
}

char Pop(struct Stack *stk)
{
	struct Node *temp=NULL;
	char x='0';
	
	if(stk->top==NULL)
	{
		printf("\nStack Underflow\n");
		return x;
	}
	
	temp=stk->top;
	stk->top=stk->top->next;
	x=temp->data;
	free(temp);
	
	return(x);
}

int countnodes(struct Node *p)
{
	int len=0;
	
	while(p!=NULL)
	{
		len++;
		p=p->next;
	}
	return(len);
}

char Peek(struct Stack *stk,int pos)
{
	struct Node *p=stk->top;
	char x='0',i;
	
	if(pos < 0 || pos > countnodes(p))
	{
		printf("\nPosition Is Not Valid\n");
		return(x);
	}
	
	for(i=1;i<pos;i++)
	    p=p->next;
	
	x=p->data;
	
	return(x);
}

bool isEmpty(struct Stack s)
{
	return s.top==NULL?true:false;
}

bool isFull(struct Stack s)
{
	struct Node *temp=NULL;
	temp=(struct Node *)malloc(sizeof(struct Node));
	
	return (temp==NULL?true:false);
}

void Display(struct Stack stk)
{
	struct Node *p=stk.top;
	
    printf("\n-----------------------------------------------\n\n");
	printf("Length Of The Stack Is : %d\n\n",stk.len);
	printf("Stack Is As Follows :\n");
	
	while(p!=NULL)
	{
	    printf("%c ",p->data);
	    p=p->next;
	}
	
	printf("\n\n-------------------------------------------------\n");
}

bool isOperand(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' ||ch=='/' || ch=='^' ||ch=='(' || ch==')')
	    return false;
	    
	return(true);
}

int prec(char ch)
{
	if(ch=='+' || ch=='-')
	    return(1);
	
	else if(ch=='*' || ch=='/')
	    return(2);
	
	return(0);
}

int precInfix(char ch)
{
    if(ch=='+' || ch=='-')
        return(1);
    
    else if(ch=='*' || ch=='/')
        return(3);
    
    else if(ch=='^')
        return(5);
    
    else if(ch=='(')
        return(7);
    
    else if(ch==')')
        return(0);
    
    return (-1);
}

int precStack(char ch)
{
    if(ch=='-' || ch=='+')
        return(2);
    
    else if(ch=='*' || ch=='/')
        return(4);
    
    else if(ch=='^')
        return(6);
    
    else if(ch=='(')
        return(0);
    
    return (-1);
}

char StackTop(struct Stack stk)
{
	char ch;
	
	if(stk.top==NULL)
	    ch='0';
	else 
	    ch=stk.top->data;
	    
	return(ch);
}

char * InfixToPostfix(char infix[])
{
	struct Stack st;
	int i=0,k=0;
	char *postfix=NULL;
	
	I(&st,0);
	
	postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
	
	while(*(infix+i)!='\0')
	{
		if(isOperand(infix[i]))
		    *(postfix+k++)=infix[i++];
		    
		else
		{
			if(prec(infix[i])>prec(StackTop(st)))
				Push(&st,infix[i++]);
				
			else 
				*(postfix+k++)=Pop(&st);
		}
	}
	
    while(!isEmpty(st))
        *(postfix+k++)=Pop(&st);	
	
	*(postfix+k)='\0';
	
	return(postfix);
}

char * InfixToPostfixWithBracket(char *infix)
{
	char *postfix=NULL;
	int i=0,j=0,len=strlen(infix);
	struct Stack s;
	
	I(&s,0);
	postfix=(char *)malloc((len+1)*sizeof(char));
	
	while(*(infix+i)!='\0')
	{
		if(isOperand(*(infix+i))) *(postfix+j++)=*(infix+i++);
		else 
		{
			if(precInfix(*(infix+i))>precStack(StackTop(s))) Push(&s,*(infix+i++));
			else
			{
				char x;
				x=Pop(&s);
				
				if(*(infix+i)==')' && x=='(') i++;
				
				if(x!='(') *(postfix+j++)=x;
			}
		}
	}
	
	while(!isEmpty(s)) *(postfix+j++)=Pop(&s);
	*(postfix+j)='\0';
	
	return(postfix);
}
/*
int EvaluatePostfix(char postfix[])
{
	int res,x,y,i;
	struct Stack stk;
	
	I(&stk,0);
	
	while(*(postfix+i)!='\0')
	{
		if(isOperand(*(postfix+i)))
		    Push(&stk,*(postfix+i++));
		    
		else
		{
			y=Pop(&stk)-'0';
			x=Pop(&stk)-'0';
			
			if(*(postfix+i)=='+')
			    res=x+y;
			    
			else if(*(postfix+i)=='-')
			    res=x-y;
			    
			else if(*(postfix+i)=='*')
			    res=x*y;
			    
			else if(*(postfix+i)=='/')
			    res=x/y;
			    
			Push(&stk,res);
		}
	} 
	
	return(Pop(&stk));
} */

int main()
{
	char infix[40];
	char *postfix=NULL;
	
	printf("\nEnter The Infix Form :\n");
	gets(infix);
	
	postfix=InfixToPostfixWithBracket(infix);
	
	printf("\nThe Postfix Form Of The Given Expression Is As Follows :\n");
	puts(postfix);
    
	//printf("\nThe Value Of This Postfix Expression Is %d\n",EvaluatePostfix(postfix));
		
	return(0);
}

