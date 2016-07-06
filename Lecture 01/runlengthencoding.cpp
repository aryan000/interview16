/* Sting Compression - Run Length Encoding */
#include<iostream>
using namespace std;
#include<cstring>
#include<cstdlib>

void compressstring(char *str)
{
	int count;
	int nextavailableposition =0;
	for(int currentposition =0;currentposition<str[currentposition]!='\0';currentposition++)
	{	count=1;
		str[nextavailableposition++] = str[currentposition];

		if(str[currentposition+1]==str[currentposition])
		{
			while(str[currentposition+1]==str[currentposition])
			{
				count++;
				currentposition++;
			}

		}
		if(count<10)
				str[nextavailableposition++] = char(count+'0');

		else
		{
			char ch[10] ;
			 itoa(count,ch,10); 
			 /* itoa converts integer to character where  function is defined as '''char *  itoa ( int value, char * str, int base );'''
			 */
			 for(int i =0;i<ch[i]!='\0';i++)
			 	str[nextavailableposition++] = ch[i];
		}


	}
	str[nextavailableposition] = '\0';
}

int main()
{
	char str [100];
	cout<<"Enter the string : " ;
	cin>> str;

	compressstring(str);

	cout<<"The encoded string is : " << str << endl;

	return 0;
}