#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>

#define qi queue<int>
#define pi pair<int,int>
#define pb(x) push_back(x)
 

#define vpi vector<pair<int,int> >

class compare{
	public : 
		bool operator()(pi a , pi b)
		{
			return a.second>b.second?true:false;
		}
};


vi shortest_distance(vpi graph[] ,int nodes, int source)
{
	cout<<"shortest_distance " << endl;
	priority_queue<pi,vpi,compare> pq;
	vi distance(nodes+1,INT_MAX);

	vb visited(nodes+1,false);
	 
	 distance[source] = 0;
	 pq.push(make_pair(source,distance[source]));
	 visited[source] = true;
    cout<<"pq.top is : " << pq.top().first;
	 while(!pq.empty())
	 {
	 	pi temp = pq.top();
	 	pq.pop();

	 	int node = temp.first;
	 	cout<<"node is : " << node << endl;
	 	int weight = temp.second;

	 	for(int  i =0;i<graph[node].size();i++)
	 	{
	 		pi adj_node_pair = graph[node][i];
	 		int adj_node = adj_node_pair.first;
	 		int adj_weight = adj_node_pair.second;

	 		 distance[adj_node] = min(distance[adj_node],(weight+adj_weight));
	 		 
	 		 if(visited[adj_node]==false)
	 		  { pq.push(make_pair(adj_node,distance[adj_node]));
	 		  	visited[adj_node]= true;
	 		  }
	 	}
	 }
	 	
	 	return distance;

}


void print(vpi graph[] , int nodes)
{	
	cout<<"Printing"; 
	for(int i =1;i<=nodes; i++)
	{
		cout<< i << " : " ;
		for(int j =0;j<graph[i].size();j++)
		{
			cout<< graph[i][j].first << "(" << graph[i][j].second << " ) " << endl;
		}
		cout << endl;
	}
}

int main()
{
	int nodes , edges;
	cin>> nodes >> edges;

	vpi graph[nodes+1] ;
	int x , y  , z;
	for(int i =0;i<edges;i++)
	{
		cin>> x >> y>>z;

		graph[x].pb(make_pair(y,z));

		graph[y].pb(make_pair(x,z));


	}

	// print(graph,nodes);
	cout<< "Enter the source : ";
	int source;
	cin>> source;

	vi distance = shortest_distance(graph,nodes,source);


	for(int i =1;i<distance.size();i++)
	{

		cout<< i << " -->" <<  distance[i]  << endl;
		// kuch karenge yahan abhi baad me

	}
}