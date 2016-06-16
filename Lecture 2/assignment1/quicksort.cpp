/* Merge Sort */


#include<iostream>
using namespace std;
#include<vector>
#include<cstdio>


void quicksort(int arr[] , int l , int n)
{
	if(l>=n) return;
	int pivot = l;
	int i =l,j = n;
	int temp;

	while(i<j)
	{
		while(arr[i]<=arr[pivot]&& i<n)
			i++;
		while(arr[j]>arr[pivot])
			j--;
		if(i<j)
		{
			 temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;
	quicksort(arr,l,j-1);
	quicksort(arr,j+1,n);


}


int main()
{
	
	int n ;
	cout<<"Enter the size of the array : " ;
	cin>> n;
	int  arr[n]; int temp;

	for(int i =0;i<n;i++)
	{
	cin>> arr[i];
	}

	quicksort(arr,0,n-1);

	cout<<"The sorted array is : ";
	for(int i =0;i<n;i++)
	 cout<<arr[i] << " ";

}