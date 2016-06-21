/* Count number of zeros in a number using  recursion */


#include<iostream>
using namespace std;

int numofzeros(int n)
{
	if(n==0) 
		return 1;
	if(n>0 && n< 10) return 0;

	if(n%10==0) return 1 + numofzeros(n/10);

	return numofzeros(n/10);
}

int main()
{
	int n;
	cout<<"Enter the number : " ;
	cin>> n;

	int ans =numofzeros(n);
	cout<<"NUmber of zeros in the integer is : " << ans << endl;
}