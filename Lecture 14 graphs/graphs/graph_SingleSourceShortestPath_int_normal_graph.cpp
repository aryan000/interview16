#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vb vector<bool>
#define pb(x) push_back(x)
#define qi queue<int>


int main()
{
	int nodes, edges;
	cin>> nodes >> edges;

	vi graph[nodes+1];
	int x , y;
	for(int i =0;i<edges;i++)
	{
		cin>> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	// graph loaded
	vi distance(nodes+1,INT_MAX);
	vb visited(nodes+1,false);
	qi q;
	distance[1] = 0;
	q.push(1);

	while(!q.empty())
	{
		int front = q.front();
		q.pop();


		for(int i =0;i<graph[front].size();i++)
		{	int node = graph[front][i];
			if(visited[node]==false)
			{
				q.push(node);
				if(distance[node] > distance[front] + 1)
					distance[node] = distance[front] + 1;

				visited[node] = true;
			}

			if(distance[node] > distance[front] + 1)
					distance[node] = distance[front] + 1;
		}
	} // end of calculating distance


	for(int i =1;i<=nodes;i++)
		cout<< i << " ----->" << distance[i] << endl;

}