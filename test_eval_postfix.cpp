#include "test.h"
using namespace std::chrono;
using namespace std;

void runPostfixEvalTest(string& expr, bool useArray)
{
    cout << (useArray ? "[Array ���]" : "[LinkedList ���]") << " ���� ��� �׽�Ʈ\n";

    InterfaceQueue* tokens;
    InterfaceStack* operators;
    InterfaceStack* expressionOperands;
    InterfaceQueue* postfixQ;

    if (useArray) {
        tokens = new ArrayQueue(MAX_ARRAY);
        operators = new ArrayStack(MAX_ARRAY);
        expressionOperands = new ArrayStack(MAX_ARRAY);
        postfixQ = new ArrayQueue(MAX_ARRAY);
    }
    else {
        tokens = new LinkedListQueue();
        operators = new LinkedListStack();
        expressionOperands = new LinkedListStack();
        postfixQ = new LinkedListQueue();
    }

    int token_cnt = tokenize(expr, tokens);
    ExpressionTree tree(tokens, token_cnt, operators);

    tree.postorder(tree.getRoot(), postfixQ);

    auto start = steady_clock::now();
    int postfixResult = evaluatePostfix(postfixQ, expressionOperands);
    auto end = steady_clock::now();

    cout << "���� ��� ���: " << postfixResult << endl;
    cout << "���� ��� �ð�: "
        << (end - start).count() << "ns" << endl;

    delete tokens;
    delete operators;
    delete expressionOperands;
    delete postfixQ;
}