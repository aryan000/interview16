/* Program to move all zeros to beginning and all 1's to end and rest all in same order */

#include<iostream>
using namespace std;
#include<vector>

void rearrange(vector<int>& v)
{
	if(v.empty()) return ;

	int zeros = 0 , ones = 0;
	for(int i =0;i<v.size();i++)
	{
		if(v[i]==0) zeros++;
		if(v[i]==1)  ones++;
	}

 int n = v.size();
 
 int availableposition = n-1;
 for( int currentposition = n-1; currentposition>=0;currentposition--)
 {
 	if(v[currentposition]!=0 && v[currentposition]!=1)
 		v[availableposition--] = v[currentposition];
 }

 int i;
 for(i =0;i<zeros;i++)
 	v[i] = 0;

 for( ;i<n-ones;i++)
 	v[i] = v[++availableposition];

  for(;i<n;i++)
  	v[i] = 1;



  

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

rearrange(arr);

for( int i =0;i<n;i++)
	cout<< arr[i] << " ";

}
