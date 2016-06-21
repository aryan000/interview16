/* Convert a function to change string to intege */

#include<iostream>
using namespace std;
#include<cstring>
#include<cstdlib>

int stoi( string str  , int index)
{

if(index==1) 
	return str[0]-'0';

int value = stoi(str,index-1);
return value*10 + str[index-1]-'0';

}

int ctoi(char * str , int n)
{
	if(n==1) 
		return *str - '0';

	int ans = ctoi(str,n-1);
	return ans*10 + str[n-1]-'0';
}


int main()
{
	string str;
	cout<<"Enter the string  1 : " ;

	cin>> str;
	// cout<< str.size();

	int n = stoi(str,str.size());
	cout<<"The number using string to integer conversion is :  " << n << endl;

	char ch[10];
	cout<<"Enter the character array : ";
	cin>> ch;
	 n = ctoi(ch,strlen(ch));
	 cout<< "The number using character array to integer conversion is : " << n << endl;

	 cout<<"Method Three !!!\n";
	 char number[100];
	 cout<<"Enter the number in character : " ;
	 cin>> number ;
	 n = atoi(ch);
	 cout<<"The conversion of character using inbuilt function in stdlib (atoi) is : " <<  n << endl;
	 cout<<"The conversion of character using inbuilt function in stdlib (atol) is :  " << atol(ch) << endl;
	
}