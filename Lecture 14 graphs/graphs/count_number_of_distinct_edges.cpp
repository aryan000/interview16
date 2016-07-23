/*
The Monk wants to buy some cities. To buy two cities, he needs to buy the road connecting those two cities. Now, you are given a list of roads, bought by the Monk. You need to tell how many cities did the Monk buy.

Input:
First line contains an integer T, denoting the number of test cases. The first line of each test case contains an integer E, denoting the number of roads. The next E lines contain two space separated integers X and Y, denoting that there is an road between city X and city Y.

Output:
For each test case, you need to print the number of cities the Monk bought.

Constraint:
1 <= T <= 100
1 <= E <= 1000
1 <= X, Y <= 10000

SAMPLE INPUT 
1
3
1 2
2 3
1 3
SAMPLE OUTPUT 
3
*/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int > >
#define vb vector<bool>
#define pb(x) push_back(x)


int main()
{
	int t;
	cin>> t;
	while(t--)
	{
		int nodes , edges;
		cin>>  edges;
		nodes = edges*2;
		vi graph[nodes+1];
		vi visited(nodes+1,false);

		int x , y;
		for(int i =0;i<edges;i++)
		{
			cin>> x >> y;
			graph[x].pb(y);
			graph[y].pb(x);
		}

		// graph has been inputted;
		int count = 1;
		visited[1] = true;
		for(int i =1;i<=nodes;i++)
		{	
			if(visited[i]==false)
			for(int j = 0;j<graph[i].size();j++)
			{
				if(graph[i][j] ==false)
					continue;
				count++;
				 visited[graph[i][j]] = true;
			}
		}

		cout<< count << endl;
	}
}