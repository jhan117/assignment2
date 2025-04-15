#include "ArrayQueue.h"
using namespace std;

// ������, �Ҹ���
ArrayQueue::ArrayQueue(int size) : front_(-1), rear_(-1), queue_size_(size) { queue_ = new string[queue_size_]; }
ArrayQueue::~ArrayQueue() { delete[] queue_; }

// ��� �޼ҵ�
bool ArrayQueue::isEmpty() { return front_ == rear_; }
bool ArrayQueue::isFull() { return front_ == (rear_ + 1) % queue_size_; }
void ArrayQueue::enqueue(string item)
{
	if (isFull())
	{
		cout << "ť �������� enqueue �Ұ�... " << item << endl;
		return;
	}
	rear_ = (rear_ + 1) % queue_size_;
	queue_[rear_] = item;
}
string ArrayQueue::dequeue()
{
	if (isEmpty())
	{
		cout << "ť ����־ dequeue �Ұ�..." << endl;
		return "";
	}
	front_ = (front_ + 1) % queue_size_;
	string item = queue_[front_];
	return item;
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
string ArrayQueue::peekFront()
{
	if (isEmpty()) return "";
	return queue_[(front_ + 1) % queue_size_];
}
string ArrayQueue::peekSecond()
{
	int first = (front_ + 1) % queue_size_;
	int secondIdx = (first + 1) % queue_size_;
	if (isEmpty() || first == rear_) return "";
	return queue_[secondIdx];
}