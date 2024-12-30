class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) {
            return 1;
        } else if (n < 0) {
            return 0;

        } else if (n == 0) {
            return 0;

        }

        else {
            while (n > 1) {
                int digit = n % 2;
                n = n / 2;
                if (digit != 0) {
                    return 0;
                } else {
                    continue;
                }
            }
            return 1;
        }
    }
};