#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int reversed = 0;

        while (x != 0)
        {
            int digit = x % 10; // Extract the last digit
            x /= 10;            // Remove the last digit from x

            // Check for overflow/underflow before adding the digit
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7))
            {
                return 0; // Overflow
            }
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8))
            {
                return 0; // Underflow
            }

            reversed = reversed * 10 + digit;
        }

        return reversed;
    }
};