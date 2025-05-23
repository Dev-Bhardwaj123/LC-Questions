class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result;
        
        while (ss >> word) {
            if (!result.empty()) result = " " + result;
            result = word + result;
        }
        
        return result;
    }
};