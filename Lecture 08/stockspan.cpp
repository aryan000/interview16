#include<iostream>
using namespace std;
#include<stack>

int main()
{
	int n;
	cin>> n;
	int arr[n];
	for(int i =0;i<n;i++)
	{
		cin>> arr[i] ; 

	}

	stack<int> s;
	s.push(0);

	int ans[n] ;
	ans[0] = 1;
	for(int i =1;i<n;i++)
	{
		while(!s.empty() && arr[s.top()]<=arr[i])
			s.pop();

		if(s.empty())
			ans[i] = i+1;
		else

		ans[i] = i - s.top();

		s.push(i);
	}

	for(int i =0;i<n;i++)
		cout<< ans[i] << " " ;
	cout<< endl;
}