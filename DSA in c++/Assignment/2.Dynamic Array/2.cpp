#include<iostream>
using namespace std;

class DynArray
{
    int capacity;
    int lastIndex;
    int *p;
    void halfArray()
    {
        if(capacity==1)
            cout<<"\nCan't half the Array";
        else{
        int *p2=new int[capacity/2];
        if(lastIndex>(capacity/2-1))
            lastIndex=capacity/2-1;
        capacity/=2;
        for(int i=0; i<=capacity; i++)
            p2[i]=p[i];
        delete []p;
        p=p2;
        }
    }

    void doubleArray()
    {
        int *p1=new int[2*capacity];
        for(int i=0; i<=capacity; i++)
            p1[i]=p[i];
        delete []p;
        p=p1;
        capacity*=2;
    }

    public:
    DynArray(int size)
    {
        if(size<0)
            cout<<"\nInvalid Array size";
        else
        {
            lastIndex=-1;
            capacity=size;
            p=new int[capacity];
        }
    }

bool checkFull()
    {
        return (capacity-1)==lastIndex;
    }

    bool checkArray()
    {
        if(lastIndex>=0)
            return 1;
        else
            return 0;
    }

    void append(int data)
    {
        if(checkFull())
            doubleArray();
        lastIndex++;
        p[lastIndex]=data;
    }

    void insert(int index, int data)
    {
        if(index<0 || index > lastIndex+1)
            cout<<"\nCan't insert data at given index";
        else
        {
            if(checkFull())
                doubleArray();
             for(int i=lastIndex; i>=index; i--)
                p[i+1]=p[i];
             p[index]=data;
             lastIndex++;
        }
    }

    void edit(int index, int data)
    {
        if(index<0 || index > lastIndex)
            cout<<"Can't edit data at given index";
        else{
                p[index]=data;
        }
    }

    void deleteElement(int index)
    {
        if(index<0 || index>lastIndex)
            cout<<"Can't delete the data at given index";
        else{
            for(int i=index; i<lastIndex; i++)
                p[i]=p[i+1];
            lastIndex--;
            if(capacity>1 &&lastIndex<=capacity/2-1)   // <= because , suppose capacity=7;  but only 2 is filled.when you delete one then only one element is left, so that size has to be also reduced.vcapacity>1 because imagine if there is only one block and only one data , and when you delete it   lastIndex=-1, capacity=1  and  lastIndex<=capacity/2-1; is still true but can't half a array of 1 size
                halfArray();
        }
    }

    int currentCapacity()
    {
        if(lastIndex<0)
            throw "NO ARRAY EXISTS";
        return capacity;
    }

    int getElement(int index)
    {
        if(index<0 || index>lastIndex)
            throw "Can't find Element at the given index";
        return p[index];
    }

    int count()
    {
        if(!checkArray())
            throw "Array is Empty ";
        return lastIndex+1;
    }

    ~DynArray()
    {
        delete []p;
    }

    int findElement(int index)
    {
        if(index<0 || index>lastIndex)
            throw "No element exists at that index";
        for(int i=0; i<=lastIndex; i++)
        {
            if(p[i]==p[index])
                return i;
        } 
                return -1;   
    }

    DynArray& operator=(DynArray &a)
    {
        capacity=a.capacity;
        lastIndex=a.lastIndex;
        int *p=new int[capacity];
        for(int i=0; i<=lastIndex; i++)
            p[i]=a.p[i];
        return *this;
    }
};

int main()
{

    return 0;
}