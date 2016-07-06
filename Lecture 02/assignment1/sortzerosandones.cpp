/*You are given with an array containing only 0’s and 1’s. Write a function to sort this
array. Find a solution which scans the array only once.*/

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
}

void sortzerosandones(vector<int> &v)
{

	int n = v.size();
	int availablezeroposition = 0  ;
	int availableoneposition = n-1;
	 
	for(int availablezeroposition = 0 , availableoneposition=n-1;availablezeroposition<availableoneposition;)
	{
		while(v[availablezeroposition]==0) availablezeroposition++;

		while(v[availableoneposition]==1) availableoneposition--;

		if(availablezeroposition<availableoneposition){
				v[availablezeroposition++]=0;
				v[availableoneposition--]=1;
			}
		if(availablezeroposition>availableoneposition) break;
		 
		 print(v);

		 getch();

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