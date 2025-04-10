#pragma once

class InterfaceQueue
{
public:
	virtual ~InterfaceQueue() {}

	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void enqueue(int item) = 0;
	virtual int dequeue() = 0;
	virtual void print() = 0;
};