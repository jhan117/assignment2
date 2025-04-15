#pragma once
#include "InterfaceQueue.h"
#include "InterfaceStack.h"
#include "ExpressionParser.h"

class ExpressionTree
{
private:
	struct TreeNode
	{
		std::string data;
		TreeNode* left_child;
		TreeNode* right_child;

		// ������
		TreeNode(std::string d) : data(d), left_child(nullptr), right_child(nullptr){}
	};

public:
	ExpressionTree(InterfaceQueue* tokens, int tokens_count, InterfaceStack* operators);
	~ExpressionTree();

	void createOperatorNode(TreeNode** operands, InterfaceStack* operators, int& idx);
	TreeNode* getRoot();
	void deleteTree(TreeNode* node);

	// Ʈ�� ��ȸ �˰���
	void preorder(TreeNode* node, InterfaceQueue* output);
	void inorder(TreeNode* node, InterfaceQueue* output);
	void postorder(TreeNode* node, InterfaceQueue* output);

private:
	TreeNode* root_;
};