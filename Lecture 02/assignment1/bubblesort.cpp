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

void bubble_sort(vector<int> &arr)
{
	int n = arr.size();

	for(int i =0;i<n;i++)
		for(int j =0;j<n-1;j++)
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);

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

	bubble_sort(arr);

	cout<<"The sorted array is : ";
	for(int i =0;i<n;i++)
	 cout<<arr[i] << " ";

}