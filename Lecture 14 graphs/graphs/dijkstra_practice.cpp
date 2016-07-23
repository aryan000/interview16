#include<bits/stdc++.h>
using namespace std;

/* THis algo works for bellmon ford and dijkshtra also */



#define vi vector<int>
#define vb vector<bool>
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)


class compare
{ 
	public : 
			bool operator()(const pi a, const pi b)
		{
			return a.second>b.second;
		}
};


vi shortest_distance(vpi graph[] , int nodes, int source)
{
	//we need priority queue , distance vector and visited for undirected graph ( to avoid infinite loop)

	vi distance(nodes+1,INT_MAX);
	vb visited(nodes+1,false);

	// this should have been 
	// priority_queue<pair<int,int>,vector<pair<int,int> > , compare> pq;

	priority_queue<pi, vpi,compare> pq;

	// dealing with source
	visited[source] = true;
	distance[source] = 0;

	pq.push(mp(source,distance[source]));

	while(!pq.empty())
	{
		pi temp = pq.top();
		pq.pop();

		int node = temp.first;
		int weight = temp.second;


		for(int i =0;i<graph[node].size();i++)
		{
			pi temp_adj = graph[node][i];

			int adj_node = temp_adj.first;
			int adj_weight = temp_adj.second;

			distance[adj_node] = min(distance[adj_node],(weight +adj_weight));

			if(visited[adj_node]==false)
			{
				pq.push(mp(adj_node,distance[adj_node]));
				visited[adj_node] = true;
			}
		}
	}


	return distance;
}




void take_graph_input(vpi graph[] , int nodes , int edges )
{

	int x , y , weight ;
	while(edges--)
	{
		cin>> x >> y >> weight ;
		graph[x].pb(mp(y,weight));
		graph[y].pb(mp(x,weight));
	}


	// graph is inputteed voila !!!!!!!!
}

int main()
{
	int nodes , edges;
	cin>> nodes >> edges;

	vpi graph[nodes+1];

	take_graph_input(graph,nodes,edges);

	int source ;
	cout<<"Enter the source : ";
	cin>> source;

	vi short_dist = shortest_distance(graph,nodes,source);

	cout<<"Shortest distance using dijkshtra from source " << source << " are : " << endl;
	for(int i =1;i<short_dist.size(); i++)
	{
		cout<< i << " --->" << short_dist[i] << endl;
	}
}