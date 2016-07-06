/* Count number of ways */

#include<iostream>
using namespace std;


int countnumberofways(int n , int i )
{
	if(i==n)
		return 1;
	if(i>n) 
		return 0;

	return countnumberofways(n,i+1) + countnumberofways(n,i+2) + countnumberofways(n,i+3);
}


int main()
{
	int n;
	cout<<"Enter the number n : ";
	cin>> n;

	int ans = countnumberofways(n,0);

	cout<<"The number of ways are : " << ans << endl;
}