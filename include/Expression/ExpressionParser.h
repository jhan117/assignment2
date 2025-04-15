#pragma once
#include <iostream>
#include "Interfaces/InterfaceQueue.h"
#include "Interfaces/InterfaceStack.h"

int tokenize(const std::string expr, InterfaceQueue* tokens);
int precedence(std::string op);
bool isOperator(std::string token);
bool isNumber(std::string token);