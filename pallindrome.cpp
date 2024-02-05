#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;  // Negative numbers are not palindromes
        }
        
        int original = x;
        int rev = 0;
        while (x != 0) {
            int lastDigit = x % 10;

            // Check for overflow before updating rev
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && lastDigit > 7)) {
                return false;  // Overflow will occur
            }

            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && lastDigit < -8)) {
                return false;  // Overflow will occur
            }

            rev = rev * 10 + lastDigit;
            x = x / 10;
        }

        return rev == original;
    }
};