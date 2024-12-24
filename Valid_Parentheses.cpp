#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    unordered_map<char, char> mappings = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char c : s) {
        // If it's a closing bracket
        if (mappings.find(c) != mappings.end()) {
            // Pop the top element from the stack if it's not empty, otherwise use a dummy value '#'
            char topElement = stack.empty() ? '#' : stack.top();
            stack.pop();

            // If the mapped opening bracket doesn't match the stack's top element, return false
            if (topElement != mappings[c]) {
                return false;
            }
        } else {
            // If it's an opening bracket, push onto the stack
            stack.push(c);
        }
    }

    // If the stack is empty, all brackets were matched; otherwise, return false
    return stack.empty();
}

int main() {
    string s;

    // Input examples
    s = "()";
    cout << (isValid(s) ? "true" : "false") << endl; // Output: true

    s = "()[]{}";
    cout << (isValid(s) ? "true" : "false") << endl; // Output: true

    s = "(]";
    cout << (isValid(s) ? "true" : "false") << endl; // Output: false

    s = "([])";
    cout << (isValid(s) ? "true" : "false") << endl; // Output: true

    return 0;
}