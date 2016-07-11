#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// O(n) solution 
ll  floorSqrt1(ll x)
{	
	if(x==0 || x==1)
		return x;

	ll i;
	for( i =0;i<x;i++)
		if(i*i>x)
			break;

	return i-1;
	
}

// o(logn) approach
 
ll floorSqrt(ll x)
{
	if(x==0 || x==1)
		return x;

	ll start = 0;
	ll end = x;
	ll mid = (start+end)/2;
	ll ans ;
	while(start<=end)
	{	
		// condition of perfect square
		if(mid*mid==x)
			return mid;

		if(mid*mid<x)
		{
			// we need just lesser that so this could be the answer
			ans = mid;
			start = mid+1;
		}
		else
			end = mid-1;

		mid = (start+end)/2;
	}


	return ans;
}

int main()
{
	int t;
	cin>> t;
	while(t--)
	{
	ll x;
	cin>> x;
	 ll ans = floorSqrt(x);
	 cout<< ans << endl;

	}
}