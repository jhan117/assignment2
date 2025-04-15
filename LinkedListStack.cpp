#include "LinkedListStack.h"
using namespace std;

// 생성자, 소멸자
LinkedListStack::LinkedListStack() : top_{nullptr} {}
LinkedListStack::~LinkedListStack(){ while (!isEmpty()) pop(); }

// 멤버 메소드
bool LinkedListStack::isEmpty(){ return top_ == nullptr; }
void LinkedListStack::push(string item)
{
	Node* new_node = new Node(item, top_);
	top_ = new_node;
}
string LinkedListStack::pop()
{
	if (isEmpty())
	{
		cout << "스택 비어있어서 pop 불가..." << endl;
		return "";
	}
	
	Node* temp = top_;
	string item = top_->data_;
	top_ = top_->next_;
	delete temp;

	return item;
}
void LinkedListStack::print()
{
	Node* current = top_;
		
	while (current != nullptr)
	{
		cout << current->data_ << " ";
		current = current->next_;
	}

	cout << endl;
}
string LinkedListStack::peek()
{
	if (isEmpty()) return "";
	return top_->data_;
}