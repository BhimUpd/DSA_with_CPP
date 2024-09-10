#include<iostream>
#include<exception>
using namespace std;

class Array
{
    int capacity;
    int lastIndex;
    int *p;

    public:
    Array(int size)
    {
        if(size>0)
        {
        capacity=size;
        p=new int[capacity];
        lastIndex=-1; // because now array is not created. 
        }
        else
        p=NULL;
    }
    //copy constructor if user says Array a1=a2; or Array a1(a2); for deep copy
    Array(Array &a)  // constructor has no return type
    {
        capacity=a.capacity;
        lastIndex=a.lastIndex;
        p=new int[capacity];
        for(int i=0; i<=lastIndex; i++)
            p[i]=a.p[i];
    }

    // assignment operator , if user does : Array a1(8),a2(8), ....... fill data in a1 .... and a2=a1;  // it is no t same but it is like a2=a1.operator Array 
    /*
    it is different , in above case it was
    Array a2;
    Array a1=a2;   or    Array a1(a2);

    but now, it is like
    Array a1, a2;
    a1=a2;
    */
    Array& operator(Array &a)  // a1=a2 is like
    {
        if(this != &a)  // to deal if uses does a1=a1;    then,   if(this != &a)  {...} will not be run so simply same object will be return 
        {
            if(p!=NULL)  // if a1=a2  and a1 was storing some data before i.e. pointing some memory than we have to first free that memory
                delete []p;
            capacity=a.capacity;
            lastIndex=a.lastIndex;
            p=new int[capacity];
            for(int i=0; i<=lastIndex; i++)
                p[i]=a.p[i];
            return *this;
        }
    }

    Array()  
    {       }
    bool checkArray()
    {
        if(lastIndex==-1)
            return true;
        else 
            return false;
    }

    bool checkFull()
    {
        return lastIndex==(capacity-1);
    }

    void append(int data) // first check either array is full or not
    {
        if(checkFull())
            cout<<"\n OverFlow";
        else
        {
            lastIndex++;
            p[lastIndex]=data;
        }
    }

    void insert(int index, int data)
    {
        if(index<0 || index>lastIndex+1)   
            cout<<"\n Can't insert data at given index";
        else if(checkFull()) 
            cout<<"\n Array is Full"; //can't insert;
        {    
        for(int i=lastIndex; i>=index; i--) // also analyze when array is empty
        {
            p[i+1]=p[i];
        }
        p[index]=data;
        }
        lastIndex++;
    }
    void edit(int index, int data)
    {
        if(index<0 || index>lastIndex)   // also satisfies fo when array is empty
            cout<<"\n Can't edit data at given index";
        else
            p[index]=data;
    }
    void Delete(int index)
    {
        if(index<0 || index>lastIndex)   // also satisfies fo when array is empty
            cout<<"\n Can't delete data at given index";
        
        else
        {  
            for(int i=index; i<lastIndex; i++)
            {
                p[i]=p[i+1];         
            }
            lastIndex--;
        }

    }
    
    int getElement(int index)
    {
        if(index<0 || index>lastIndex)   // If  if() {..} runs then it should return something since function return type is int.   so to avoid this use exception handeling i.e.   if  if(){...} doesn't run than remaining statement will run which returns something. 
           throw 10;
        return p[index];
    }
    ~Array()
    {
        delete []p;
    }
    int findElement(int index)
    {
        for(int i=0; i<=lastIndex; i++)     // if array contains no element than loop doesn't run.
        {
            if(p[i]==p[index])
                return index;
        }
                return -1;  // if array contains no element than also we need to se
    }

};

int main()
{
    Array a1(5);
    a1.append(4);
    a1.append(5);
    try{
    cout<<a1.getElement(2);
    }
    catch(int e)
    {
        cout<<"error: ";
    }
    return 0;
}