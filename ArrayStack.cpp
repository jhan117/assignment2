#include <iostream>
#include "ArrayStack.h"
using namespace std;

// ������, �Ҹ���
ArrayStack::ArrayStack(int size) : top_(-1), stack_size_(size) {}
ArrayStack::~ArrayStack() { delete[] stack_; }

// ��� �޼ҵ�
bool ArrayStack::isEmpty() { return top_ == -1; }
bool ArrayStack::isFull() { return top_ == (stack_size_ - 1); }
void ArrayStack::push(int item)
{
	if (isFull())
	{
		cout << "���� �������� push �Ұ�... " << item << endl;
		return;
	}
	top_++;
	stack_[top_] = item;
}
int ArrayStack::pop()
{
	if (isEmpty())
	{
		cout << "���� ����־ pop �Ұ�..." << endl;
		return NULL;
	}
	top_--;
	return stack_[top_];
}
void ArrayStack::print()
{
	if (isEmpty())
	{
		cout << "������ �������" << endl;
		return;
	}

	for (int i = top_; i >= 0; --i)
	{
		cout << stack_[i] << " ";
	}

	cout << endl;
}