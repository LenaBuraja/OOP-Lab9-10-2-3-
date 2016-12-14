#include "Array.h"
#include <iostream>
#include <stack>
#include <memory>

void outStack(std::stack<std::shared_ptr<Array>> st) {
	std::stack<std::shared_ptr<Array>> newStack = st;
	while (!newStack.empty()) {
		std::cout << *newStack.top() << std::endl;
		newStack.pop();
	}
}

int main() {
	std::stack<std::shared_ptr<Array>> stackShared;
	Array arr1(5);
	std::cin >> arr1;
	stackShared.push(std::shared_ptr<Array>(&arr1));
	std::cout << arr1 << std::endl;

	Array arr2(3);
	std::cin >> arr2;
	stackShared.push(std::shared_ptr<Array>(&arr2));
	std::cout << arr2 << std::endl;

	Array arr3(2);
	std::cin >> arr3;
	stackShared.push(std::shared_ptr<Array>(&arr3));
	std::cout << arr3 << std::endl;

	Array arr4(3);
	std::cin >> arr4;
	stackShared.push(std::shared_ptr<Array>(&arr4));
	std::cout << arr4 << std::endl;

	std::cout << "All first stack:" << std::endl;
	outStack(stackShared);

	return 0;
}
