#include<bits/stdc++.h>
using namespace std;

class points
{
	public : 
	int x ;
	int y ;

	double length(points a)
	{	
	   double ans = (a.x-x)*(a.x-x) +  (a.y-y)*(a.y-y);
	   return  ans;
	}
};

int main()
{
	int t;
	cin>> t;
	while(t--)
	{
		points a , b , c, d;
		 
		 cin>> a.x >> a.y ;
		 cin>> b.x >> b.y ;
		 cin>> c.x >> c.y ;
		 cin>> d.x >> d.y ;

		 vector<double> lengths;
		 lengths.push_back(a.length(b));
		 lengths.push_back(a.length(c));
		 lengths.push_back(a.length(d));
		 lengths.push_back(b.length(c));
		 lengths.push_back(b.length(d));
		 lengths.push_back(c.length(d));

		 sort(lengths.begin(),lengths.end());

		 // for(int i =0;i<lengths.size();i++)
		 // 	cout<< lengths[i] << " ";

		 if(lengths[0]==lengths[1])
		 	{if(lengths[1]==lengths[2])
		 		if(lengths[2]==lengths[3])
		 			if(lengths[4]==lengths[5])
		 	
		 		cout<<true << endl;	
		 	}	
		 else cout<< false << endl;;

	}

	return 0;
}