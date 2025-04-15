#pragma once
#include "ExpressionParser.h"
#include "Stack.h"
#include "Queue.h"
#include "Expression.h"
#include<string>
#include <chrono>

#define MAX_ARRAY 100

void runPrefixEvalTest(std::string& expr, bool useArray);
void runPostfixEvalTest(std::string& expr, bool useArray);