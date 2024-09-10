//Graph list
#include<iostream>
using namespace std;
class AdjList;
struct node{
    int data,vertex;
    node *next;
};
class Graph{
        int v_count;
        AdjList *arr;
    public:
        Graph();
        void createGraph(int);
        void addEdge(int);
        void addEdge(int,int,int);
        int getVcount();
        void printGraph();
        ~Graph();
};
class AdjList{
        int vertex;
        node *start;
    public:
        AdjList();
        AdjList(int);
        void setVertex(int);
        void addNode(int,int);
        void printList();
        void removeFirstNode();
        ~AdjList();
};
AdjList::AdjList()
{
    start=NULL;
}
AdjList::AdjList(int v)
{
    vertex=v;
}
AdjList::~AdjList()
{
    while(start)
        removeFirstNode();
}
void AdjList::setVertex(int V)
{
    int vertex=V;
}
void AdjList::printList()
{
    node *t=start;
    while(t)
    {
        cout<<"\n("<<t->vertex<<","<<t->data<<")";
        t=t->next;
    }
}
void AdjList::addNode(int v, int data)
{
    node* n=new node;
    n->vertex=v;
    n->data=data;
    n->next=start;
    start=n;
}
void AdjList::removeFirstNode()
{
    if(start)
    {
        node *t=start;
        start=t->next;
        delete t;
    }
}

Graph::Graph()
{
    v_count=0;
    arr=NULL;
}
Graph::~Graph()
{
    delete []arr;
}
void Graph::createGraph(int totalVertexNumber)
{
    int m,n,data;
    v_count=totalVertexNumber;
    arr=new AdjList[v_count];
    for(int i=0; i<v_count; i++)
    {
        arr[i].setVertex(i);
        cout<<"Enter how many adjacent node of vertex V"<<i;
        cin>>m;
        cout<<"\nEnter vertex number of adjacent node of V"<<i;
        for(int j=0; j<m; j++)
        {
            cin>>n;
            cout<<"\nEnter data:";
            cin>>data;
            arr[i].addNode(n,data);

        }
    }
}
void Graph::addEdge(int vertex1, int vertex2,int data)
{
    arr[vertex1].addNode(vertex2,data);
}
int Graph::getVcount()
{
    return v_count;
}
void Graph::printGraph()
{
    for(int i=0; i<v_count; i++)
    {
        cout<<endl;
        arr[i].printList();
    }
}

int main()
{
    return 0;
}