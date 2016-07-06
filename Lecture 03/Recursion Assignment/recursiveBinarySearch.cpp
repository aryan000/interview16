/* implementing binary search recursively */


#include<iostream>
using namespace std;
#include<vector>

int binary_search(vector<int> v , int low , int high , int item)
{

	if(low>high) 
		return -1;

	if(low==high && v[low]==item)
		return low;

	int mid = (low+high)/2;

	if(v[mid]==item)
		return mid ;

	if(v[mid]>item)
		return binary_search(v,low,mid-1,item);

	else return binary_search(v,mid+1,high,item);

}

int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>>n;

	int temp;
	vector<int> arr;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);

	}

	int item;
	cout<<"Enter the item to be found : ";
	cin>> item;
	int ans = binary_search(arr,0,n,item);

	if(ans==-1)
		cout<<"Index not found";

	else cout<<"Element found at index " << ans+1 << endl;
}