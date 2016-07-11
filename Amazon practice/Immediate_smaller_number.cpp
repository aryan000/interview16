#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>> t;
	while(t--)
	{
		int n;
		cin>> n;
		vector<int> arr;
		int temp;
		for(int i =0;i<n;i++)
		{
			cin>> temp;
			arr.push_back(temp);
		}
		for(int i =0;i<n-1;i++)
			{
				if(arr[i+1]<arr[i])
				cout<< arr[i+1] << " ";

				else cout<< "-1 ";

		}
		cout<< "-1" << endl;
	}
}