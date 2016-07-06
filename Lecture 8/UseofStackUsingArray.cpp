#include<iostream>
using namespace std;
#include"stack.h"



int main()
{
	stack<int> s;

	s.push(1);
	cout<< "element at stack top " << s.top() << endl;
	s.push(2);

	cout<< "element at stack top " << s.top() << endl;
	s.push(3);

	cout<< "element at stack top " << s.top() << endl;
	s.pop();
	cout<< "element at stack top " << s.top() << endl;

	cout<< " is stack empty ?? " << s.isempty() << endl;
	cout<< "element at stack top " << s.top() << endl;

	cout<< " size of current stack : " << s.size() << endl;
	cout<< "element at stack top " << s.top() << endl;

	s.pop();
	cout<< "element at stack top " << s.top() << endl;
	s.pop();
	cout<< "element at stack top " << s.top() << endl;
	s.pop();
	cout<< "element at stack top " << s.top() << endl;
	s.pop();
	cout<< "element at stack top " << s.top() << endl;

	cout<< " is stack empty ?? " << s.isempty() << endl;

	cout<< " size of current stack : " << s.size() << endl;

	s.push(1);
	s.push(1);s.push(1);s.push(1);s.push(1);s.push(1);
	return 0;

}