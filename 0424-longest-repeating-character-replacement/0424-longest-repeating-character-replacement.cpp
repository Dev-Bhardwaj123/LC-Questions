class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, n = s.size(), maxCount = 0, maxLen = 0;
        while (r < n) {
            mp[s[r]]++;
            maxCount = max(maxCount, mp[s[r]]);
            if ((r - l + 1) - maxCount > k) { 
                mp[s[l]]--;
                l++;
            } //since length of l-r substring has already been recorded, start moving l so that new substring can be considered.
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};