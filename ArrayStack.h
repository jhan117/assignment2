#pragma once
#include "InterfaceStack.h"

class ArrayStack : public InterfaceStack
{
public:
	ArrayStack(int size);
	~ArrayStack();

	bool isEmpty() override;
	bool isFull() override;
	void push(int item) override;
	int pop() override;
	void print() override;

private:
	int* stack_;
	int top_;
	int stack_size_;
};