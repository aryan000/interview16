#include<iostream>
using namespace std;
#include<vector>


int number_of_palin_substring(string str , int i , int j , vector<vector<int> > output)
{
	if(i>=j)
		return 0;
	if(output[i][j] !=0)
		return output[i][j];
	if(str[i]==str[j])
	{
		output[i][j] = 1 +   number_of_palin_substring(str,i+1,j-1,output);
		return output[i][j];
	}

	output[i][j] = max(number_of_palin_substring(str,i+1,j,output) ,number_of_palin_substring(str,i,j-1,output));
	return output[i][j];
}

int main()
{
	string str;
	cin>> str;
	
	vector<vector<int> > output;
	for(int i =0;i<str.size();i++)
	{
		vector<int> temp;
		for(int j =0;j<str.size();j++)
			temp.push_back(0);

		output.push_back(temp);
	}
	cout<< str.size() + number_of_palin_substring(str,0,str.size()-1,output) << endl ;
}