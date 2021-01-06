#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

std::string ShortestEquivalentPath(const std::string& path) {
    std::stringstream ss(path);
    std::string token;
    std::stack<std::string> path_names;
    
    while (std::getline(ss, token, '/')) {
        if (!path_names.empty() && token == "..") {
            path_names.pop();
        } else if (token != ".." && token != "." && token != "") {
            path_names.push(token);
        }
    }
    
    std::string res;
    while (!path_names.empty()) {
        res = '/' + path_names.top() + res;
        path_names.pop();
    }
    
    if (res.empty()) {
        return "/";
    } else {
        return res;
    }
}

int main() {

    return 0;
}