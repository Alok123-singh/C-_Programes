#include<iostream>                        /* Abstract Data Type In C++ Language */
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<cstdarg>

using namespace std;

class Array
{
 private:
    int *A;
    int size;
    int length;
    void swap(int *x,int *y);
 public:
    Array(); 
    Array(int size);
    Array(Array &a);
    void setlength(int length);
    void setsize(int size);
    int getlength();
    int getsize();
    void SetElements(int n,...);
    void I();
    void Add(int x);
    void Insert(int index,int x);
    void Display();
    void Delete(int index);
    int LinearSearch1(int key);
    int LinearSearch2(int key);
    int BinarySearch(int key);
    int RBinarySearch(int l,int h,int key);
    int Max();
    int Min();
    int Sum();
    float Average();
    int Get(int index);
    void Set(int index,int x);
    void Reverse1();
    void Reverse2();
    void LeftShift();
    void LeftRotation();
    void RightShift();
    void RightRotation();
    void InsertSort(int index,int x);
    bool IsSorted();
    void Negative_Positive();
    void Merge(Array a1,Array a2);
    void Append(Array a1);
    void Copy(Array a1);
    bool Compare(Array a2);
    void Concat(Array a1,Array a2);
    void Union_NotSorted(Array a1,Array a2);
    void Union_Sorted(Array a1,Array a2);
    void Intersection_NotSorted(Array a1,Array a2);
    void Intersection_Sorted(Array a1,Array a2);
    void Difference_NotSorted(Array a1,Array a2);
    void Difference_Sorted(Array a1,Array a2);
    void FindAllMissingElement_Sorted();
    void FindAllMissingElement_NotSorted();
    void FindAllDuplicateElement_Sorted();
    void FindAllDuplicateElement_NotSorted();
    void FindCountingOfEachDuplicateElement_Sorted1();
    void FindCountingOfEachDuplicateElement_Sorted2();
    void FindCountingOfEachDuplicateElement_NotSorted1();
    void FindCountingOfEachDuplicateElement_NotSorted2();
    void PairOfElementsOfAddition_Sum_NotSorted(int sum);
    void PairOfElementsOfAddition_Sum_SortedOrNotSorted(int sum);
    void PairOfElementsOfAddition_Sum_Sorted(int sum);
    void FindMaxMinInSingleScan();
    ~Array();
};

int main()
{
    Array arr1(20);
    arr1.SetElements(9,1,2,3,4,5,6,7,8,9);
    arr1.Display();
    arr1.PairOfElementsOfAddition_Sum_SortedOrNotSorted(10);
    return(0);
}

Array::Array()
{
    A=new int[16];
    size=16;
    length=0;
    for(int i=0;i<size;i++)
       *(A+i)=0;
}
Array::Array(int size)
{
    this->size=size;
    this->length=0;
    A=new int[size];
    for(int i=0;i<size;i++)
       *(A+i)=0;
}
Array::Array(Array &a)
{
    this->size=a.size;
    this->length=a.length;
    this->A=a.A;
}
void Array::setsize(int size)
{
    this->size=size;
    A=new int[size];
}
void Array::setlength(int length)
{
    this->length=length;
    int i;
    for(i=0;i<size;i++)
        *(A+i)=0;
}
int Array::getsize()
{
    return (size);
}
int Array::getlength()
{
    return(length);
}
void Array::SetElements(int n,...)
{
    va_list obj;
    va_start(obj,n);
    int i;
    for(i=0;i<n;i++)
        *(A+i)=va_arg(obj,int);
        
    length=n;
    va_end(obj);
} 
void Array::I()
{
    int l,s;
    int i,j;
    cout<<"Enter Size Of Array     : ";
    cin>>s;
    size=s;
    A=new int[size];
    cout<<"Enter Length Of Array   : ";
    cin>>l;
    length=l;
    cout<<"Enter Elements In Array :\n";
    for(i=0;i<length;i++)
    {
        cin>>*(A+i);
    }
    for(j=length;j<size;j++)
    {
        *(A+j)=0;
    }
}
void Array::Add(int x)
{
    if(length<size)
    {
        *(A+length)=x;
    }
    length++;
}
void Array::Insert(int index,int x)
{
    if(length<size&&index>=0&&index<=length)
    {
        int i;
        for(i=length;i>index;i--)
        {
            *(A+i)=*(A+i-1);
        }
        *(A+i)=x;
    }
    length++;
}
void Array::Display()
{
    cout<<"\n-------------------------------------------------------------------------------\n";
    cout<<"Size Of The Array   : "<<size<<endl;
    cout<<"Length Of The Array : "<<length<<endl;
    cout<<"Elements Are        : ";
    for(int i=0;i<length;i++)
    {
        cout<<*(A+i)<<" ";
    }
    cout<<"\n-------------------------------------------------------------------------------\n";
}
void Array::Delete(int index)
{
    int i;
    for(i=index;i<length-1;i++)
    {
        *(A+i)=*(A+i+1);
    }
    *(A+length-1)=0;
    length--;
}
void Array::swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int Array::LinearSearch1(int key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(*(A+i)==key)
        {
            swap(A+i,A+i-1);
            return i;
        }
    }
    return -1;
}
int Array::LinearSearch2(int key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(*(A+i)==key)
        {
            swap(A+i,A);
            return i;
        }
    }
    return -1; 
}
int Array::BinarySearch(int key)
{
    int l=0,h=length-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(*(A+mid)==key)
           return mid;
        if(key<*(A+mid))
           h=mid-1;
        if(key>*(A+mid))
           l=mid+1;
    }
    return -1;
}
int Array::RBinarySearch(int l,int h,int key)
{
    static int mid;
    if(l>h)
       return -1;
    
    mid=(l+h)/2;
    
    if(*(A+mid)==key)
       return mid;
    
    if(key<*(A+mid))
       return RBinarySearch(l,mid-1,key);
       
    if(key>*(A+mid))
       return RBinarySearch(mid+1,h,key);
}
int Array::Max()
{
    int i;
    int max=*A;
    for(i=1;i<length;i++)
    {
        if(*(A+i)>max)
           max=*(A+i);
    }
    return max;
}
int Array::Min()
{
    int i;
    int min=*A;
    for(i=1;i<length;i++)
    {
        if(*(A+i)<min)
           min=*(A+i);
    }
    return min;
}
int Array::Sum()
{
    int i;
    int sum=0;
    
    for(i=0;i<length;i++)
       sum+=*(A+i);
       
    return sum;
}
float Array::Average()
{
    return (float)Sum()/length;       
}
int Array::Get(int index)
{
    return *(A+index);
}
void Array::Set(int index,int x)
{
    *(A+index)=x;
}
void Array::Reverse1()
{
    int *a;
    a=new int[length];
    int i,j;
    for(i=length-1,j=0;j<length;i--,j++)
        *(a+j)=*(A+i);
    
    while(i<length)
    {
        *(A+j)=*(a+j);
        j++;    
    }       
}
void Array::Reverse2()
{
    int i;
    for(i=0;i<length;i++)
        swap(A+i,A+length-1-i);
}
void Array::LeftShift()
{
    int i;
    for(i=0;i<length-1;i++)
        *(A+i)=*(A+i+1);
        
    *(A+length-1)=0;
    length--;
}
void Array::LeftRotation()
{
    int i,x;
    x=*(A+length-1);
    for(i=0;i<length-1;i++)
        *(A+i)=*(A+i+1);
        
    *(A+length-1)=x;
}
void Array::RightShift()
{
    int i;
    for(i=length-1;i>0;i--)
        *(A+i)=*(A+i-1);
        
    *A=0;
}
void Array::RightRotation()
{
    int i,x;
    x=*(A+length-1);
    for(i=length-1;i>0;i--)
        *(A+i)=*(A+i-1);
        
    *A=x;
}
void Array::InsertSort(int index,int x)
{
    int i;
    for(i=length;i>index;i--)
        *(A+i)=*(A+i-1);
        
    *(A+i)=x;
}
bool Array::IsSorted()
{
    int i;
    for(i=0;i<length-1;i++)
    {
        if(*(A+i)>*(A+i+1)) break;
        if(i==length-2)
            return true;
    }
    return false;
}
void Array::Negative_Positive()
{
    int i,j;
    while(i<j)
    {
        while(*(A+i)<0) i++;
        while(*(A+j)>=0) j++;
        
        swap(A+i,A+j);
    }
}
void Array::Merge(Array a1,Array a2)
{
    int i,j,k;
    i=j=k=0;
    while(i<a1.length&&j<a2.length)
    {
        if(*(a1.A+i)<*(a2.A+j))
            *(A+k++)=*(a1.A+i++);
            
        else if(*(a2.A+j)<*(a1.A+i))
            *(A+k++)=*(a2.A+j++);
    }
    for(;i<a1.length;i++)
        *(A+k++)=*(a1.A+i);
        
    for(;j<a2.length;j++)
        *(A+k++)=*(a2.A+j);
        
    length=k;
}
void Array::Append(Array a1)
{
    int i,j;
    for(i=length,j=0;j<a1.length&&i<size;i++,j++)
        *(A+i)=*(a1.A+j);
        
    length=i;
}
void Array::Copy(Array a1)
{
    int i;
    for(i=0;i<length&&i<a1.length;i++)
        *(A+i)=*(a1.A+i);
        
    length=i;
}
bool Array::Compare(Array a1)
{
    if(length!=a1.length)
        return false;
        
    int i,j;
    for(int i=0;i<length;i++)
    {
        for(j=0;j<a1.length;j++)
        {
            if(*(A+i)!=*(a1.A+j))
                return false;
        }
    }
    return true;
}
void Array::Concat(Array a1,Array a2)
{
    int i;
    for(i=0;i<a1.length;i++)
        *(A+i)=*(a1.A+i);
        
    int j;
    for(j=0;j<a2.length;j++)
    {
        *(A+i)=*(a2.A+j);
        i++;
    }
    length=i;
}
void Array::Union_Sorted(Array a1,Array a2)
{
    int i,j,k;
    i=j=k=0;
    while(i<a1.length&&j<a2.length)
    {
        if(*(a1.A+i)<*(a2.A+j))
            *(A+k++)=*(a1.A+i++);
        
        else if(*(a2.A+j)<*(a1.A+i))
            *(A+k++)=*(a2.A+j++);
            
        if(*(a1.A+i)==*(a2.A+j))
        {
            *(A+k++)=*(a1.A+i++);
            j++;
        }
    }
    for(;i<a1.length;i++)
        *(A+k++)=*(a1.A+i);
        
    for(;j<a2.length;j++)
        *(A+k++)=*(a2.A+j);
        
       length=k; 
}
void Array::Union_NotSorted(Array a1,Array a2)
{
    int i;
    for(i=0;i<a1.length;i++)
        *(A+i)=*(a1.A+i);
        
    int j,k;
    for(j=0;j<a2.length;j++)
    {
        for(k=0;k<a1.length;k++)
        {
            if((*a2.A+j)==*(a1.A+k)) break;
            if(i==a1.length-1)
                *(A+i++)=*(a1.A+j);
        }
    }
    length=i;
}
void Array::Intersection_Sorted(Array a1,Array a2)
{
    int i,j,k;
    i=j=k=0;
    while(i<a1.length&&j<a2.length)
    {
        if(*(a1.A+i)<*(a2.A+j))
            i++;
            
        else if(*(a2.A+j)<*(a1.A+i))
            j++;
            
        else
        {
            *(A+k++)=*(a1.A+i++);
            j++;
        }
    }
    length=k;
}
void Array::Intersection_NotSorted(Array a1,Array a2)
{
    int i,j,k=0;
    for(i=0;i<a1.length;i++)
    {
        for(j=0;j<a2.length;j++)
        {
            if(*(a1.A+i)==*(a2.A+j))
                *(A+k++)=*(a1.A+i);
        }
    }
    length=k;
}
void Array::Difference_Sorted(Array a1,Array a2)
{
    int i,j,k;
    i=j=k=0;
    while(i<a1.length&&j<a2.length)
    {
        if(*(a1.A+i)<*(a2.A+j))
            *(A+k++)=*(a1.A+i++);
            
        else if(*(a2.A+j)<*(a1.A+i))
            j++;
            
        else
        {
            i++;
            j++;  
        }    
    }
    for(;i<a1.length;i++)
        *(A+k++)=*(a1.A+i);
        
    length=k;
}
void Array::Difference_NotSorted(Array a1,Array a2)
{
    int i,j,k=0;
    for(i=0;i<a1.length;i++)
    {
        for(j=0;j<a2.length;j++)
        {
            if(*(a1.A+i)==*(a2.A+j)) break;
            if(j==a2.length-1)
                *(A+k++)=*(a1.A+i);
        }
    }
    length=k;
}
void Array::FindAllMissingElement_Sorted()
{
    int i;
    int diff=*A;
    cout<<"\nMissing Elements In This Sorted Array : ";
    for(i=0;i<length;i++)
    {
        if(diff<(*(A+i)-i))
        {
            while(diff<(*(A+i)-i))
            { 
                cout<<(diff+i);
                diff++;
            }
        }
    }
    cout<<endl;
}
void Array::FindAllMissingElement_NotSorted()
{
    int *H;
    int min,max;
    min=Min();
    max=Max();
    int i,j,k;
    H=new int[max+1];
    for(i=0;i<=max;i++)
        *(H+i)=0;
    
    cout<<"\nMissing Elements In This Unsorted Array : ";
    for(j=0;j<length;j++)
        (*(H+*(A+i)))++;
        
    for(k=min;k<=max;k++)
    {
        if(*(H+k)=0)
            cout<<k<<" ";
    }
    cout<<endl;
}
void Array::FindAllDuplicateElement_Sorted()
{
    int i;
    typedef int lastelement;
    lastelement l=0;
    cout<<"\nDupliacte Elements In This Sorted Array : ";
    for(i=0;i<length-1;i++)
    {
        if(*(A+i)==*(A+i+1)&&*(A+i)!=l)
        {
            l=*(A+i);
            cout<<l<<" ";
        }
    }
    cout<<endl;
}
void Array::FindAllDuplicateElement_NotSorted()
{
    int *H;
    int max,min;
    int i,j,k;
    max=Max();
    min=Min();
    H=new int[max+1];
    for(i=0;i<=max;i++)
        *(H+i)=0;
    cout<<"\nTotal Duplicate Elements In This Unsorted Array : ";    
    for(j=0;j<length;j++)
        (*(H+*(A+j)))++;
        
    for(k=min;k<=max;k++)
    {
        if(*(H+k)>1)
            cout<<k<<" ";
    }
    cout<<endl;
}
void Array::FindCountingOfEachDuplicateElement_Sorted1()
{
    int i,j;
    cout<<"\nTotal Duplicate Elements in This Sorted Array :\n";
    for(i=0;i<length-1;i++)
    {
        if(*(A+i)==*(A+i+1))
        {
            j=i+1;
            while(*(A+i)==*(A+j)&&j<=length) j++;
            
            cout<<*(A+i)<<" is Appearing "<<j-i<<" times"<<endl;
            i=j-1;
        }
    }
    
}
void Array::FindCountingOfEachDuplicateElement_Sorted2()
{
    int *H;
    int max,min;
    int i,j,k;
    max=Max();
    min=Min();
    H=new int[max+1];
    for(i=0;i<=max;i++)
        *(H+i)=0;
        
    for(j=0;j<length;j++)
        (*(H+*(A+j)))++;

    cout<<"\nTotal Duplicate Elements in This Sorted Array :\n";
    for(k=min;k<=max;k++)
    {
        if(*(H+k)>2)
            cout<<k<<" is Appearing "<<*(H+k)<<" times"<<endl;
    }
}
void Array::FindCountingOfEachDuplicateElement_NotSorted1()
{
    int i,j;
    int count;
    cout<<"\nTotal Dupicate Elements in This Unsorted Array :\n";
    for(i=0;i<length-1&&*(A+i)!=-1;i++)
    {
        count=1;
        for(j=i+1;j<length;j++)
        {
            if(*(A+i)==*(A+j))
            {
                *(A+j)=-1;
                count++;
            }
        }
        if(count>1)
            cout<<*(A+i)<<" is Appearing "<<count<<" times\n";
    }
}
void Array::FindCountingOfEachDuplicateElement_NotSorted2()
{
    int *H;
    int max,min;
    int i,j,k;
    max=Max();
    min=Min();
    H=new int[max+1];
    for(i=0;i<=max;i++)
        *(H+i)=0;
    
    for(j=0;j<length;j++)
        *(H+*(A+j))+=1;
    
    cout<<"\nTotal Duplicates in This Unsorted Array :\n";
    for(k=min;k<=max;k++)
    {
        if(*(H+k)>2);
            cout<<k<<" is Appearing "<<*(H+k)<<" times\n";    
    } 
}
void Array::PairOfElementsOfAddition_Sum_NotSorted(int sum)
{
    int i,j;
    cout<<"\nPair Of Elements Of Total Sum="<<sum<<" Are : ";
    for(i=0;i<length-1;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if((*(A+i)+*(A+j))==sum)
                cout<<"("<<*(A+i)<<","<<*(A+j)<<") ";
        }
    }
    cout<<endl;
}
void Array::PairOfElementsOfAddition_Sum_SortedOrNotSorted(int sum)
{
    int i,j;
    int *H;
    int max;
    max=Max();
    H=new int[max+1];
    for(i=0;i<=max;i++)
        *(H+i)=0;
    
    cout<<"\nPair Of Elements Of Total Sum="<<sum<<" Are : ";
    for(j=0;j<length;j++)
    {
        if(*(H+(sum-*(A+j)))!=0)
            cout<<"("<<*(A+j)<<","<<sum-*(A+j)<<") ";
            
        (*(H+*(A+j)))++;
    }
    cout<<endl;
}
void Array::PairOfElementsOfAddition_Sum_Sorted(int sum)
{
    int i=0,j;
    j=length-1;
    cout<<"\nPair Of Elements Of Total Sum="<<sum<<" Are : ";
    while(i<j)
    {
        if((*(A+i)+*(A+j))>sum) j--;
        else if((*(A+i)+*(A+j))<sum) i++;
        else if((*(A+i)+*(A+j))==sum)
        {
            cout<<"("<<*(A+i)<<","<<*(A+j)<<") ";
            i++;
            j--;
        }
    }
    cout<<endl;
}
void Array::FindMaxMinInSingleScan()
{
    int i;
    int max,min;
    max=min=*A;
    for(i=1;i<length;i++)
    {
        if(*(A+i)<min)
            min=*(A+i);
        else if(*(A+i)>max)
            max=*(A+i);
    }
    cout<<"\nMinimum Element is "<<min<<" and Maximum Element is "<<max<<endl;
}

Array::~Array()
{
    delete []A;
}
