/* Given two Strings check if one is reverse of the other.
*/

#include<iostream>
using namespace std;
#include<cstring>

bool isreverse(char *a , char*b , int asize, int bsize)
{

	if(asize!=bsize) return false;
	if(asize==0 && bsize==0) return true;
	if(a[0]!=b[bsize-1])
		return false;

	return (a+1,b,asize-1,bsize-1);
}


int main()
{
	
	char str1[50] , str2[50];

	cout<<"Enter first string :";
	cin>> str1;
	cout<<"Enter second string :";
	cin>> str2;

	bool ans = isreverse(str1,str2,strlen(str1),strlen(str2));

	if(ans)
		cout<<"strings are reverse of each other";

	else cout<<"strings are not reverse of each other";



}