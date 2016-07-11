#include<bits/stdc++.h>
using namespace std;

class rectangle
{
	public : 
	int leftx , lefty , rightx , righty;

}; 


bool check(rectangle a , rectangle b)
{
	if(a.rightx <= b.leftx || b.rightx <= a.leftx)
		return false;
	if(a.lefty <= b.righty || b.lefty <= a.righty)
		return false;

	return true;
}

int main()
{	
  int t;
  cin>> t;
  while(t--)
  {
  	 rectangle a , b;
  	 cin>> a.leftx >> a.lefty >> a.rightx >> a.righty;
  	 cin>> b.leftx >> b.lefty >> b.rightx >> b.righty;

  	 cout<< check(a,b) << endl ;
  }
	
}