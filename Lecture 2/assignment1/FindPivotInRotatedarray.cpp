/*A sorted array has been rotated by some number k in clockwise direction. How can we
find k efficiently
*/

#include<iostream>
using namespace std;
#include<vector>


int rotated(vector<int> arr , int start , int end)
{
	// Base Case 
	if(start>end) return -1; // not possible for a rotated pivot point case.
	if(start==end) return start ;// single element at last

	/*  rotated array looks like 
				/p\
			   /   \
	          /     \
		     /       \
		    /         \
		 start		   end

	*/
	// we need to find p as pivot point

	int mid = (start+end)/ 2;

   cout<<" mid is : " << start << " " << end << " " << mid << endl;
	if(mid<end && arr[mid]>arr[mid+1]) // if mid is exactly the p point
		return mid;

	 

	if(start<mid && arr[mid]<arr[mid-1]) // if mid is below the exactly p point
		return mid-1;

	if(arr[start]<=arr[mid])
		return rotated(arr,mid+1,end);

	else
	return rotated(arr,start	,mid-1);




}


int main()
{
	int n;
	cout<<"Enter the number of elements : " ;
	cin>> n;

	vector<int> arr;

	int temp;
	for(int i =0;i<n;i++)
	{
	cin>> temp;
	arr.push_back(temp);

	}

	int ans = rotated(arr,0,arr.size()-1);
	if(ans==-1) cout<<"Array is not rotated";
	else 
	cout<<"The rotated point number is : " << ans << endl;
}