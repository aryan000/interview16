#include<iostream>
using namespace std;
#include<stack>
#include<string>

bool isDuplicateparenthesis(string str)
{
	stack<pair<char,int> > s;

	pair<char,int> temp1 , temp2;
	for(int i =0;i<str.size();i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i] =='[')
			s.push(make_pair(str[i],i));

		if(str[i]==')' || str[i]=='}' || str[i]==']')
		{	
			temp1 = s.top();
			s.pop();

			if(i+1!=str.size() )
			{
				if(str[i+1]==')' || str[i+1]=='}' || str[i+1] ==']')
				{
					
					temp2 = s.top(); 

					// cout<< temp1.second << " and " << temp2.second << endl;
					if(temp1.second-1==temp2.second)
						return true;


				}

			}

		}

	}

	return false;
}

int main()
{
	string str;
	cin>> str;

	cout<< isDuplicateparenthesis(str) << endl;

}