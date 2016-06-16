/* Merge Sort */


#include<iostream>
using namespace std;
#include<vector>
#include<cstdio>


void merge(int arr[], int l , int mid , int r)
{

	// cout<<" before modified array is : " ;
	// for(int i =l;i<=r;i++)
	// 	cout<< arr[i] <<  " ";
	// cout<< endl;
	vector<int> v ;  
	int i = l;
	int j = mid+1;
	while(i<=mid && j<=r)
	{
		if(arr[i]<arr[j])
		{
			v.push_back(arr[i]);
			i++;
		}
		else
		{
			v.push_back(arr[j]);
			j++;
		} 


	}

	while(i<=mid)
	{
		v.push_back(arr[i]);
		i++;
	}
	while(j<=r)
	{
		v.push_back(arr[j]);
		j++;

	}



	for(int i =0;i<v.size();i++)
		{  arr[l+i] = v[i];

			// cout<< v [i] << " ";
		}

 //  cout<<"modified array is : " ;
	// for(int i =l;i<=r;i++)
	// 	cout<< arr[i] <<  " ";



	// cout<<endl;
	// getchar();
	return ;





}

void mergesort( int v[] , int i , int n)
{

if(i< n)
{
	int mid = (i+n)/2;
	mergesort(v,i,mid);
	mergesort(v,mid+1,n);
	merge(v,i,mid,n);
}

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

	mergesort(arr,0,n-1);

	cout<<"The sorted array is : ";
	for(int i =0;i<n;i++)
	 cout<<arr[i] << " ";

}