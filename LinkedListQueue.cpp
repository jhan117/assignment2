#include "LinkedListQueue.h"
using namespace std;

LinkedListQueue::LinkedListQueue(): front_(nullptr), rear_(nullptr) {}
LinkedListQueue::~LinkedListQueue(){ while (!isEmpty()) dequeue();}

bool LinkedListQueue::isEmpty() { return front_ == nullptr; }
void LinkedListQueue::enqueue(string item)
{
	Node* new_node = new Node(item);

	if (isEmpty())
	{
		front_ = new_node;
		rear_ = new_node;
	}
	else
	{
		rear_->next_ = new_node;
		rear_ = new_node;
	}
	rear_->next_ = front_;
}
string LinkedListQueue::dequeue()
{
	if (isEmpty())
	{
		cout << "큐 비어있어서 dequeue 불가..." << endl;
		return "";
	}

	if (front_ == rear_)
	{
		string item = front_->data_;
		delete front_;
		front_ = rear_ = nullptr;
		return item;
	}
	else
	{
		Node* temp = front_;
		string item = front_->data_;
		front_ = front_->next_;
		rear_->next_ = front_;
		delete temp;
		return item;
	}
}
void LinkedListQueue::print()
{
	Node* current = front_;
	if (!isEmpty())
	{
		do
		{
			cout << current->data_ << " ";
			current = current->next_;
		} while (current != front_);
	}

	cout << endl;
}
string LinkedListQueue::peekFront()
{
	if (isEmpty()) return "";
	return front_->data_;
}
string LinkedListQueue::peekSecond()
{
	if (isEmpty() || front_->next_ == nullptr) return "";
	return front_->next_->data_;
}