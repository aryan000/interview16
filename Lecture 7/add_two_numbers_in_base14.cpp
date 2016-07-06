/* add two numbers in base 14*/

#include<iostream>
using namespace std;
#include<string>
#include<map>

string reverse(string str)
{	
	int n = str.size();
	char ch  ;
	for(int i =0;i<n/2;i++)
	{
		ch = str[i] ;
		str[i] = str[n-i-1];
		str[n-i-1] = ch;

	}

	return str;
}

string add_digits( char first , char second , int &carry)
{
	map<char,int> hash;
	hash['a'] = 10;
	hash['b'] = 11;
	hash['c'] = 12;
	hash['d'] = 13;
	hash['1'] = 1;
	hash['2'] = 2;
	hash['3'] = 3;
	hash['4'] = 4;
	hash['5'] = 5;
	hash['6'] = 6;
	hash['7'] = 7;
	hash['8'] = 8;
	hash['9'] = 9;

	map<int,char> change;
	change[10] = 'a';
	change[11] = 'b';
	change[12] = 'c';
	change[13] = 'd';

	int a = hash[first] ;
	int b = 0;
	if(second!=' ') b  = hash[second] ;

	int sum = a+b +carry;

	string ans ; 
	if(sum<14) carry = 0;

	if(sum>14)
	{
		carry = sum % 14;
		sum = sum/14;
		
	}

	if(sum<=9)
	{
		 
		ans = char(sum+'0');
		return ans;
	}

	else if(sum>9 &&  sum<14)
	{	 
		ans = change[sum];
		return ans;

	}
	else if(sum==14)
	{
		ans = '0';
		carry = 1;
	}

	return ans;
}

string add(string s1 , string s2 )
{
	
	string ans;
	
	string temp1 , temp2;
	temp1 = reverse(s1);
	temp2 = reverse(s2);


	int i = 0 , j = 0 , carry = 0;

	while(i<temp1.size() && j < temp2.size())
	{
		ans += add_digits(temp1[i],temp2[j],carry);

		i++;
		j++;
	}

	while(i<temp1.size())
		ans += add_digits(temp1[i++],' ',carry);

	while(j<temp2.size())
		ans += add_digits(temp2[j++],' ',carry);

	return reverse(ans);
}

int main()
{
	string s1 , s2;
	cout<<"Enter the first number : ";
	cin>> s1 ;
	cout<< " Enter the second number : ";
	cin>> s2;


	string ans = add(s1,s2);
	cout<< " The sum of the number is :  " << ans << endl;
}