#include<iostream>
using namespace std;
#include<vector>

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int> >
#define pb(x) push_back(x)


vi dfs(vi graph[]  , int curr_node , vb &visited)
{
	vi ans;
	
	if(visited[curr_node])
		return ans;
	visited[curr_node] = true;

	ans.pb(curr_node);

	for(int i =0;i<graph[curr_node].size();i++)
	{
		if(visited[graph[curr_node][i]]==false)
		{	
			// ans.pb(graph[curr_node][i]);
			vi temp = dfs(graph,graph[curr_node][i],visited);

			for(int k =0;k<temp.size() ; k++)
			 ans.pb(temp[k]);			 
		} 

	}

	return ans;
}




void take_graph_input( vi graph[] , int nodes , int edges)
{
	int node1 , node2;
	while(edges--)
	{	
		cin>> node1 >> node2;
		// building a undirected graph
		graph[node1].pb(node2);
		graph[node2].pb(node1);
	}


	return;
}



int main()
{
	int nodes, edges;
	cout<<"Enter the nodes and edges : ";
	cin>> nodes >> edges ;

	vi graph[nodes+1];
	 take_graph_input(graph, nodes , edges);

	 vb visited(nodes+1,false);

	 vvi connected_component;
	 int count_connected = 0;
	 for(int i=1;i<=nodes;i++)
	 {	
	 	if(visited[i]==false)
	 	{
	 		vi temp = dfs(graph,i,visited);
	 		connected_component.pb(temp);
	 		count_connected++;
	 	}

	 }

	 cout<<"Total number of connected_component are : " << count_connected<<endl;
	 cout<<"Connected component are : " << endl;

	 for(int i =0;i<connected_component.size();i++)
	 {
	 	for(int j =0;j<connected_component[i].size();j++)
	 		cout<< connected_component[i][j] << " ";

	 	cout<< endl;
	 }



	return 0;
}
