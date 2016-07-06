#include<iostream>
using namespace std;
#include<stack>

bool isbalanced(string str)
{
	stack<char> s;

	for(int i =0;i<str.size();i++)
	{
		if(str[i]=='('|| str[i]=='{' || str[i]=='[')
			s.push(str[i]);

		if(str[i]==')')
		{
			if(!s.empty() && s.top()=='(')
			{
				s.pop();
				continue;
			}
			return false;
		}


		if(str[i]=='}')
		{
			if(!s.empty() && s.top()=='{')
			{
				s.pop();
				continue;
			}
			return false;
		}

		if(str[i]==']')
		{
			if(!s.empty() && s.top()=='[')
			{
				s.pop();
				continue;
			}
			return false;
		}
	}

	if(s.empty())
		return true;
	else return false;
}

int main()
{
	string str;
	cin>> str;
	cout<< isbalanced(str) << endl;
	
}