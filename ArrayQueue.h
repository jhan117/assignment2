#pragma once
#include "InterfaceQueue.h"

class ArrayQueue : public InterfaceQueue
{
public:
	ArrayQueue(int size);
	~ArrayQueue();

	bool isEmpty() override;
	bool isFull() override;
	void enqueue(int item) override;
	int dequeue() override;
	void print() override;

private:
	int* queue_;
	int front_, rear_;
	int queue_size_;
};