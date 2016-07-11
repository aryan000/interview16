#include<bits/stdc++.h>
using namespace std;

/* 
The structure of the node of the queue is*/

struct QueueNode
{
    int data;
    QueueNode *next;
};


// and the structure of the class is
class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
public :
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
    void push(int);
    int pop();
};

 

/* The method push to push element into the queue*/
void Queue:: push(int x)
{
           // Your Code
        QueueNode *temp = new QueueNode;
        temp->data = x;
        temp->next = NULL;
        
        if(front==NULL)
        {
            front = temp;
            rear = temp;
            
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        cout<< "inserted " << x << endl;
}

/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
        // Your Code   
         // Your Code   
        QueueNode *temp = front;
        int val;
        if(front==NULL && rear==NULL)
            return -1;
        if(front==rear)
        {   front=NULL;
           rear = NULL;
          temp->next = NULL;
          val = temp->data;
         delete temp;
         return val;
            
        }
        else
        {
            front = front->next;
            temp->next = NULL;
            val = temp->data;
            delete temp;
            return val;
        }    
}


int main()
{
	int t;
	cin>> t;
	while(t--)
	{	Queue q;

		int query;
		cin>> query;
		while(query--)
		{
			int n;
			cin>> n;
			if(n==1)
			{
				int x;
				cin>> x;
				q.push(x);

			}
			if(n==2)
			{
				cout<< q.pop() << endl;
			}
		}

	}

	return 0;
}