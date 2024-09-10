#include<iostream>

using namespace std;

class MatrixGraph{
    private:
        int v_count, e_count,**adj;
    public:
        void createGraph(int,int);
        void printMatrix();
        void printAdjacentNode(int);
        bool isIsolated(int);
        ~MatrixGraph();

};

void MatrixGraph::createGraph(int no_of_vertex, int no_of_edges)
{
    int u,v;
    v_count=no_of_vertex;
    e_count=no_of_edges;
    adj=new int*[v_count];
    for(int i=0; i<v_count; i++)   
        adj[i]=new int[v_count];
    for(int i=0; i<v_count; i++)
    {
        for(int j=0; j<v_count; j++)
            adj[i][j]=0;
    }
    cout<<"\n Enter node numbers connecting edges:\n";
    for(int i=0; i<e_count; i++)
    {
        cin>>u>>v;
        adj[u][v]=adj[v][u]=1;
    }
}

void MatrixGraph::printMatrix()
{
    for(int i=0; i<v_count; i++)
    {
        for(int j=0; j<v_count; j++)
            cout<<adj[i][j];
        cout<<endl;
    }
}

void MatrixGraph::printAdjacentNode(int n)
{
    if(n>=0 && n<v_count)
    {
        for(int i=0; i<v_count; i++)
        {
            if(adj[n][i])
                cout<<"\nV"<<i;
        }
    }
}

bool MatrixGraph::isIsolated(int n)
{
    if(n>=0 && n<v_count)
    {
        for(int i=0; i<v_count; i++)
        {
            if(adj[n][i])
                return 0;
        }
        return 1;
    }
}

MatrixGraph::~MatrixGraph()
{
    for(int i=0; i<v_count;  i++)
    {
        delete []adj[i];
    }
    delete []adj;
}

int main()
{

    return 0;
}