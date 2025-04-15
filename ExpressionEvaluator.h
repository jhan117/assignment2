#pragma once
#include "ExpressionTree.h"
#include <string>

// 후위식 계산
int evaluatePostfix(InterfaceQueue* tokens, InterfaceStack* operands);
// 전위식 계산
int evaluatePrefix(InterfaceQueue* tokens);
int calculateExp(std::string left, std::string right, std::string op);