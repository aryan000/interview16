#include<iostream>
using namespace std;
#include<vector> 

// brute force solution
bool is_equal_sum_partition(vector<int> arr, int i , int sum)
{	
	if(i<0)
		return false;

	if(arr[i]==sum)
		return true;

	return is_equal_sum_partition(arr,i-1,sum) || is_equal_sum_partition(arr,i-1,sum-arr[i]);

}

int main()
{
	int n;
	cin>> n;
	vector<int> arr;
	int temp,sum=0;
	for(int i =0;i<n;i++)
	{
	cin>> temp;
	arr.push_back(temp);
	sum+= temp;
	}

	if(sum&1) cout<< "0" << endl;
	else
	{
	   bool ans = is_equal_sum_partition(arr,arr.size()-1,sum/2);

	   cout<< ans << endl; 



	}
}