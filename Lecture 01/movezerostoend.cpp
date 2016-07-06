/* Push all the zeros to end maintaining the order of elements */

#include<iostream>
using namespace std;
#include<vector>

vector<int> movezeros( vector<int> arr)
{

   int count = 0 , j=0;
   for(int i =0;i<arr.size();i++)
   {
   	  if(arr[i]!=0)
   	  {
   	  	arr[j] = arr[i]; j++;
   	  }

   }
   for(;j<arr.size();j++)
   	 arr[j] = 0;

   	return arr;
}

int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>> n;

	vector<int> arr;
	int temp;

	cout<<"Enter the array elements : " ;

	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}

	arr = movezeros(arr);

	for(int i =0;i<n;i++)
		cout<< arr[i] << " ";

}