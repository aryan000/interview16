/*
Given a input number in array form. Push all the zeroes to the end maintaining the order
of rest of elements
*/

#include<iostream>
using namespace std;
#include<vector>


void pushzerostoend(std::vector<int> &v)
{
   int count=0,position=0;;
   for(int i =0;i<v.size();i++)
   	 { if(v[i]==0) count++;
   	  
   	   if(v[i]!=0)
		{
			v[position++] = v[i];
		}
	}

	while(position < v.size())
	{
		v[position++] = 0;
	}


}


int main()
{

	int n;
	cout<<"Enter the size of the array : " ;
	cin>> n;

	vector<int> arr(n);
	int temp;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}

	pushzerostoend(arr);

	cout<<"after pushing zeros to end , array is : ";
	for(int i =0;i<n;i++)
		cout<< arr[i] << " ";

}