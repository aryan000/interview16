/* Printing all subset */

#include<iostream>
using namespace std;
#include<vector>
#include<string>


void printsubset(vector<int> v ,int index,  string str)
{
	if(index==0)
	{
		cout<< str<< endl;
		return;
	}

	printsubset(v,index-1,str);
	printsubset(v,index-1,char(v[index-1]+'0') + str );

}


int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>> n;

	vector<int> arr;
	int temp;

	for(int i =0;i<n;i++)
	{
	cin>> temp;
	arr.push_back(temp);
	}


	printsubset(arr,arr.size(),"");

	return 0;
}