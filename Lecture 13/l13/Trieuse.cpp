#include<iostream>
using namespace std;
#include<map>

class TrieNode
{
	public : 
	char data;
	map<char,TrieNode*> children;
	bool isterminal;

	TrieNode(char data)
	{
		this->data = data;
	}
};


class Trie
{	
	public : 
	TrieNode *root;
	int num_of_words;

	Trie()
	{	
		// creating root of the trie with null character
		root=new TrieNode('\0');
		num_of_words = 0;

	}

	private : 
	bool contains(string word , TrieNode *node,int index)
	{
		if(index==word.size())
		{
			if(node->isterminal)
				return true;
			return false;
		}

		char current_char = word[index];

		if(node->children.count(current_char)==0)
			return false;
		return contains(word,node->children[current_char],index+1);

	}

	public : 

	bool contains(string word)
	{
		return contains(word,root,0);
	}

	private : bool remove(string word , TrieNode *node , int index)
	{
		if(index==word.size())
		{
			if(node->isterminal)
				node->isterminal = false;

			if(node->children.size()==0)
				{delete node; return true;}
			return false;

		}

		char current_char = word[index];
		if(node->children.count(current_char)!=0)
		{
			bool ans = remove(word, node->children[current_char],index+1);
			if(ans)
			{
				node->children.erase(current_char);

				if(node->children.size()==0)
					{delete node; return true; }
				return false;
			} 
			return false;
		}



	}

	public  : 	bool remove(string word)
	{  
		 return remove(word,root,0);

	}

	private : 
	static bool insert( TrieNode *node , string word , int index)
	{

		// Base case , when it reaches the end of the string
		if(index==word.size())
		{
			if(node->isterminal)
				return false;
			node->isterminal = true;
			return true;

		} 

		char current_character = word[index];
		TrieNode *nextNode = node->children[current_character];

		if(nextNode==NULL)
		{
			nextNode = new TrieNode(current_character);
			node->children[current_character] = nextNode;

		}
		return insert(nextNode,word,index+1);

		// if successfully inserted return true else false
	}

	public : 
	void insert(string word)
	{
		if(insert(root,word,0))
			num_of_words++;

	}
};

int main()
{
	Trie T;

	 
	 

	 char ch = '1';
	 cout<< " Press 1 to add , 2 to read , 3 to remove : ";
	 string str;
	 while(ch!= 'q')
	 {	cin>> ch;
	 	if(ch=='1')
	 	{ cin>> str; 
	 		T.insert(str);
	 	}

	 	if(ch=='2')
	 	{	
	 		cin>> str;
	 		if(T.contains(str))
	 			cout<<"Element exists ";
	 		else cout<<"Element does not exists";
	 	}
	 	if(ch=='3')
	 	{	
	 		cin>> str;
	 		if(T.remove(str))
	 			cout<<"Element removed ";
	 		else 
	 			cout<<"Element does not exists";
	 	}


	 	cout<< " Press 1 to add , 2 to read , 3 to remove : ";
	 }


}