#include <iostream>
#include <string>
#include <stack>

int Eval(const std::string& RPN_Expression) {
    std::stack<int> intermediate;

    for (const auto c : RPN_Expression) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            int x = intermediate.top();
            intermediate.pop();

            int y = intermediate.top();
            intermediate.pop();

            switch (c)
            {
            case '+':
                intermediate.emplace(x + y);
                break;
            case '-':
                intermediate.emplace(x - y);
                break;
            case '/':
                intermediate.emplace(x / y);
                break;
            case '*':
                intermediate.emplace(x * y);
                break;
            }
        } else {
            intermediate.emplace(c - '0');
        }
    }

    return intermediate.top();
}

int main() {
    std::string exp = "34+2*1+";
    std::cout << Eval(exp) << '\n';

    return 0;
}