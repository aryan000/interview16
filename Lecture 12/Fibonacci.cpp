#include<iostream>
using namespace std;

// Recursive and exponential solution
int fib(int n)
{
	if(n==0|| n==1)
		return n;

	return fib(n-1) + fib(n-2);
}

//Iterative and LInear solution with dp

int fibdp(int n)
{
	int arr[n+1] = {0};
	arr[0] = arr[1] = 1;
	for(int i =2;i<=n;i++)
		arr[i] = arr[i-1] + arr[i-2];

	return arr[n];
}

int main()
{
	cout<< "Enter the number  :" ;
	int n;
	cin>> n;
	cout<<"THe nth fibonacci number is :  " << fib(n-1);
	cout<<"THe nth fibonacci number is :  " << fib(n-1);
}