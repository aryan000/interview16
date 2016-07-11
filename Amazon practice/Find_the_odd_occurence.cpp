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
		int temp;
		int ans = 0;
		for(int i =0;i<n;i++)
		{
			cin>> temp;
			ans = ans^temp;
		}
		cout<< ans << endl;
	}
}