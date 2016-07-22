#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#define qi queue<int> 
#define vi vector<int>
#define vb vector<bool>
#define pb(x) push_back(x)


void print(vi graph[] , int nodes)
{
	for(int i =1;i<=nodes;i++)
	{	
		cout<< "for node i is : " << i  << " -----> " ;
		for(int j =0;j<graph[i].size();j++)
		{
			if(j==graph[i].size()-1)
				cout<< graph[i][j] << endl;
			else cout<< graph[i][j] << " ----->";
		}
	cout<< endl;
	}

	return;
}

void take_graph_input(vi graph[] , int nodes , int edges)
{
	int node1 , node2;
	cout<<"Enter edges in the following lines : ";
	while(edges--)
	{
		cin>> node1 >> node2 ;
		graph[node1].pb(node2);
		graph[node2].pb(node1);
	}

	// print(graph,nodes);
	// int ch;
	// cin>> ch;
	return;
}


void bfs( int node ,  vi graph[] , int nodes, vb visited, vi &level)
{
	qi q;
	q.push(node);
	level[node] = 0;

	visited[node] = true;

	while(!q.empty())
	{
		int temp_node = q.front();
		q.pop();

		// cout<< "dealing with node : " << temp_node << endl;
		for(int i =0;i< graph[temp_node].size();i++)
		{ 
			// cout<<" node has value : "<< visited[graph[temp_node][i]] << endl;
			if(visited[graph[temp_node][i]]==false)
			{	
				// cout<<"dealing with : " << graph[temp_node][i] << endl;
				level[graph[temp_node][i]] = level[temp_node] + 1;
				q.push(graph[temp_node][i]);
				visited[graph[temp_node][i]] = true;

			}
		} 
		// all nodes of current node inserted
	}

	 

	return;
}

int main()
{
	cout<<"Enter number of nodes and edges : ";
	int nodes , edges;
	cin>> nodes >> edges;

	vi graph[nodes+1];
	take_graph_input(graph,nodes,edges);

	vb visited(nodes+1,false);

	vi level(nodes+1,0);

	bfs(1,graph,nodes,visited,level);

	 for(int i =1;i<=nodes;i++)
	 cout<< i << " ------> " << level[i] << endl;


}