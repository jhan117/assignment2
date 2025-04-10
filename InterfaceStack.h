#pragma once

class InterfaceStack
{
public:
	virtual ~InterfaceStack() {}

	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual void push(int item) = 0;
	virtual int pop() = 0;
	virtual void print() = 0;
};