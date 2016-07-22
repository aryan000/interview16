/*
Input File:
6
4
1 2
2 3
1 3
4 5

*/

#include<iostream>
using namespace std;
#include<vector> 

#define vi vector<int> 
#define vb vector<bool>
#define pb(x) push_back(x)
	

void graph_input( vi graph[] , int nodes , int edges)
{
	int a , b;
	while(edges--)
	{
	cin>> a >> b;
	// undirected graph
	graph[a].pb(b);
	graph[b].pb(a);
	}
}

void dfs( int node , vb &visited , vi graph[])
{	
	visited[node] = true;

	for(int i =0;i<graph[node].size();i++)
	{
		if(visited[graph[node][i]] == false)
		{
			dfs(graph[node][i], visited , graph);
		}
	}

}

int main(int argc, char const *argv[])
{
	int node , edges;
	cout<<"Enter nodes and edges : ";
	cin>> node >> edges ;
	vi graph[node+1];
	graph_input(graph,node ,edges);

	
	vb visited(node,false);

	int connected_component = 0;

	for(int i =1;i<=node;i++)
	{	
		if(visited[i]==false)
			{dfs(i,visited , graph);
			connected_component ++;
		}


	}


	cout<<"Number of connected_component in a graph is : " << connected_component << endl;


		return 0;
}
