/* To find the longest substring of given string s which contains at most 2 unique characters */

#include<iostream>
using namespace std;

/* This is brute force O(n^2) solution */

string LongestTwoUniqueCharSubstring(string s)
{
	string temp;
	int flag = 0 ; 
	char a , b;
	int j =0;
	int startindex = 0 , endindex = 0 , tempstartindex = 0 , tempendindex = 0 , max_size = 0 , temp_size = 0;

	for(int i =0;i<s.size();i++)
	{ 
		a = s[i];
		int x = i;
		tempstartindex = i;
		while(s[x]==a) x++;
		b = s[x];
		while(s[x]==b || s[x]==a) x++;
		tempendindex = x-1;

		temp_size = tempendindex - tempstartindex +1;
		if(temp_size>max_size)
		{
			max_size = temp_size;
			startindex = tempstartindex;
			endindex = tempendindex;
		}

	}

	for(int i = startindex;i<=endindex;i++)
		temp += s[i];


	return temp;
}

/* This is the optimized O(n) solution for the same questions */
string LongestTwoUniqueCharSubstring2(string s)
{
	string temp;
	char a , b;
	int j =0;
	int startindex = 0 , endindex = 0 , tempstartindex = 0 , tempendindex = 0 , max_size = 0 , temp_size = 0;
	int switchindex = 0;

		a = s[0];
		int x = 0;
		tempstartindex = 0;
		while(s[x]==a) x++;
		switchindex = x;
		int i = x;
	while(i<s.size())
	{ 
		tempstartindex = switchindex;
		switchindex = i;
		b = s[i];
		// cout<< " a is : " << a << " and " << " b is : " << b << endl;
		while(s[i]==b || s[i]==a) 
			{ 
				if(s[i]!=s[i-1]) switchindex = i;
				i++;
			}
		tempendindex = i-1;
		a = s[switchindex];
		temp_size = tempendindex - tempstartindex +1;
		if(temp_size>max_size)
		{
			max_size = temp_size;
			startindex = tempstartindex;
			endindex = tempendindex;
		}

	}

	for(int i = startindex;i<=endindex;i++)
		temp += s[i];


	return temp;
}



int main()
{

	string str;
	cout<<"Enter the string : " ;
	cin>> str;

	string temp = LongestTwoUniqueCharSubstring(str);
	string temp2 = LongestTwoUniqueCharSubstring2(str);
	cout<<"The longest two unique character substring is : " << temp<<endl;;
	cout<<"The longest two unique character substring is : " << temp2<<endl;;
	return 0;
}