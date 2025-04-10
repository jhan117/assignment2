#pragma once
#include "InterfaceQueue.h"
#include "Node.h"

class LinkedListQueue : public InterfaceQueue
{
public:
	LinkedListQueue(int size);
	~LinkedListQueue();

	bool isEmpty() override;
	bool isFull() override;
	void enqueue(int item) override;
	int dequeue() override;
	void print() override;

private:
	Node* head_;
	Node* tail_;
};