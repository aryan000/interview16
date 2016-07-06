/*What if the array has 0’s, 1’s and 2’s. Find another solution which scans the array only
once..*/

#include<iostream>
using namespace std;
#include<vector>
#include<cstdio>
#include<conio.h>


void print(vector<int> arr)
{
	// cout<<"Printing\n";
	for(int i =0;i<arr.size();i++)
		cout<< arr[i] << " ";
	cout<<endl;
	getch();
}

void swap(int*a , int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortzerosandones(vector<int> &v)
{

	int n = v.size();
	int i = 0 , j = 0 , k = n-1;

	while(i<k && j<k)
	{

		// print(v);

		while(v[i]==0)
		{
			
			if(i==j) j++;
			i++;
		}

		while(v[j]==1)
			j++;

		if(v[j]==0 && j!=i) 
			{
				swap(&v[i],&v[j]);
				continue;
			}
		else
		{
			while(v[k]==2)
				k--;

			if(v[k]==0 && k>i)
			{
				swap(v[k],v[i]);
				continue;
			}
			else if(v[k]==1 && k>j)
				swap(v[k],v[j]);
		}
	}
	
}



int main()
{
	int n;
	cout<<"Enter the size of the array : " ;
	cin>> n;

	vector<int> arr;
	int temp;

	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}


	sortzerosandones(arr);

	print(arr);
	

	return 0;
}