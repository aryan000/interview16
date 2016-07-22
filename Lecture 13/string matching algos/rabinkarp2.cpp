#include<iostream>
using namespace std;

#define d 256
#define mod 19 // its a primt number
// d is taken as the hash multiplier
#define loop(x,n) for(int x = 0;x<n;x++)


void find(string Text , string Pattern)
{	
	int n = Text.length();
	int m = Pattern.length();
	int multiplier = 1;
	int i ;
		loop(i,m-1)
		multiplier = (multiplier*d)%mod;

	// multiplier = pow(d,m-1)%mod;

	int hasht = 0 , hashp = 0;

	loop(i,m)
	{
		hasht = (d*hasht + Text[i])%mod;
		hashp = (d*hashp + Pattern[i])%mod;	
	}


	for(int i =0;i<=n-m;i++)
	{	
		// cout<< hashp <<" and " <<  hasht << endl; 
		if(hashp == hasht)
		{	int j;
			for( j = 0;j<m;j++)
				if(Pattern[j]!=Text[i+j])
					break;

			if(j==m) cout<<"Pattern found at index :  " << i << endl;

		}

		hasht = (d*(hasht - Text[i]*multiplier) + Text[i+m] )%mod;
		if(hasht<0)
			hasht += mod;
	}




}


int main()
{
	string Text , Pattern;
	getline(cin,Text);
	getline(cin,Pattern);


	find(Text,Pattern);
}