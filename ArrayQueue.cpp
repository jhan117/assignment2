#include <iostream>
#include "ArrayQueue.h"
using namespace std;

// ������, �Ҹ���
ArrayQueue::ArrayQueue(int size): front_(-1), rear_(-1), queue_size_(size){}
ArrayQueue::~ArrayQueue() { delete[] queue_; }

// ��� �޼ҵ�
bool ArrayQueue::isEmpty() { return front_ == rear_; }
bool ArrayQueue::isFull() { return front_ == (rear_ + 1) % queue_size_; }
void ArrayQueue::enqueue(int item)
{
	if (isFull())
	{
		cout << "ť �������� enqueue �Ұ�... " << item << endl;
		return;
	}
	rear_ = (rear_ + 1) % queue_size_;
	queue_[rear_] = item;
}
int ArrayQueue::dequeue()
{
	if (isEmpty())
	{
		cout << "ť ����־ dequeue �Ұ�..." << endl;
		return NULL;
	}
	front_ = (front_ + 1) % queue_size_;
	return queue_[front_];
}
void ArrayQueue::print()
{
	if (isEmpty())
	{
		cout << "ť�� �������" << endl;
		return;
	}

	int idx = (front_ + 1) % queue_size_;

	while (true)
	{
		if (idx == rear_ + 1) break;
		cout << queue_[idx] << " ";
		idx = (idx + 1 % queue_size_);
	}
	cout << endl;
}