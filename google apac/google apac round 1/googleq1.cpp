#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include<conio.h>
#include <fstream>

class Country
{	
	public : 
	string name;
	int size ;

	 
	 Country (string name)
	{
		this->name = name;
		set<char> uniqueentry;
		for(int i =0;i<name.size();i++)
		{
			if(name[i]==' ')
				continue;

			else
				uniqueentry.insert(name[i]);
		}

	this->size = uniqueentry.size();
	}
};

bool lexicographically(string s1 , string s2)
{	
	

	for(int i =0;i<min(s1.size(),s2.size()); i++)
	{	
		if(s1[i]==s2[i])
			continue;
		if(s1[i]<s2[i])
			return true;
		else return false;
		
	}

}
bool Compare(const Country&c1 , const Country&c2)
{	
	if(c1.size > c2.size )
		return true;

	if(c1.size < c2.size)
		return false;

	if(c1.size==c2.size)
	{
		 
		
		return lexicographically(c1.name,c2.name);
	}
};

void print(vector<Country> v)
{	//cout<<"printing";
	for(int i =0;i<v.size();i++)
	{
		cout<< v[i].name << " " << v[i].size << endl;
	}
}

int main(int argc, char const *argv[])
{
	 
	ifstream infile;
	// infile.open ("A-small-practice (1).in", ios::binary);
	infile.open ("A-large-practice.in", ios::binary);
   	ofstream myfile;
   	myfile.open ("output1.txt");

	while(!infile.eof())
	{	
		int t;
	//scanf("%d",&t);

			 infile >> t;
	int x = 1;
	while(t--)
	{
		int n;
		//scanf("%d",&n);
		fflush(stdin);
		 

		// cout<< str << endl;
		infile>> n;
		// cout<< n << endl;
		vector<Country> people;
		 	string str;
		 getline(infile,str);
		for(int i =0;i<n;i++)
		{	
			
			getline (infile,str);

			// cout<< str << endl;
			// infile>> str;
			// gets(str);
			Country temp(str);
			people.push_back(temp);

			
		}

		// print(people);
		sort(people.begin(),people.end(),Compare);

		/*cout<< "stored values are \n";
		for(int i =0;i<people.size();i++)
			cout<< people[i].name << endl;
		// */
		// print(people);
		// getch();
		string y = people[0].name;
		// cout<< y << endl;
		// cout << x << endl;
		myfile << "Case #" << x << ": " << y << "\n";
		// printf("Case #%d: %s\n",x,y);
		x++;

		 
	 } // end of while;
	 infile.close();
	 myfile.close();
	 break;


}

	return 0;
}