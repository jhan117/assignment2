#include "test.h"
using namespace std::chrono;
using namespace std;

void runPrefixEvalTest(string& expr, bool useArray)
{
    cout << (useArray ? "[Array ���]" : "[LinkedList ���]") << " ���� ��� �׽�Ʈ\n";

    InterfaceQueue* tokens;
    InterfaceStack* operators;
    InterfaceStack* expressionOperands;
    InterfaceQueue* prefixQ;

    if (useArray) {
        tokens = new ArrayQueue(MAX_ARRAY);
        operators = new ArrayStack(MAX_ARRAY);
        expressionOperands = new ArrayStack(MAX_ARRAY);
        prefixQ = new ArrayQueue(MAX_ARRAY);
    }
    else {
        tokens = new LinkedListQueue();
        operators = new LinkedListStack();
        expressionOperands = new LinkedListStack();
        prefixQ = new LinkedListQueue();
    }

    int token_cnt = tokenize(expr, tokens);
    ExpressionTree tree(tokens, token_cnt, operators);

    tree.preorder(tree.getRoot(), prefixQ);

    auto start = steady_clock::now();
    int prefixResult = evaluatePrefix(prefixQ);
    auto end = steady_clock::now();

    cout << "���� ��� ���: " << prefixResult << endl;
    cout << "���� ��� �ð�: "
        << (end - start).count() << "ns" << endl;

    delete tokens;
    delete operators;
    delete expressionOperands;
    delete prefixQ;
}