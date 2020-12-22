#include <iostream>
#include <string>
#include <algorithm>

void ReverseWords(std::string* s) {
    std::reverse(s->begin(), s->end());
    
    std::size_t start = 0, end;
    while ((end = s->find(" ", start)) != std::string::npos) {
        std::reverse(s->begin() + start, s->begin() + end);
        start = end + 1;
    }
    std::reverse(s->begin() + start, s->end());
    
}

int main() {
    std::string s{"move more"};

    std::cout << "Original String: " << s << '\n';
    ReverseWords(&s);
    std::cout << "Reversed String: " << s << '\n';

    return 0;
}