class Solution {
public:

    string expand(string &s, int l, int r) {

        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(string s) {

        string ans = "";

        for(int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            string temp1 = expand(s, i, i);

            // Even length palindrome
            string temp2 = expand(s, i, i + 1);

            if(temp1.size() > ans.size())
                ans = temp1;

            if(temp2.size() > ans.size())
                ans = temp2;
        }

        return ans;
    }
};