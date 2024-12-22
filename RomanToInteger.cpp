#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        int size = s.length();
        char max = s[size - 1];
        int output = 0;
        map<char, int> rI = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        for (int i = size - 1; i >= 0; i--)
        {
            if (rI[s[i]] >= rI[max])
            {
                max = s[i];
                output += rI[s[i]];
                cout << "plus" << rI[s[i]] << endl;
            }
            else
            {
                output -= rI[s[i]];
                cout << rI[s[i]] << endl;
            }
        }
        return output;
    }
};