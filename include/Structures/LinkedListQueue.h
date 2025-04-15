#pragma once
#include "Interfaces/InterfaceQueue.h"
#include "Node.h"

class LinkedListQueue : public InterfaceQueue
{
public:
	LinkedListQueue();
	~LinkedListQueue();

	bool isEmpty() override;
	void enqueue(std::string item) override;
	std::string dequeue() override;
	void print() override;
	std::string peekFront() override;
	std::string peekSecond() override;

private:
	Node* front_;
	Node* rear_;
};