// Rabin Karp String Matching Algo

// At each step we are finding hash of m characters of T and comparing the hash with the hash of pattern 
// we need the hash function which creates the hash in O(1) time for finding the hash of m characters of T every time
// for a good hash function complexity of is O(m+n)
// Only for numbers

#include<iostream>
using namespace std;
#include<cmath>
int code(string str)
{
	int value = 0;
	for(int i =0;i<str.size();i++)
	{
		value = value*10 + str[i]-'0';
	}

	return value;
}

void find(string T , string P)
{	
	
	int hash = code(P);

	int x = code(T.substr(0,P.size()));
	int m = P.size();
	bool flag = false;
	int ans;
	int multiplier = ceil(pow(10,m-1));
	for(int i = 0; i<=T.size()-m;i++)
	{
				
			// cout<< T[i] << endl;
		// cout<< x << endl;
		if(x==hash)
		{
			flag = true;
			cout<< " Found at index : " << i << endl;
			 
		}	
		
		x = 10*(x - multiplier*(T[i] -'0')) + T[i+m] - '0';

	}


	if(!flag) cout<<"not found ";
}

int main()
{
	string T , P;
	// cin>> T;
	// cin>> P;
	getline(cin,T);
	getline(cin,P);

	 find(T,P);
}