#include<iostream>
using namespace std;
#include<vector>

#define vi vector<int>
#define vb vector<bool>
#define pb(x) push_back(x)



void graph_input(vi graph[] , int nodes , int edges)
{	
	int vertex1 , vertex2;
	while(edges--)
	{
		cin>> vertex1 >> vertex2;
		// since it is a undirected graph;
		graph[vertex1].pb(vertex2);
		graph[vertex2].pb(vertex1);
	}

	return ;
}

void dfs(int node , vb &visited , vi graph[])
{
	if(visited[node])
		return;

	visited[node] = true;

	for(int i =0;i<graph[node].size();i++)
	{
		if(visited[graph[node][i]]==false)
			dfs(graph[node][i],visited,graph);
	}
}

int main()
{
	cout<<"Enter nodes and edges  : ";
	int nodes , edges;
	cin>> nodes >> edges;

	vi graph[nodes+1];

	graph_input(graph, nodes, edges);

	vb visited(nodes+1,false);

	int connected_componenet = 0;

	// counting number of connected components
	for(int i =1;i<=nodes;i++)
	{
		if(visited[i]==false)
		{
			dfs(i,visited,graph);
			connected_componenet++;
		}
	}

	cout<< " NUmber of connected componenet is : " << connected_componenet << endl;
}