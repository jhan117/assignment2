#include "ArrayStack.h"
using namespace std;

// 생성자, 소멸자
ArrayStack::ArrayStack(int size) : top_(-1), stack_size_(size) { stack_ = new string[stack_size_]; }
ArrayStack::~ArrayStack() { delete[] stack_; }

// 멤버 메소드
bool ArrayStack::isEmpty() { return top_ == -1; }
bool ArrayStack::isFull() { return top_ == (stack_size_ - 1); }
void ArrayStack::push(string item)
{
	if (isFull())
	{
		cout << "스택 가득차서 push 불가... " << item << endl;
		return;
	}
	top_++;
	stack_[top_] = item;
}
string ArrayStack::pop()
{
	if (isEmpty())
	{
		cout << "스택 비어있어서 pop 불가..." << endl;
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
		cout << "스택이 비어있음" << endl;
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