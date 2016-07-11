#include<bits/stdc++.h>
using namespace std;

// using extra space 

char * encode( char *str)
{
	char *ans = new char[strlen(str)+1];

	int i , nextposition=0 , count = 0;
	for(int i =0;str[i]!='\0';i++)
	{
			ans[nextposition++] = str[i];
			count =0;

			
			while(str[i+1]!='\0' && str[i+1]==str[i])
				{i++; count++;}
			ans[nextposition++] = char(count+'1');

	}

	ans[nextposition] = '\0';
	return ans;
}


int main()
{
	int t;
	cin>> t;
	while(t--)
	{
	  char *str = new char[100];
	  cin>> str;
	  char* ans = encode(str);
	  cout<< ans << endl;

	}
}