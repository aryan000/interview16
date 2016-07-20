#include<iostream>
using namespace std;
#include<climits>
#include<vector>

int fn(int n )
{	
	if(n==1)
		return 0;

	if( n==2 || n==3)
		return 1;

	int ans1 = fn(n-1);
	int ans2 = INT_MAX;
	int ans3 = INT_MAX;

	if(n%2==0)
		ans2 = fn(n/2);
	if(n%3==0)
		ans3 = fn(n/3);

	return 1 + min(ans1 , min(ans2,ans3));

}

int fn_dp(int n , vector<int> arr)
{
	if(n==1)
		return 0;

	if( n==2 || n==3)
		return 1;

	int ans1 = fn(n-1);
	int ans2 = INT_MAX;
	int ans3 = INT_MAX;

	if(n%2==0)
		ans2 = fn(n/2);
	if(n%3==0)
		ans3 = fn(n/3);

	 arr[n] = 1 + min(ans1 , min(ans2,ans3));
	 return arr[n];
}

int dp(int n)
{
	int arr[n+1];
	arr[0] = 0;
	arr[1] = 0;

	int x , y , z;

	for(int i =2;i<=n;i++)
	{
		x = y = z = INT_MAX;
		x = arr[i-1];
		if(i%2==0)
			y = arr[i/2];
		if(i%3==0)
			z = arr[i/3];

		arr[i] = 1 + min(x,min(y,z));


	}

	return arr[n] ;
}

int main()
{
	int n;
	cin>>n;
	// vector<int> arr(n+1,0);
	cout<< dp(n) << endl;
}