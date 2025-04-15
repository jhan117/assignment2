#include "ArrayStack.h"
using namespace std;

// ������, �Ҹ���
ArrayStack::ArrayStack(int size) : top_(-1), stack_size_(size) { stack_ = new string[stack_size_]; }
ArrayStack::~ArrayStack() { delete[] stack_; }

// ��� �޼ҵ�
bool ArrayStack::isEmpty() { return top_ == -1; }
bool ArrayStack::isFull() { return top_ == (stack_size_ - 1); }
void ArrayStack::push(string item)
{
	if (isFull())
	{
		cout << "���� �������� push �Ұ�... " << item << endl;
		return;
	}
	top_++;
	stack_[top_] = item;
}
string ArrayStack::pop()
{
	if (isEmpty())
	{
		cout << "���� ����־ pop �Ұ�..." << endl;
		return "";
	}
	string item = stack_[top_];
	top_--;
	return item;
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
string ArrayStack::peek()
{
	if (isEmpty()) return "";
	return stack_[top_];
}