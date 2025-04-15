#pragma once
#include "Interfaces/InterfaceStack.h"
#include "Node.h"

class LinkedListStack : public InterfaceStack
{
public:
	LinkedListStack();
	~LinkedListStack();

	bool isEmpty() override;
	void push(std::string item) override;
	std::string pop() override;
	void print() override;
	std::string peek() override;

private:
	Node* top_;
};