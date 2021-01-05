#include <iostream>
#include <stack>
#include <utility>

class MaxStack {
private:
	std::stack<std::pair<int, int>> cacheStack;

public:
	void Push(int x) {
		cacheStack.push({x, Empty() ? x : std::max(Max(), x)});
	}

	int Pop() {
		if (Empty()) {
			throw std::length_error("Pop(): empty stack");
			int top = cacheStack.top().first;
			cacheStack.pop();
			return top;
		}
	}

	bool Empty() const { return cacheStack.empty(); }

	int Max() const {
		if (Empty()) {
			throw std::length_error("Max(): empty stack");
		}

		return cacheStack.top().second;
	}
};

int main() {
	auto mx = MaxStack();
	mx.Push(141);
	mx.Push(51);
	mx.Push(4122);
	std::cout << mx.Max() << '\n';
	return 0;
}