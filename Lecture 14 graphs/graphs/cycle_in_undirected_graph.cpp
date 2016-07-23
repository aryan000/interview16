#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define pb(x) push_back(x)


bool iscyclic(vi graph[] , int source , vb &visited , vb &rec_stack)
{
	if(visited[source]==false)
	{
		visited[source] = true;
		rec_stack[source] = true;

		for(int i =0;i<graph[source].size();i++)
		{
			if(visited[graph[source][i]]==false)
					{
						if(iscyclic(graph,graph[source][i],visited,rec_stack))
						return true;
					}
					
			else if(rec_stack[source])
				return true;
		}
	}

	rec_stack[source] = false;
	return false;
}

bool iscyclic(vi graph[] ,int nodes)
{
	vb visited(nodes,false);
	vb rec_stack(nodes,false);

	for(int i =0;i<nodes;i++)
	{
		if(iscyclic(graph,i,visited,rec_stack))
			return true;

	}

return false;
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
 	cout<<"Enter the nodes and edges : ";
 	cin>> nodes >> edges;

 	vi graph[nodes];

 	take_graph_input(graph,edges);

 	bool ans = iscyclic(graph,nodes);

 	if(ans) 
 		cout<<"Yes there is a cycle ";
 	else cout<<"No there is no cycle ";

}
