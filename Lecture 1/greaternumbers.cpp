// Write a Code to find #numbers greater than input using hte same digits

#include<iostream>
using namespace std;
#include<vector>

int  greaternum( std::vector<int> v , int index)
{
	int ans = 0 , n = v.size();
	int fact[n] ; fact[1] = 1;
	for(int i =2;i<n;i++)
		fact[i] = i*fact[i-1];
	
	for(int i =0;i< n;i++)
	{ int numgreater  =0;
		for(int j =i+1;j<n;j++)
			if(v[i]<v[j]) 
				numgreater++;

		ans += numgreater*fact[n-i-1];

	}

	return ans;
}


vector<int> reverse( vector<int> arr)
{
	int n = arr.size() , temp;
	for(int i =0;i<n/2;i++)
	{
		temp = arr[i];
		arr[i] = arr[n-i-1];
		arr[n-i-1] = temp;
	}

	return arr;
}

int main()
{

	int n;
	cout<<"Enter the number ";
	cin>> n;

	vector<int> arr;
	int temp = n;
	while(temp)
	{
		arr.push_back(temp%10);
		temp/=10;
	}

	arr = reverse(arr);
	for(int i = 0 ; i<arr.size();i++)
		cout<< arr[i] << " ";
 	int ans = greaternum(arr,0);

 	cout<<" Number of numbers greater than number is :  " << ans << endl;
}