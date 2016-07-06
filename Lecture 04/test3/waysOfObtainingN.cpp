/*
Given a number N, write a program  to list the ways of obtaining N by using numbers from 1 to N-­‐1 any number of times. 
Example :
Input-­‐ N= 4
Output –
1,1,1,1
1,1,2
1,3
2,2
3,1
2,1,1
1,2,1

*/

#include<iostream>
using namespace std;
#include<vector>

void print(std::vector<int> v)
{
	for(int i =0;i<v.size();i++)
		cout<< v[i] << " ";
	cout<< endl;
}


// This question is similar to lexicographical

void printnumberofways(int n ,int sum, vector<int> &output)
{	
	// Base Case 1 
	if(sum>n) return;
	//Base Case 2
	if(sum==n) 
	{
		print(output);
		return;
	}

	for(int i =1;i<=n;i++)
	{
		output.push_back(i);
		printnumberofways(n,sum+i,output);
		output.pop_back();
	}

}


int main()
{	

	int n;
	cin>> n;
	vector<int> arr;
	printnumberofways(n,0,arr);

	return 0;
}