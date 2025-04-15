#include "Expression/ExpressionTree.h"
using namespace std;

// »ı¼ºÀÚ, ¼Ò¸êÀÚ
ExpressionTree::ExpressionTree(InterfaceQueue* tokens, int tokens_count, InterfaceStack* operators)
{
	TreeNode** operands = new TreeNode*[tokens_count];
	int idx = 0;

	while (!tokens->isEmpty())
	{
		string token = tokens->dequeue();

		if (isNumber(token))
		{
			TreeNode* new_node = new TreeNode(token);
			operands[idx++] = new_node;
		}
		else if (token == "(")
		{
			operators->push(token);
		}
		else if (token == ")")
		{
			while (!operators->isEmpty() && operators->peek() != "(")
			{
				createOperatorNode(operands, operators, idx);
			}
			operators->pop();
		}
		else if (isOperator(token))
		{
			while(!operators->isEmpty() && precedence(operators->peek()) >= precedence(token))
			{
				createOperatorNode(operands, operators, idx);
			}
			operators->push(token);
		}
	}

	while (!operators->isEmpty())
	{
		createOperatorNode(operands, operators, idx);
	}
	root_ = operands[0];

	delete []operands;
}
ExpressionTree::~ExpressionTree() { deleteTree(root_); }

// ¸â¹ö ¸Ş¼Òµå
void ExpressionTree::createOperatorNode(TreeNode** operands, InterfaceStack* operators, int& idx)
{
	string op = operators->pop();
	TreeNode* right = operands[--idx];
	TreeNode* left = operands[--idx];

	TreeNode* node = new TreeNode(op);
	node->left_child = left;
	node->right_child = right;

	operands[idx++] = node;
}
ExpressionTree::TreeNode* ExpressionTree::getRoot()
{
	return root_;
}
void ExpressionTree::deleteTree(TreeNode* node)
{
	if (node == nullptr) return;

	deleteTree(node->left_child);
	deleteTree(node->right_child);

	delete node;
}

void ExpressionTree::preorder(TreeNode* node, InterfaceQueue* output)
{
	if (node == nullptr) return;

	output->enqueue(node->data);
	preorder(node->left_child, output);
	preorder(node->right_child, output);
}
void ExpressionTree::inorder(TreeNode* node, InterfaceQueue* output)
{
	if (node == nullptr) return;

	inorder(node->left_child, output);
	output->enqueue(node->data);
	inorder(node->right_child, output);
}
void ExpressionTree::postorder(TreeNode* node, InterfaceQueue* output)
{
	if (node == nullptr) return;

	postorder(node->left_child, output);
	postorder(node->right_child, output);
	output->enqueue(node->data);
}