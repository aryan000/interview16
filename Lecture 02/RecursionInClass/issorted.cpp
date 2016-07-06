/* Check if the array is sorted or not using recursion */

#include<iostream>
using namespace std;
#include<vector>

/* using stl vectors checknig whether vector is sorted or not */
bool issorted( vector<int> v , int i)
{
  if(v.size()-i ==1) return true;

  if(v[i]>v[i+1]) return false;

  return issorted(v,i+1);
	
}

/* for array as pointers passed to the function */
bool issorted( int *arr, int n)
{
	if(n==0 || n==1) 
		return true;

	if(arr[0]>arr[1]) return false;

	return issorted(arr+1,n-1);
}

int main()
{
	int n;
	cout<<"Enter the size of the array : ";
	cin>> n;

	vector<int> arr;
	int temp;

	for(int i =0;i<n;i++)
	{
	cin>> temp;
	arr.push_back(temp);
	}

	bool check = issorted(arr,0);

	if(check) cout<<"The array is sorted ";
	else cout<<"The array is not sorted ";

}