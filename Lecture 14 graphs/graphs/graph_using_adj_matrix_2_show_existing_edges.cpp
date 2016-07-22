#include<iostream>
using namespace std;
#include<vector>

#define vi vector<int> 
#define vvi vector<vector<int> > 

#define pb(arr,x) arr.push_back(x)  

int main()
{
	int vertices;
	cout<<"Enter the number of vertices : ";
	cin>> vertices;

	vvi graph;
	for(int i =0;i<vertices;i++)
	{
		vi temp(vertices,false);

		pb(graph,temp);
		
	}

	int edges;
	cout<<"Enter number of edges : ";
	cin>> edges;

	for(int i =0;i<edges;i++)
	{
		cout<<" Enter vertices a and b of an edge : ";
		int a , b;
		cin>> a >> b;
		graph[a][b] = 1;
	}

	cout<<"Find out if there is an edge or not : ";
	int a , b;
	cin>> a >> b;
	if(graph[a][b])
		cout<<"There is an edge ";
	else cout<< " THere is no edge : ";





}

/*
INput file 
4
5
1 2
2 4
3 1
3 4
4 2

*/