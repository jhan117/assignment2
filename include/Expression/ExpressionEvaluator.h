#pragma once
#include "ExpressionTree.h"
#include <string>

// ������ ���
int evaluatePostfix(InterfaceQueue* tokens, InterfaceStack* operands);
// ������ ���
int evaluatePrefix(InterfaceQueue* tokens);
int calculateExp(std::string left, std::string right, std::string op);