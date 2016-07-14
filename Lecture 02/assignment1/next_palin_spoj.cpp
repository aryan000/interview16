#include<iostream>
using namespace std;
#include<vector>
typedef long long ll;				

bool check9(string arr)
{	
	
	for(int i =0;i<arr.size();i++)
		if(arr[i]!='9')
			return false;

	return true;
}

ll stringtoint(string v)
{
	ll ans = 0;
	for(int i =0;i<v.size();i++)
	{
		ans = ans*10 + v[i]-'0';
	}
	return ans;
}




ll next_palin(string arr , ll x )
{		
	// print(arr);

	if(check9(arr))	
		{	//cout << " is 9";
			 return stringtoint(arr) + 2;
		}

	int n = arr.size();
	string temp = arr;
	for(int i =0;i<n/2;i++)
			arr[n-i-1] = arr[i];
  
      ll num = stringtoint(arr);
     
     if(num>x)
     	return num ;
     else 
     {	
     	 arr = temp;
     	int i,carry=1 ;
     	if(n%2==0)
     	i = n/2-1;
     	else i = n/2;
     	do
     	{
     		int sum = arr[i]-'0' + 1;
     		if(sum<10)
     			{
     				arr[i] = char(sum+'0');
     				carry = 0;
     				break;
     			}
     		else
     		{
     			arr[i] = char(sum%10 + '0');
     			carry = sum/10;
     			i--;
     		}
     	}while(carry);

	     	return next_palin(arr,x);
     }





}

int main()
{	
	int t;
	cin>> t;
	while(t--)
	{
	string str;
	cin>> str;
	cout<< next_palin(str,stringtoint(str)) << endl;;

}
}