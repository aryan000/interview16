#include<iostream>
using namespace std;

int num_possible_ways(int n)
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	return num_possible_ways(n-1) + num_possible_ways(n-2) + num_possible_ways(n-3) ;
}

int possible_ways_dp(int n)
{
	int arr[n+1];
	// base case
	if(n<0) 
		return 0;
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;

	
	for(int i =3;i<=n;i++)
		arr[i] = arr[i-1]+ arr[i-2]+ arr[i-3];

	return arr[n];
}
int main()
{
	int n;
	cin>> n;

	cout<< possible_ways_dp(n) << endl;
}