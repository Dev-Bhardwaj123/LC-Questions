class Solution {
public:
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b; // beginWord
    int sz; // added
    void dfs(string word, vector<string>& seq){
        if(word == b){
            vector<string> temp = seq;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        int steps = mpp[word];
        for(int i = 0; i < sz; i++){
            char org = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        sz = beginWord.size();
        b = beginWord; // set the global b
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word == endWord) break;

            for(int i = 0; i < sz; i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = org;
            }
        }

        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
