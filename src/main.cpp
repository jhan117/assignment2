#include "test.h"
#include <iostream>
using namespace std;

#define EXPS 5

int main()
{
    string* expressions = new string[EXPS]{
        "2 + 3",
        "((8 + 2) * 3 - 4) / (5 + 6)",
        "( ( 8 + 2 ) * ( 3 - 1 ) + 4 / 2 ) * ( ( 7 + 3 ) - ( 6 / ( 2 + 1 ) ) ) + ( ( 5 + 9 ) * ( 3 + 2 ) ) - 10",
        "100 * (2 + 12) / 14 - (4 + 6) * 3",
        "((10 + 20) / 5) * (100 - 25) + (8 * 4)"
    };

    for (int i = 0; i < EXPS; i++)
    {
        string expr = expressions[i];
        cout << "중위 표현식: " << expr << endl << endl;

        runPrefixEvalTest(expr, true);
        cout << endl;
        runPrefixEvalTest(expr, false);
        cout << endl;
        runPostfixEvalTest(expr, true);
        cout << endl;
        runPostfixEvalTest(expr, false);
        cout << endl;

        cout << "==========" << endl << endl;
    }

    return 0;
}