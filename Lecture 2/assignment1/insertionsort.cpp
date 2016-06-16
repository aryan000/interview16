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
/*
Insertion sort is same as placing cards at its right position. Pick an element find its correct
position shift rest of the elements one ahead and then place the picked element at its location
*/
void insertion_sort(vector<int> &arr)
{
	int n = arr.size();

	int j;
	int valuetobeinserted;
	for(int i =1;i<n;i++)
	{
		valuetobeinserted = arr[i];
		j= i-1;
		while(j>=0 && arr[j]>valuetobeinserted)
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1]= valuetobeinserted;
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

	insertion_sort(arr);

	cout<<"The sorted array is : ";
	for(int i =0;i<n;i++)
	 cout<<arr[i] << " ";

}