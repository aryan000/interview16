#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

#define loop(x,n) for(x=0;x<n;x++)


int ways_of_coin_change(vector<int> arr ,int last, int n)
{	
	// n cannot be formed
	 if(n<0)
	 	return 0;
	 // n has been formed
	 if(n==0)
	 	return 1;

	 // there is no element in arr
	 if(last<0 && n>=1)
	 	return 0;
	 return ways_of_coin_change(arr,last-1,n) + ways_of_coin_change(arr,last,n-arr[last]);
}


int recursive_ways(vector<int> arr , int last , int n , vector<int> iscalculated )
{
	if(n<0)
		return 0;

	if(n==0)
	{
		iscalculated[n] = 1;
		return iscalculated[n];
	}

	if(last<0 && n>0)
		return 0;

	iscalculated[n] = recursive_ways(arr,last-1,n,iscalculated) + recursive_ways(arr,last,n-arr[last],iscalculated);
	return iscalculated[n];
}

int main()
{
	int n;
	// cout<<"Enter the number of coins : ";
	cin>> n;
	int x;
	cin>> x;
	// cout<<"Enter the coins value : ";
	vector<int> arr ; int temp;

	int i;
	loop(i,n)
	{
		cin>> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	// cout<< "Enter the value to be excahnged : ";
	

	// cout<< ways_of_coin_change(arr,arr.size()-1,x);
	vector<int> iscalculated (x+1,0);

	cout<< recursive_ways(arr,arr.size()-1,x,iscalculated);


}