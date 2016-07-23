#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define pb(x) push_back(x)
#define vll vector<long long>
typedef long long ll;


ll ans;

void dfs(vi graph[] , int curr_node , vb &visited , vll cost)
{
	 
	visited[curr_node] = true;

	// ans.pb(curr_node);
	ans += cost[curr_node];

	for(int i = 0;i<graph[curr_node].size();i++)
	{	
		if(visited[graph[curr_node][i]]==false)
		{  dfs(graph,graph[curr_node][i] , visited,cost);

		}
	}

}

void take_graph_input(vi graph[] , int nodes , int edges)
{
	int node1 , node2;
	
	while(edges--)
	{
		cin>> node1 >> node2;
		graph[node1].pb(node2);
		graph[node2].pb(node1);
	}


return;
}

int main()
{

 int t;
 cin>> t;
 while(t--)
 {
 	int nodes , edges;
 	cin>> nodes >> edges;

 	vi graph[nodes+1];
 	take_graph_input(graph,nodes,edges);

 	vb visited(nodes+1,false);
 	vll arr; ll temp;
 	arr.pb(0); // initialising useless first index

 	for(int i =1;i<=nodes;i++)
 	{
 		cin>> temp;
 		arr.pb(temp);
 	}

 	 
 	ll max_sum = 0;
 	for(int i =1;i<=nodes;i++)
 	{	
 		 
 		 ans = 0;
 		if(visited[i]==false)
 		{

 			 dfs(graph,i,visited , arr);
 			if(ans>max_sum)
 				max_sum = ans;
 		}
 	}

 	


 	cout<< max_sum << endl;
 } // end of t while loop

 return 0;
}