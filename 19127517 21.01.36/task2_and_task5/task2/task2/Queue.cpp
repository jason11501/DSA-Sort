#include "Queue.h"

Node* getNode(const string& value)
{
	Node* newNode = new Node;
	newNode->value = value;
	newNode->next = nullptr;
	return newNode;
}

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
	len = 0;
}

bool Queue::isEmpty()
{
	return len <= 0;
}

void Queue::enqueue(const string& value)
{
	Node* node = getNode(value);
	if (head != nullptr && tail != nullptr)
	{
		tail->next = node;
		tail = node;
	}
	else
		head = tail = node;
	len++;
}

string Queue::dequeue()
{
	if (head && tail)
	{
		string temp = head->value;
		Node* tempNode = head;
		head = head->next;
		delete tempNode;
		len--;
		if (head == nullptr)
			tail = nullptr;
		return temp;
	}

	head = tail = nullptr;
	return "";
}

Queue::~Queue()
{
	if (head)
	{
		Node* temp;
		while (head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
}
