/*Use recursion to check if a given String is palindrome or not.*/

#include<iostream>
using namespace std;
#include<cstring>


bool ispalin(char *str, int len)
{
	if(str==0) return true;
	if(str[0]!=str[len-1])
		return false;

	if(len==1) return true;
	if(len==2 && str[0]==str[1]) return true;

	return ispalin(str+1,len-2);
}

int main()
{
	char str[50];
	cout<<"Enter the string : ";
	cin>> str;
	bool ans = ispalin(str,strlen(str));

	if(ans)
		cout<<"string is a palindrome";
	else
		cout<<"string is not a palindrome";

}