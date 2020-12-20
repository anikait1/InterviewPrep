#include <iostream>
#include <string>
#include <vector>

int StringToInt(const std::string& s) {
    int result = 0;
    for (int i = s[0] == '-' ? 1 : 0; i < s.size(); ++i) {
        const int digit = s[i] - '0';
        result = result * 10 + digit;
    }

    return s[0] == '-' ? -result : result;
}

std::string IntToString(int x) {
    bool is_negative = x < 0 ? true : false;
    std::string s;

    do {
        s += '0' + std::abs(x % 10);
        x /= 10;
    } while (x);

    if (is_negative) {
        s += '-';
    }

    return { s.rbegin(), s.rend() };
}

int main() {

    return 0;
}