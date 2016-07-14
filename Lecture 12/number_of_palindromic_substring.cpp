#include<iostream>
using namespace std;
#include<vector>

int count_palin(string str, int i , int j)

{
	if(i>j)
		return 0;

	if(str[i]==str[j])
		return 1+ count_palin(str,i+1,j-1);

	return max(count_palin(str,i+1,j),count_palin(str,i,j-1));
}

int main()
{
		
		string str;
		cin>> str;

		int ans = count_palin(str,0,str.size()-1);
		cout<< ans + str.size()<< endl;
}