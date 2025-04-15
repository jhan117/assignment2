#pragma once
#include "Interfaces/InterfaceStack.h"

class ArrayStack : public InterfaceStack
{
public:
	ArrayStack(int size);
	~ArrayStack();

	bool isEmpty() override;
	bool isFull() override;
	void push(std::string item) override;
	std::string pop() override;
	void print() override;
	std::string peek() override;

private:
	std::string* stack_;
	int top_;
	int stack_size_;
};