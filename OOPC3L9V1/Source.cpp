#include "Array.h"
#include <iostream>
#include <stack>
#include <memory>

void outStack(std::stack<Array> st) {
	std::stack<Array> newStack = st; 
	while (!newStack.empty()) {
		std::cout << newStack.top() << std::endl; 
		newStack.pop(); 
	}
}

int main() {
	std::stack<Array> stackShared;
	std::stack<Array> stackSharedSecond;
	Array arr1(5);
	std::cin >> arr1;
	stackShared.push(arr1); 
	std::cout << arr1 << std::endl;

	Array arr2(3);
	std::cin >> arr2;
	stackShared.push(arr2);
	std::cout << arr2 << std::endl;

	Array arr3(2);
	std::cin >> arr3;
	stackSharedSecond.push(arr3);
	std::cout << arr3 << std::endl;

	Array arr4(3);
	std::cin >> arr4;
	stackShared.push(arr4);
	std::cout << arr4 << std::endl;

	std::cout << "All first stack:" << std::endl;
	outStack(stackShared);
	
	std::cout << "All second stack:" << std::endl;
	outStack(stackSharedSecond);
	
	Array arr5(4);
	std::cin >> arr5;
	std::cout << arr5;
	stackSharedSecond.emplace(arr5); 
	std::cout << "All new second stack:" << std::endl;
	outStack(stackSharedSecond);
	system("pause");

	while (!stackShared.empty()) { 
		stackSharedSecond.push(stackShared.top());
		stackShared.pop();
	}

	std::cout << "All first stack:" << std::endl;
	outStack(stackShared);

	std::cout << "All second stack:" << std::endl;
	outStack(stackSharedSecond);
	system("pause");

	Array arr6(3);
	std::cin >> arr6;
	std::cout << arr6 << std::endl;
	Array arr7(4);
	std::cin >> arr7;
	std::cout << arr7 << std::endl;

	stackSharedSecond.pop();
	stackSharedSecond.pop();

	stackSharedSecond.push(arr6);
	stackSharedSecond.push(arr7);
	std::cout << "All second stack:" << std::endl;
	outStack(stackSharedSecond);
	return 0;
}
