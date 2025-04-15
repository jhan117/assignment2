#pragma once
#include "Expression/ExpressionParser.h"
#include "Structures/Stack.h"
#include "Structures/Queue.h"
#include "Expression/Expression.h"
#include<string>
#include <chrono>

#define MAX_ARRAY 100

void runPrefixEvalTest(std::string& expr, bool useArray);
void runPostfixEvalTest(std::string& expr, bool useArray);