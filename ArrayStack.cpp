#include <iostream>
#include "ArrayStack.h"
using namespace std;

// 생성자, 소멸자
ArrayStack::ArrayStack(int size) : top_(-1), stack_size_(size) {}
ArrayStack::~ArrayStack() { delete[] stack_; }

// 멤버 메소드
bool ArrayStack::isEmpty() { return top_ == -1; }
bool ArrayStack::isFull() { return top_ == (stack_size_ - 1); }
void ArrayStack::push(int item)
{
	if (isFull())
	{
		cout << "스택 가득차서 push 불가... " << item << endl;
		return;
	}
	top_++;
	stack_[top_] = item;
}
int ArrayStack::pop()
{
	if (isEmpty())
	{
		cout << "스택 비어있어서 pop 불가..." << endl;
		return NULL;
	}
	top_--;
	return stack_[top_];
}
void ArrayStack::print()
{
	if (isEmpty())
	{
		cout << "스택이 비어있음" << endl;
		return;
	}

	for (int i = top_; i >= 0; --i)
	{
		cout << stack_[i] << " ";
	}

	cout << endl;
}