/* Return all subarray of an array */

#include<iostream>
using namespace std;
#include<vector>


void printallsubarray(vector<int> arr)
{
	for(int i =0;i<arr.size();i++)
	{
		for(int j = i;j<arr.size();j++)
		{
			for(int k = i;k<=j;k++)
				cout<< arr[k] << " ";
			cout<< endl;
		}
	}

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


	printallsubarray(arr);
}