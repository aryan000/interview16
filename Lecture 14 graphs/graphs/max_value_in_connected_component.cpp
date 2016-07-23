/*This is the story in Zimbo, the kingdom officially made for monkeys. Our Code Monk visited Zimbo and declared open a challenge in the kingdom, thus spoke to all the monkeys :

You all have to make teams and go on a hunt for Bananas. The team that returns with the highest number of Bananas will be rewarded with as many gold coins as the number of Bananas with them. May the force be with you!
Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M rituals are performed. Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.

Input:
First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M. M lines follow. Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual. Last line of the testcase contains N space-separated integer constituting the array A.

Output:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 105
0 ≤ M ≤ 105
0 ≤ Ai ≤ 1012

SAMPLE INPUT 
1
4 3
1 2
2 3
3 1
1 2 3 5
SAMPLE OUTPUT 
6
Explanation
Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.


*/

#include<iostream>
using namespace std;
#include<vector>

#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define pb(x) push_back(x)



vi dfs(vi graph[] , int curr_node , vb &visited)
{
	vi ans ;
	if(visited[curr_node])
		return ans;
	visited[curr_node] = true;

	ans.pb(curr_node);

	for(int i = 0;i<graph[curr_node].size();i++)
	{	
		if(visited[graph[curr_node][i]]==false)
		{vi temp = dfs(graph,graph[curr_node][i] , visited);

		for(int k = 0;k<temp.size();k++)
			ans.pb(temp[k]);
		}
	}

	return ans;
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
 	vi arr; int temp;
 	arr.pb(0); // initialising useless first index

 	for(int i =1;i<=nodes;i++)
 	{
 		cin>> temp;
 		arr.pb(temp);
 	}

 	vvi connected_componenet ;

 	for(int i =1;i<=nodes;i++)
 	{	
 		vi component;
 		if(visited[i]==false)
 		{

 			component = dfs(graph,i,visited);
 			connected_componenet.pb(component);
 		}
 	}

 	long long int max_sum = 0;

 	for(int i =0;i<connected_componenet.size();i++)
 	{	long long int temp = 0;
 		for(int j =0;j<connected_componenet[i].size();j++)
 			// cout<< connected_componenet[i][j] << " ";
 			temp += arr[connected_componenet[i][j]];

 		if(temp>max_sum)
 			max_sum = temp;
 	}

 	cout<< max_sum << endl;
 } // end of t while loop

 return 0;
}