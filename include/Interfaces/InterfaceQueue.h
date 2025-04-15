#pragma once
#include <iostream>

class InterfaceQueue
{
public:
	virtual ~InterfaceQueue() {}

	virtual bool isEmpty() = 0;
	virtual bool isFull() { return false; }
	virtual void enqueue(std::string item) = 0;
	virtual std::string dequeue() = 0;
	virtual void print() = 0;
	virtual std::string peekFront() = 0;
	virtual std::string peekSecond() = 0;
};