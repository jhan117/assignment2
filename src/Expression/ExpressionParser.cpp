#include "Expression/ExpressionParser.h"
using namespace std;

int tokenize(const string expr, InterfaceQueue* tokens)
{
	int token_count = 0;
	string current_number;

	for (char ch : expr)
	{
		if (isdigit(ch))
		{
			current_number += ch;
		}
		else
		{
			if (!current_number.empty())
			{
				tokens->enqueue(current_number);
				token_count++;
				current_number = "";
			}
			if (isspace(ch)) continue;
			tokens->enqueue(string(1, ch));
			token_count++;
		}
	}

	if (!current_number.empty())
	{
		tokens->enqueue(current_number);
		token_count++;
	}

	return token_count;
}

int precedence(string op)
{
	if (op == "+" || op == "-") return 1;
	else if (op == "*" || op == "/") return 2;
	else return 0;
}
bool isOperator(string token)
{
	return (token == "+" || token == "-"
		|| token == "*" || token == "/");
}
bool isNumber(string token)
{
	int start = 0;

	if (token[0] == '-')
	{
		if (token.length() == 1) return false;
		start = 1;
	}

	for (int i = start; i < token.length(); ++i)
	{
		if (!isdigit(token[i])) return false;
	}
	return true;
}