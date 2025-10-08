76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(m < n) return "";

        unordered_map <char, int> mp;

        for(char &ch : t){
            mp[ch]++;
        }

        int requiredCount = n;
        int i = 0, j= 0;

        int windowSize = INT_MAX;
        int start = 0;

        while(j < m){
            char ch = s[j];
            if(mp[ch] > 0){
                requiredCount --;
            }
            mp[ch] --;

            while(requiredCount == 0){
                int current_window = j - i + 1;

                if(windowSize > current_window){
                    windowSize = current_window;
                    start = i;
                }
                mp[s[i]]++;

                if(mp[s[i]] > 0) requiredCount ++;

                i++;
            }
            j++;
        }

        return windowSize == INT_MAX ? "" : s.substr(start, windowSize);
    }
};