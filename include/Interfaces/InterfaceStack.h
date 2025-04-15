#pragma once
#include <iostream>

class InterfaceStack
{
public:
	virtual ~InterfaceStack() {}

	virtual bool isEmpty() = 0;
	virtual bool isFull() { return false; }
	virtual void push(std::string item) = 0;
	virtual std::string pop() = 0;
	virtual void print() = 0;
	virtual std::string peek() = 0;
};