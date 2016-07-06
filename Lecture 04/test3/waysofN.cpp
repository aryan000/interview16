#include<iostream>
using namespace std;
#include<vector>


void waysofN(int sum , int n , vector<int> arr)
{	

	if(sum==n)
	{
		for(int i =0;i<arr.size();i++)
			cout<<arr[i] << " ";

		cout<< endl;
	}

	if(sum>n) return;
	for(int i =1;i<n;i++)
	{
		arr.push_back(i);
		waysofN(sum+i,n,arr);
		arr.pop_back();
	}


}




int main()
{
	int n;
	cout<<"Enter the number n : ";
	cin>> n;
	vector<int> arr;
	waysofN(0,n,arr);
}