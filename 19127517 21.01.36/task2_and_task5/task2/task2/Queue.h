#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

struct Node
{
	string value;
	Node* next;
};

class Queue
{
	Node* head;
	Node* tail;
	int len;
public:
	Queue();
	bool isEmpty();
	void enqueue(const string&);
	string dequeue();
	~Queue();
};

Node* getNode(const string&);

#endif
