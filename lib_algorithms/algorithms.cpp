#include <string>
#include "stack.h"
#include "queue.h"

bool check_breckets(std::string str) {

	int size = str.length();
	Stack<char> stack(size);

	for (int i = 0; i < size; i++) {
		if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{')) {
			stack.push(str[i]);
		}

		else if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}')) {
			if (stack.is_empty()) {
				return false;
			}

			char top = stack.top();


			if ((str[i] == ')' && top == '(') || (str[i] == ']' && top == '[') || (str[i] == '}' && top == '{')) {
				stack.pop();
			}
			else {
				return false;
			}
		}
	}
	return stack.is_empty();
}