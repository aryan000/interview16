#include<bits/stdc++.h>
using namespace std;

bool equal2product( vector<int> arr , int pro)
{

	int start = 0 , end = arr.size()-1;

	while(start<end)
	{	
		int temp  =arr[start]*arr[end];
		if(temp==pro)
			return true;

		if(temp>pro)
			end--;
		else
			start++;
	}

	return false;
}

int main()
{
	int t;
	cin>> t;
	while(t--)
	{
		int n;
		cin>> n;
		int pro;
		cin>> pro;
		vector<int> arr;
		int temp;
		for(int i =0;i<n;i++)
		{
			cin>> temp;
			arr.push_back(temp);
		}

		sort(arr.begin(),arr.end());

		bool ans = equal2product(arr,pro);
		if(ans)
			cout<<"Yes" << endl;
		else cout<<"No" << endl;

	}
}