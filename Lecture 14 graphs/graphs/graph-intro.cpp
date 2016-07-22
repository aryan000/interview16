#include<queue>
#include<iostream>
#include<list>
using namespace std;

class graph{

    int v;
    int e;
     list<int> *adjlist;
 public:
    graph(int vertices)
    {
        v=vertices;
        adjlist=new list<int>[v];
        e=0;
    }
    void addedge(int u,int v,bool bidirectional=true)
    {
        if(bidirectional==true)
        {
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
            e=e+2;
        }
        else{
            adjlist[u].push_back(v);
            e=e+1;
        }
    }

    void bfsprint()
    {
        bool *visited=new bool [v];
        //forcdistance  take an array of int
        //int distance[v]={-1};

        for(int i=0;i<v;i++)
        {
            visited[i]=false;
        }
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            cout<<f<<" ";
            for(auto i=adjlist[f].begin();i!=adjlist[f].end();i++)
            {
                if(visited[*i]==false)
                {
                    q.push(*i);
                    visited[*i]=true;

                }
            }

        }

    }
   /* void shortestpath()
    {
        int *dist=new int [v];
        for(int i=0;i<v;i++)
            dist[i]=-1;
            queue<int>q;
        q.push(0);
        dist[0]=0;

        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto i=adjlist[f].begin();i!=adjlist[f].end();i++)
            {
                if(dist[*i]==-1)
                {
                    q.push(*i);
                dist[*i]=dist[f]+1;
                }
             }

        }
        for(int i=0;i<v;i++)
        {
            cout<<dist[i]<<" ";
        }

    }*/
        void shortestpath(int src,int dest)
    {
        int *dist=new int [v];
        for(int i=0;i<v;i++)
            dist[i]=-1;
            queue<int>q;
        q.push(src);
        dist[src]=0;
        int *p=new int [v];
        for(int i=0;i<v;i++)
            p[i]=-1;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto i=adjlist[f].begin();i!=adjlist[f].end();i++)
            {
                if(dist[*i]==-1)
                {
                    q.push(*i);
                dist[*i]=dist[f]+1;
                p[*i]=f;
                //if(*i==dest)
                    //return dist[dest];
                }
            }

        }
        int i=dest;
        while(i!=-1)
        {
            cout<<i<<" <--";
            i=p[i];
        }
              /* cout<<dest<<" ";
        while(i!=src&&dist[dest]!=-1)
        {
            cout<<p[i]<<" ";
            i=p[i];

       }
       if(dest==-1)
        cout<<"Path does not exist"<<endl;
*/
    }
    void dfshelper(int index,bool *visited)
    {
        cout<<index<<" ";
        visited[index]=true;
        for(auto i=adjlist[index].begin();i!=adjlist[index].end();i++)
        {
            if(visited[*i]==false)
                dfshelper(*i,visited);
        }

    }
    void dfsprint()
    {
        bool *visited=new bool [v];
        for(int i=0;i<v;i++)
            visited[i]=false;
        dfshelper(0,visited);


    }
};
int main()
{
    int v,e,x,y;
    cout<<"Enter the number of vertices and edges int the graph: ";
    cin>>v>>e;
    graph g(v);
    //graph *g=new graph(v);
    for(int i=0;i<e;i++)
    {
        cout<<"Enter edge "<<i+1<<" ";
        cin>>x>>y;
        g.addedge(x,y);
    }
    g.bfsprint();
    cout<<endl;
   /* int s,d;
    cin>>s>>d;
    g.shortestpath(s,d);*/
    g.dfsprint();
    cout<<endl;
    return 0;
}
