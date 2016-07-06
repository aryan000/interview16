/* Bubble Sort */


#include<iostream>
using namespace std;
#include<vector>

void swap(int *a , int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Minimum element is always placed at first 

void selection_sort(vector<int> &arr)
{
	int n = arr.size(); 
	int temp ;
	for(int i =0;i<n-1;i++)
	{  
		temp = i;
		for(int j =i+1;j<n;j++)
		{
			if(arr[temp]>arr[j])
				temp = j;
		}

		if(temp!=i)
			swap(&arr[i],&arr[temp]);


	}
}

int main()
{
	
	int n ;
	cout<<"Enter the size of the array : " ;
	cin>> n;
	vector<int> arr; int temp;

	for(int i =0;i<n;i++)
	{
	cin>> temp;
	arr.push_back(temp);
	}

	selection_sort(arr);

	cout<<"The sorted array is : ";
	for(int i =0;i<n;i++)
	 cout<<arr[i] << " ";

}