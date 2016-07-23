#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define pb(x) push_back(x)


void take_graph_input(vi graph[]   , int edges )
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
	cin>> nodes >> edges;

	vi graph[nodes+1];

	take_graph_input(graph,edges);

	for(int i =0;i<nodes;i++)
	{
		cout<<"Adjacency list of vertex : " << i << endl ;
		cout<< " head --> ";
		for(int j = 0;j<graph[i].size();j++)
		{
			if(j==graph[i].size()-1)
				cout<< graph[i][j] ;
			else
				cout<< graph[i][j] << " --->";
		}
		cout<< endl;
	}


return 0;
}