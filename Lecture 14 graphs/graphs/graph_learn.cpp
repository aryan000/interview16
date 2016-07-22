#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<list>

class graph
{
	int vertex ;
	int edge ;
	list<int> * adjlist;

	public : 
	 graph(int vertex)
	 {	
	 	this->vertex = vertex;
	 	adjlist = new list<int>[vertex];
	 	edge = 0;
	 }

	 void add_edge(int u  , int v , bool bidirectional=true)
	 {
	 	if(bidirectional)
	 	{
	 		adjlist[u].push_back(v);
	 		adjlist[v].push_back(u);
	 		edge +=2;
	 	}

	 	else
	 	{
	 		adjlist[u].push_back(v);
	 		edge += 1;
	 	}
	 }
};

int main()
{

}