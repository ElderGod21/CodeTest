#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
         stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();  // Remove duplicate
        } else {
            st.push(c);  // Add new character
        }
    }

    // Build the final string
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());  // Reverse to get correct order
    return result;
        
    }
};