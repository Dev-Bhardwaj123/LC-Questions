class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int freq = 1;

        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1]) {
                freq++;
                if (freq == 9) {
                    comp += "9";
                    comp += word[i - 1];
                    freq = 0;
                }
            } else {
                if (freq > 0) {
                    comp += to_string(freq);
                    comp += word[i - 1];
                }
                freq = 1; 
            }
        }
        if (freq > 0) {
            comp += to_string(freq);
            comp += word.back();
        }

        return comp;
    }
};
