#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define vb vector<bool>
#define pb(x) push_back(x)


void take_graph_input(vi graph[] , int edges)
{
	int a , b;
	while(edges--)
	{
		cin>> a  >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	return;
}


void dfs(vi graph[] , int source , vb &visited)
{	

	if(visited[source])
		return;
	cout<< source << " ";
	visited[source] = true;

	for(int i =0;i<graph[source].size();i++)
	{
		if(visited[graph[source][i]]==false)
			dfs(graph,graph[source][i],visited);
	}


	return;
}



int main(int argc, char const *argv[])
{
	
	cout<<"Enter number of nodes and edges : ";
	int nodes, edges;
	cin>> nodes >> edges;

	vi graph[nodes];

	take_graph_input(graph,edges);


	cout<<"Enter the source node on which you want to find out dfs : ";
	int source;
	cin>> source;

	vb visited(nodes,false);
	dfs(graph , source,visited);
	return 0;
}