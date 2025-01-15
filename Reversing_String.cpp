#include <iostream> 
#include <vector>
using namespace std;
class Solution {
public:

    void reverseString(vector<char>& s) {
        int n = s.size();
        int start = 0;
        int e = n-1;
        while(start<e){
            swap(s[start++],s[e--]);
        }
        
    }
};