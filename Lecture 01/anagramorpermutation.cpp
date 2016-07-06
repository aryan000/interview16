/* check two strings are anagram of each other */

#include<iostream>
using namespace std;
#include<map>

bool anagramcheck(string str , string str1)
{
	if(str.size()!=str1.size()) return false;

	map<char,int> hash;
	int i =0;
	for(i=0;i<str.size();i++)
	{ 
		if(hash.count(str[i]>0))
			hash[str[i]] +=1;

		else hash[str[i]] = 1;

	}

	for(i=0;i<str1.size();i++)
	{
		if(hash.count(str1[i])>0)
		{
			hash[str[i]] -=1;
			if(hash[str[i]]<0) return false;
		}
		else return false;
	}

	return true;
}

int main()
{
	string str;
	cin>> str;
	string str1;
	cin>> str1;

	bool ans  = anagramcheck(str,str1);
	if(ans) cout<<" Strings are anagram of each other " ;
	else cout<<"Strings are not anagrams of each other ";


}