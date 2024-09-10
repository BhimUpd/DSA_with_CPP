#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
class SLL
{
    node *start;
    public:
    SLL()
    {
        start=NULL;
    }

    void insertatBeginning(int);
    void insertatLast(int);
    node* search(int); // search a node and returns the address of that node
    void insertAfter(node*,int);// insert after given node,   first user uses function node* search(int data) {...} which returns node address, so one argument must be node pointer 
    void deleteFirst();
    void deleteLast();
};

void SLL::insertatBeginning(int data)
{
    node *n=new node;
    n->data=data;
    n->next=start;
    start=n;
}

void SLL::insertatLast(int data)
{
    node *temp;
    node *n=new node;
    n->data=data;
    n->next=NULL;
    if(start==NULL)  // if list is empty
        start=n;
    else
    {
        temp=start;
        while(temp->next!=NULL) // means temp points another node 
            temp=temp->next;  // temp=start so, temp=start->next   start->next contains the address of first list at first
        temp->next=n;
    }
}

node* SLL::search(int data)
{
    node *temp;
    temp=start;
    while(temp!=NULL) // loop runs from first list to last list
    {
        if(temp->data == data)
            return temp;
    }
    return NULL; // if not found or list is empty
}

void SLL::insertAfter(node* p, int data) // in first argument user either enters address of node  or something like    obj.insertAfter(serach(old_data), new_data)
{
    if(p!=NULL)
    {
        node *n=new node;
        n->data=data;
        n->next=p->next;
        p->next=n;
    }
    else
        cout<<"Can't Insert";
}

void SLL::deleteFirst()
{
    if(start==NULL)
        cout<<"List is Empty";
    else
    {
        node *p=start;
        start=start->next;
        delete p;
    }
}

void SLL::deleteLast()
{
    if(start==NULL)
        cout<<"List is Empty";
    else
    {
        
    }
}

int main()
{

    return 0;
}