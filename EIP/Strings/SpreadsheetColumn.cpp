#include <iostream>
#include <string>
#include <vector>

int SSDecodeColID(const std::string& col) {
    int result = 0;

    for (char c : col) {
        result = result * 26 + (c - 'A' + 1);
    }

    return result;
}

int main() {
    auto res = SSDecodeColID("ZZ");
    std::cout << res << '\n';


    return 0;
}