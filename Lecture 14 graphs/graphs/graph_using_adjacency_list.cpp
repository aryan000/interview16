/*A1 􀄺 2
A2 􀄺 4
A3 􀄺 1 􀄺 4
A4 􀄺 2
Consider the above directed graph and let’s code it.
Input File:
4
5
1 2
2 4
3 1
3 4
4 2

*/

#include<iostream>
using namespace std;
#include<vector>
#define vi vector<int>
#define pb(x) push_back(x)

int main(int argc, char const *argv[])
{
	
	int vertices , edges;
	cout<<"Enter vertices and edges : ";
	cin>> vertices>> edges;

	vi graph[vertices+1];
	int x, y;

	for(int i =0;i<edges;i++)
	{
		cin>> x >> y;
		graph[x].pb(y);
	}

	for(int i =1;i<=vertices; i++)
	{
		cout<<" Adjacency list of node " << i  << " : " ; 
		for(int j =0;j<graph[i].size();j++)
		{
			if(j== graph[i].size()-1) // last element
				cout<< graph[i][j] << endl;
			else
				cout<< graph[i][j] << " ---> ";
		}
		cout<< endl;
	}
	return 0;
}