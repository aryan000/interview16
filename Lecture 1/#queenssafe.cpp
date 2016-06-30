/* Check if queens are safe or not */
#include<iostream>
using namespace std;

bool issafe(vector<int> x , vector<int> y)
{
	
}


int main()
{
	int n;
	cout<<"Enter the size of Chess Board : ";
	cin>> n;

	vector<int> x , y;
	int a,b,i;

	for( i =0;i<n;i++)
	 { 
	 	cin>> a >> b;
	 	x.push_back(a);
	 	y.push_back(b);
	 }	

	 bool flag = issafe(x,y);

	 if(flag)
	 {
	 	cout<<"The position is safe ";

	 }

	 else 
	 	cout<< "the position is not safe ";



}