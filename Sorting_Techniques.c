#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int I(int **A)
{
	int n,i1;
	
	printf("\nEnter The Lenght Of Array :\n");
	scanf("%d",&n);
	
	*A=(int *)malloc(n*sizeof(int));
	
	printf("\nEnter Elements In Array :\n");
	for(i1=0;i1<n;i1++)
	{
		printf("\nEnter %d Element :\n",i1+1);
		scanf("%d",*A+i1);
	}
	return(n);
}

void Swap(int *a,int *b)
{
	int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
}

void BubbleSort(int A[],int n)
{
	int i,j;
	int flag;
	
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(*(A+j)>*(A+j+1))
			{
				Swap(A+j,A+j+1);
				flag=1;
			}
		}
		if(flag==0)
		    break;
	}
}

void InsertionSort(int A[],int n)
{
	int i,j,x;
	
	for(i=1;i<n;i++)
	{
		j=i-1;
		x=*(A+i);
		while(j>=0 && *(A+j)>x)
		{
			*(A+j+1)=*(A+j);
			j--;
		}
		*(A+j+1)=x;
	}
}

void SelectionSort(int A[],int n)
{
	int i,j,k;
	
	for(i=0;i<n-1;i++)
	{
		for(k=j=i;j<n;j++)
		{
			if(*(A+j)<*(A+k))
			    k=j;
		}
		Swap(A+i,A+k);
	}
}

int Partition(int A[],int l,int h)
{
	int i=l,j=h;
	int pivot=*(A+l);
	
	do
	{
		do{i++;}while(*(A+i)<=pivot);
		do{j--;}while(*(A+j)>pivot);
		
		if(i<j)
		    Swap(A+i,A+j);
	}while(i<j);
	Swap(A+l,A+j);
	return (j);
}

void QuickSort(int A[],int l,int h)
{
	int j;
	
	if(l<h)
	{
		j=Partition(A,l,h);
		QuickSort(A,l,j);
		QuickSort(A,j+1,h);
	}
}

void MergeTwoListWithinOneArray(int A[],int l,int mid,int h)
{
	int i,j,k;
	int i1;
	int *C=NULL;
	
	k=l;
	i=l;
	j=mid+1;
	
	C=(int *)malloc((h+1)*sizeof(int));
	
	while(i<=mid && j<=h)
	{
		if(*(A+i)<*(A+j))
		    *(C+k++)=*(A+i++);
		    
		else if(*(A+i)>*(A+j))
		    *(C+k++)=*(A+j++);
	}
	
	for(;i<=mid;i++)
	    *(C+k++)=*(A+i);
	
	for(;j<=h;j++)
	    *(C+k++)=*(A+j);
	
    for(i1=l;i1<=h;i1++)
	    *(A+i1)=*(C+i1);	
}

int MergeTwoList(int **C,int A[],int n1,int B[],int n2)
{
	int i,j,k;
	i=j=k=0;
	
	*C=(int *)malloc((n1+n2)*sizeof(int));
	
	while(i<n1 && j<n2)
	{
		if(*(A+i)<*(B+j))
		    *(*C+k++)=*(A+i++);
		    
		else if(*(A+i)>*(B+j))
		    *(*C+k++)=*(B+j++);
	}
	
	for(;i<n1;i++)
	    *(*C+k++)=*(A+i);
	
	for(;j<n2;j++)
	    *(*C+k++)=*(B+j);
	
	return(k);
}

int MergeFourList(int **G,int A[],int n1,int B[],int n2,int C[],int n3,int D[],int n4)
{
	int k1,k2,k3;
	int *E=NULL;
	int *F=NULL;
	//int i1,j1,i2,j2,i3,j3;
	
	k1=MergeTwoList(&E,A,n1,B,n2);
	k2=MergeTwoList(&F,C,n3,D,n4);
	k3=MergeTwoList(G,E,k1,F,k2);
	
    /*
	i1=j1=k1=0;
	
	E=(int *)malloc((n1+n2)*sizeof(int));
	
	while(i1<n1 && j1<n2)
	{
	    if(*(A+i1)<*(B+j1))
		    *(E+k1++)=*(A+i1++);
			
		else if(*(A+i1)>*(B+j1))
		    *(E+k1++)=*(B+j1++);	
	}
	
	for(;i1<n1;i1++)
	    *(E+k1++)=*(A+i1);
	
	for(;j1<n2;j1++)
	    *(E+k1++)=*(B+j1);
	    
	i2=j2=k2=0;
	
	F=(int *)malloc((n3+n4)*sizeof(int));
	
	while(i2<n3 && j2<n4)
	{
		if(*(C+i2)<*(D+j2))
		    *(F+k2++)=*(C+i2++);
		    
	    else if(*(C+i2)>*(D+j2))
	        *(F+k2++)=*(D+j2++);
	}
	
	for(;i2<n3;i2++)
	    *(F+k2++)=*(C+i2);
	
	for(;j2<n4;j2++)
	    *(F+k2++)=*(D+j2);
	    
	i3=j3=k3=0;
	
	*G=(int *)malloc((k1+k2)*sizeof(int));
	
	while(i3<k1 && j3<k2)
	{
		if(*(E+i3)<*(F+j3))
		    *(*G+k3++)=*(E+i3++);
		    
		else if(*(E+i3)>*(F+j3))
		    *(*G+k3++)=*(F+j3++);
	}
	
	for(;i3<k1;i3++)
	    *(*G+k3++)=*(E+i3);
	
	for(;j3<k2;j3++)
	    *(*G+k3++)=*(F+j3);
	*/
	return(k3);
}

void IMergeSort(int A[],int n)
{
	int p,i,l,mid,h;
	
	for(p=2;p<=n;p=p*2)
	{
		for(i=0;i+p-1<=n;i+=p)
		{
			l=i;
			h=i+p-1;
			mid=(l+h)/2;
			MergeTwoListWithinOneArray(A,l,mid,h);
		}
	}
	if(p/2<n)
	    MergeTwoListWithinOneArray(A,0,p/2-1,n-1);
}

void RMergeSort(int A[],int l,int h)
{
	if(l<h)
	{
		int mid;
		
		mid=(l+h)/2;
		RMergeSort(A,l,mid);
		RMergeSort(A,mid+1,h);
		MergeTwoListWithinOneArray(A,l,mid,h);
	}
}

int findMax(int A[],int n)
{
	int max=INT_MIN,i;
	
	for(i=0;i<n;i++)
	{
		if(*(A+i)>max)
		    max=*(A+i);
	}
	return(max);
}

void CountSort(int A[],int n)
{
	int i,j;
	int max;
	int *C=NULL;
	
	max=findMax(A,n);
	C=(int *)malloc((max+1)*sizeof(int));
	
	for(i=0;i<max+1;i++)
	    *(C+i)=0;
	
	for(j=0;j<n;j++)
	    (*(C+*(A+j)))++;
	
	i=j=0;
	while(i<max+1)
	{
		if(*(C+i)>0)
		{
			*(A+j++)=i;
		    (*(C+i))--;	
		}
		else
		    i++;
	}
}

struct Node
{
	int data;
	struct Node *next;
};

void Insert(struct Node **p,int key)
{
	struct Node *q=*p,*temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=key;
	temp->next=NULL;
	
	if(temp==NULL)
	{
		printf("\nElements Can Not Be Inserted\n");
		return;
	}
	
	if(*p==NULL)
		*p=temp;

	else
	{
		while(q->next!=NULL)
		    q=q->next;
		    
		q->next=temp;
	}
}

int Delete(struct Node **p)
{
	struct Node *q=*p,*test=NULL;
	int x=-1;
	
	test=(struct Node *)malloc(sizeof(struct Node));
	
	if(test==NULL)
		printf("\nElement can Not Be Deleted\n");
	else
	{
		*p=q->next;
		x=q->data;
		q->next=NULL;
		free(q);
	}
	return(x);
}

void BinSort(int A[],int n)
{
	int i,j,max;
	struct Node **Bins=NULL;
	
	max=findMax(A,n);
	
	Bins=(struct Node **)malloc((max+1)*sizeof(struct Node *));
	
	for(i=0;i<max+1;i++)
	    *(Bins+i)=NULL;
	    
	for(j=0;j<n;j++)
	    Insert(Bins+*(A+j),*(A+j));
	
	i=j=0;
	while(i<max+1)
	{
		while(*(Bins+i)!=NULL)
			*(A+j++)=Delete(Bins+i);
		
		i++;
	}
}

void RadixSort(int A[],int n)
{
	int div=1,i,j,max;
	struct Node **Bins=NULL;
	
	max=findMax(A,n);
	Bins=(struct Node **)calloc(10,sizeof(struct Node *));
	
	for(i=0;i<10;i++)
	    *(Bins+i)=NULL;
	do
	{
	    for(j=0;j<n;j++)
		    Insert(Bins+(*(A+j)/div)%10,*(A+j));
	    
	    i=j=0;
	    while(i<10)
	    {
		    while(*(Bins+i)!=NULL)
		    	*(A+j++)=Delete(Bins+i);
	    
		    i++;
		}
	    div*=10;
    }while(div<max);
}

void ShellSort(int A[],int n)
{
	int gap,i,j,temp;
	
	for(gap=n/2;gap>=1;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			temp=*(A+i);
			j=i-gap;
			while(j>=0 && *(A+j)>temp)
			{
				*(A+j+gap)=*(A+j);
				j=j-gap;
			}
			*(A+j+gap)=temp;
		}
	}
}

void Display(int A[],int n)
{
	int i;
	
	printf("\n-----------------------------------------------------------------------------------------------------\n\n");
	printf("Length Of The Array Is : %d\n\n",n);
	
	printf("Array Is As Follows : ");
	for(i=0;i<n;i++)
	    printf("%d  ",*(A+i));
	
	printf("\n\n-----------------------------------------------------------------------------------------------------\n");
}

int main()
{
	int *A,n1;
	
	n1=I(&A);
	
	ShellSort(A,n1);
	
	Display(A,n1);
	
	return(0);
}









