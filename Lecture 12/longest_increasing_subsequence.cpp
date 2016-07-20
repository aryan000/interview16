#include<iostream>
using namespace std;
#include<vector>

int lis(vector<int> arr , int index  , int max_element)
{
	if(index==arr.size())
		return 0;

	if(arr[index]>max_element)
	{
		int ans1 = 1 + lis(arr , index+1, arr[index]);
		int ans2 = lis(arr,index+1,max_element);
		return max(ans1,ans2);
	}
	return lis(arr,index+1,max_element);
}

int recursive_lis(vector<int> arr , int index , int max_element , int *output)
{
	if(index==arr.size())
		return 0;

	if(output[index]!=0)
		return output[index] ;

	if(arr[index]>max_element)
	{
		int ans1 = 1 + recursive_lis(arr,index+1,arr[index],output);
		int ans2 = recursive_lis(arr,index+1,max_element,output);

		output[index] = max(ans1,ans2);
		return output[index];
	}

	int ans = recursive_lis(arr,index+1,max_element,output);
	output[index] = ans;
	return output[index];

}


int iterative_lis(vector<int> arr )
{
	if( arr.size()==0)
		return 0;

	vector<int> temp(arr.size(),1);

	int ans = 0;

	for(int i =1;i<arr.size();i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[j]<arr[i] && temp[i] <temp[j]+1)
					temp[i] = temp[j]+1;

			ans = max(ans,temp[i]);
		}
	}


return ans;



}


int main()
{
	int n;
	cin>> n;
	vector<int> arr; 
	int temp;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}	

	int *output = new int[n];
	for(int i =0;i<n;i++)
	{
		output[i] = 0;
	}

	// cout<< recursive_lis(arr,0,0,output);

	cout<< iterative_lis(arr);
}