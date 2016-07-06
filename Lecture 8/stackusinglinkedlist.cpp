#include<iostream>
using namespace std;
#include "stacklinkedlist.h"

int main()
{
	stack<int> s;

	s.push(10);
	// cout<< "element at stack top " << s.top() << endl;
	s.push(2);

	cout<< "element at stack top " << s.top() << endl;
	s.push(3);

	cout<< "element at stack top " << s.top() << endl;
	// s.pop();
	cout<< "element at stack top " << s.top() << endl;

	cout<< " is stack empty ?? " << s.isempty() << endl;
	// cout<< "element at stack top " << s.top() << endl;

	// cout<< " size of current stack : " << s.getsize() << endl;
	// cout<< "element at stack top " << s.top() << endl;

	// s.pop();
	// cout<< "element at stack top " << s.top() << endl;
	// s.pop();
	// cout<< "element at stack top " << s.top() << endl;
	// s.pop();
	// cout<< "element at stack top " << s.top() << endl;
	// s.pop();
	// cout<< "element at stack top " << s.top() << endl;

	// cout<< " is stack empty ?? " << s.isempty() << endl;

	// cout<< " size of current stack : " << s.getsize() << endl;

	// s.push(1);
	// s.push(1);s.push(1);s.push(1);s.push(1);s.push(1);
	// 
	return 0;

}