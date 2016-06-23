/* Keypad combination */

#include<iostream>
using namespace std;
#include<string>
#include<vector>


vector<string> * digitoption(char ch)
{
	vector<string> *smalleroutput = new vector<string>;
switch(ch)
{	case '2' : smalleroutput->push_back("a"); smalleroutput->push_back("b"); smalleroutput->push_back("c"); break;
	case '3' : smalleroutput->push_back("d"); smalleroutput->push_back("e"); smalleroutput->push_back("f"); break;
	case '4' : smalleroutput->push_back("g"); smalleroutput->push_back("h"); smalleroutput->push_back("i"); break;
	case '5' : smalleroutput->push_back("j"); smalleroutput->push_back("k"); smalleroutput->push_back("l"); break;
	case '6' : smalleroutput->push_back("m"); smalleroutput->push_back("n"); smalleroutput->push_back("o"); break;
	case '7' : smalleroutput->push_back("p"); smalleroutput->push_back("q"); smalleroutput->push_back("r");smalleroutput->push_back("s"); break;
	case '8' : smalleroutput->push_back("t"); smalleroutput->push_back("u"); smalleroutput->push_back("v"); break;
	case '9' : smalleroutput->push_back("w"); smalleroutput->push_back("x"); smalleroutput->push_back("y"); smalleroutput->push_back("z"); break;

}

return smalleroutput;

}

vector<string> * printkeypadcombination(string str)
{
	vector<string> *output = new vector<string>;
	// Base Case which is very important
	if(str.size()==0)
	{
		output->push_back(" ");
		return output;
	}

	
  vector<string> * smalleroutput = printkeypadcombination(str.substr(0,str.size()-1));
  vector<string> * lastdigitoption = digitoption(str[str.size()-1]);
  
  for(int i = 0;i<smalleroutput->size();i++)
  	for(int j = 0;j<lastdigitoption->size();j++)
  		output->push_back(smalleroutput->at(i)+lastdigitoption->at(j));


  	return output;



}

int main()
{
	string str;
	cout<<"Enter the keypad Combination :";
	cin>> str;

	vector<string> *allcombinatoin = printkeypadcombination(str);

	for(int i =0;i<allcombinatoin->size();i++)
		cout<< allcombinatoin->at(i) << endl;

}