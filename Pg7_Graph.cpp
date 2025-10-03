#include<iostream>
using namespace std;
class Graph
{
    int vt;
    int adj[10][10];
public:
    Graph(int n)
    {

        vt=n;
        for(int i=0;i<vt;i++)
            for(int j=0;j<vt;j++)
            adj[i][j]=0;
    }
    void addedge(int u,int v)
    {
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void BFS(int start)
    {
        cout<<"\t\t--Breadth First Search--\n";
        bool visited[10]={false};
        int q[10],front=0,rear=0;
        cout<<"\n\tBFS Traversal :  ";
        visited[start]=true;
        q[rear++]=start;
        while(front<rear)
        {
            int v=q[front++];
            cout<<v<<" ";
            for(int i=0;i<vt;i++)
            {
                if(adj[v][i]==1 && !visited[i])
                {
                    visited[i]=true;
                    q[rear++]=i;
                }
            }
        }
        cout<<endl;
    }
    void DFS(int start)
    {
        cout<<"\t\t--Depth First Search--\n";
        bool visited[10]={false};
        int st[10],top=-1;
        cout<<"\n\tDFS Traversal :  ";
        st[++top]=start;
        while(top>=0)
        {
            int v=st[top--];
            if(!visited[v])
            {
            cout<<v<<" ";
            visited[v]=true;
            for(int i=vt-1;i>=0;i--)
            {
                if(adj[v][i]==1 && !visited[i])
                {
                    st[++top]=i;
                }
            }
        }
    }
    cout<<endl;
    }
};
int main()
{
    cout<<"\t\tGRAPH IMPLEMENTATION\n\n";
    int n,edges,u,v,c,start;
    cout<<"Enter number of vertices:";
    cin>>n;
    Graph g(n);
    cout<<"Enter number of edges:";
    cin>>edges;
    cout<<"Enter edges(u,v):"<<endl;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        g.addedge(u,v);
    }
    cout<<"Enter starting vertax:";
    cin>>start;
    cout<<"\t\n-----Menu-----\n";
    cout<<"\n1.BFS TARVERSAL";
    cout<<"\n2.DFS TRAVERSAL";
    cout<<"\n3.Exit\n";
    do
    {
        cout<<"\nEnter the choice:";
        cin>>c;
        switch(c)
        {
        case 1:
            g.BFS(start);
            break;
        case 2:
            g.DFS(start);
            break;
        case 3:
            cout<<"\n\tExisting..\n";
            break;
        default:
            cout<<"\n\tInvalid choice.Enter the choice between 1-3 .";
        }
    }while(c!=3);
    return 0;
}
