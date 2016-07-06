#include<iostream>
using namespace std;

bool isHighVowelWord(string str)
{
	bool ans = false;

	int num_of_vowel = 0 , num_of_consonant=0;

	for(int i =0;i<str.size();i++)
	{
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||str[i]=='o' ||str[i]=='u')
		{
			num_of_vowel++;
			if(i+1<str.size())
			if(str[i+1]=='a' || str[i+1]=='e' || str[i+1]=='i' ||str[i+1]=='o' ||str[i+1]=='u')	
			{
				ans = true;
			}
		}
		else
			num_of_consonant++;
	}



	return ((num_of_vowel>=num_of_consonant) && ans);
}


int main()
{
	string str;
	cin>> str;

	cout<< isHighVowelWord(str) << endl;
}