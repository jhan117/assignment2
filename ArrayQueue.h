#pragma once
#include "InterfaceQueue.h"

class ArrayQueue : public InterfaceQueue
{
public:
	ArrayQueue(int size);
	~ArrayQueue();

	bool isEmpty() override;
	bool isFull() override;
	void enqueue(std::string item) override;
	std::string dequeue() override;
	void print() override;
	std::string peekFront() override;
	std::string peekSecond() override;

private:
	std::string* queue_;
	int front_, rear_;
	int queue_size_;
};