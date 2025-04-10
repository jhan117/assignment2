#pragma once
#include "InterfaceStack.h"
#include "Node.h"

class LinkedListStack : public InterfaceStack
{
public:
	LinkedListStack(int size);
	~LinkedListStack();

	bool isEmpty() override;
	bool isFull() override;
	void push(int item) override;
	int pop() override;
	void print() override;

private:
	Node* top_;
};