#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string& s) {
    int start = 0;
    int end = s.size() - 1;

    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }

    return true;
}

int main() {

    return 0;
}