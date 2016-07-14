#include<iostream>
using namespace std;
#include<vector>

int max_sum_subarray(vector<int> arr   )
{

 int max_sum = 0;
 int max_sum_so_far = 0;

 for(int i =0;i<arr.size();i++)
 {
 	if(max_sum+arr[i]>0)
 		max_sum += arr[i];
 	else
 		max_sum = 0;

 	if(max_sum_so_far<max_sum)
 	{
 		max_sum_so_far = max_sum;
 	}
 }

 return max_sum_so_far;
}


// for handling -ve test cases
int max_sum_subarray2(vector<int> arr)
{
	int max_sum = arr[0];
	int max_so_far = arr[0];

	for(int i =1;i<arr.size();i++)
	{
		max_sum = max(arr[i],max_sum+arr[i]);
		max_so_far = max(max_so_far,max_sum);

	}

	return max_so_far;
}

int main()
{
	int n;
	cin>> n;

	vector<int> arr;
	int temp;
	for(int i =0;i<n;i++)
	{	cin>> temp;
	arr.push_back(temp);
	}

	cout<< "Maximum sum of subarray is : " << max_sum_subarray2(arr );


}