#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool IsPalindrome(const std::string& s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
        while (!std::isalnum(s[i]) && i < j) {
            i++;
        }

        while (!std::isalnum(s[j]) && i < j) {
            j--;
        }

        if (std::tolower(s[i++]) != std::tolower(s[j--])) {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::vector<std::string> strings{"Ray a ray", "A man, a plan, a canal, Panama"};

    std::for_each(std::begin(strings), std::end(strings), [](const std::string& s) {
        std::cout << IsPalindrome(s) << '\n';
    });

    return 0;
}