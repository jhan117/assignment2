#include "Expression/ExpressionEvaluator.h"
using namespace std;

int evaluatePostfix(InterfaceQueue* tokens, InterfaceStack* operands)
{
	while (!tokens->isEmpty())
	{
		string token = tokens->dequeue();

		if (isNumber(token))
		{
			operands->push(token);
		}
		else if (isOperator(token))
		{
			string right = operands->pop();
			string left = operands->pop();
			int result =  calculateExp(left, right, token);
			operands->push(to_string(result));
		}
	}
	return stoi(operands->pop());
}
int evaluatePrefix(InterfaceQueue* tokens)
{	
	while (true)
	{
		//cout << "prefix 시작: ";
		//tokens->print();

		string token = tokens->dequeue();
		//cout << "token: " << token << endl;
		if (tokens->isEmpty()) return stoi(token);

		if (isNumber(token))
		{
			tokens->enqueue(token);
		}
		else if (isOperator(token))
		{
			string op1 = tokens->peekFront();
			string op2 = tokens->peekSecond();

			if (isNumber(op1) && isNumber(op2))
			{
				string left = tokens->dequeue();
				string right = tokens->dequeue();
				int result = calculateExp(left, right, token);
				tokens->enqueue(to_string(result));
			}
			else
			{
				tokens->enqueue(token);
			}
		}

		//cout << "prefix 결과: ";
		//tokens->print();
	}
}

int calculateExp(string left, string right, string op)
{
	int leftVal = stoi(left);
	int rightVal = stoi(right);

	if (op == "+") return leftVal + rightVal;
	else if (op == "-") return leftVal - rightVal;
	else if (op == "*") return leftVal * rightVal;
	else if (op == "/") return leftVal / rightVal;

	return NULL;
}