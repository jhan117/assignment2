#include <iostream>
#include "ArrayQueue.h"
using namespace std;

// 생성자, 소멸자
ArrayQueue::ArrayQueue(int size): front_(-1), rear_(-1), queue_size_(size){}
ArrayQueue::~ArrayQueue() { delete[] queue_; }

// 멤버 메소드
bool ArrayQueue::isEmpty() { return front_ == rear_; }
bool ArrayQueue::isFull() { return front_ == (rear_ + 1) % queue_size_; }
void ArrayQueue::enqueue(int item)
{
	if (isFull())
	{
		cout << "큐 가득차서 enqueue 불가... " << item << endl;
		return;
	}
	rear_ = (rear_ + 1) % queue_size_;
	queue_[rear_] = item;
}
int ArrayQueue::dequeue()
{
	if (isEmpty())
	{
		cout << "큐 비어있어서 dequeue 불가..." << endl;
		return NULL;
	}
	front_ = (front_ + 1) % queue_size_;
	return queue_[front_];
}
void ArrayQueue::print()
{
	if (isEmpty())
	{
		cout << "큐가 비어있음" << endl;
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