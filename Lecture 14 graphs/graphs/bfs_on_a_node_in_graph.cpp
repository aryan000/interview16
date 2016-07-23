#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define qi queue<int>
#define pb(x) push_back(x)


void bfs(int source , vi graph[] , int nodes)
{
	 vb visited(nodes,false);
	 visited[source] = true;

	 qi q;
	 q.push(source);
	 while(!q.empty())
	 {
	 	int front = q.front();
	 	q.pop();

	 	cout<< front << " ";
	 	 for(int i= 0;i<graph[front].size();i++)
	 	 {
	 	 	if(visited[graph[front][i]]==false)
	 	 	{
	 	 		q.push(graph[front][i]);
	 	 		visited[graph[front][i]] = true;
	 	 	}
	 	 }
	 }
}



void take_graph_input(vi graph[] , int edges)
{
	int a , b;
	while(edges--)
	{
		cin>> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}


	return;
}

int main()
{
	int nodes , edges;
	cout<<"Enter number of nodes and edges : " ;
	cin>> nodes >> edges;

	vi graph[nodes];
	take_graph_input(graph,edges);

	cout<<"Enter the node for bfs :  ";
	int source;
	cin>> source;

	bfs(source,graph,nodes);


	return 0;

}