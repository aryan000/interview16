#include<iostream>
using namespace std;
#include<vector>
#include<conio.h>

void print(vector<int> v)
{
	for(int i =0;i<v.size();i++)
		cout<< v[i] << " ";
	cout<< endl;
}

bool check9(vector<int> arr)
{	
	
	for(int i =0;i<arr.size();i++)
		if(arr[i]!=9)
			return false;

	return true;
}

int getvectortoint(std::vector<int> v  , int start , int end)
{
	int ans = 0;
	for(int i =start;i<end;i++)
	{
		ans = ans*10 + v[i];
	}

	return ans;
}

vector<int> getinttovector (int n)
{
	vector<int> ans;
	if(n<10)
	{
		ans.push_back(n);
		return ans;
	}

	ans = getinttovector(n/10);
	ans.push_back(n%10);
	return ans;


}


int next_palin(vector<int> arr , int x)
{		
	// print(arr);

	if(check9(arr))
		return x+2;

	int n = arr.size();
	for(int i =0;i<n/2;i++)
			arr[n-i-1] = arr[i];
  
     int temp = getvectortoint(arr,0,arr.size());

     if(temp>x)
     	return temp;


     else 
     {
     	arr = getinttovector(x);
     	int i,carry=1 ;
     	if(n%2==0)
     	i = n/2-1;
     	else i = n/2;
     	do
     	{
     		int sum = arr[i] + 1;
     		if(sum<10)
     			{
     				arr[i] = sum;
     				carry = 0;
     			}
     		else
     		{
     			arr[i] = sum%10;
     			carry = sum/10;
     			i--;
     		}
     	}while(carry);

	     	return next_palin(arr,x);
     }





}

int main()
{
	int n;
	cin>> n;
	 	vector<int> arr = getinttovector(n);


	cout<< next_palin(arr,n);
}