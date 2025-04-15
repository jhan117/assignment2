#pragma once

struct Node
{
	std::string data_;
	Node* next_;

	// »ý¼ºÀÚ
	Node(std::string data, Node* next = nullptr) : data_(data), next_(next) {}
};