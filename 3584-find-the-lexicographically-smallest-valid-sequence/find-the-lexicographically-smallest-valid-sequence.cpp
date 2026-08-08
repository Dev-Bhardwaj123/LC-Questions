class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int r=m-1,c=0;
        vector<int> right(n);
        for(int i=n-1;i>=0;i--){
            right[i]=c;
            if(r>=0 && word1[i]==word2[r]){
                r--;
                c++;
            }
        }
        vector<int> ans;
        bool changed=false;
        int j=0;
        for(int i=0;i<n && j<m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!changed && right[i]>=m-j-1){
                ans.push_back(i);
                j++;
                changed=true;
            }
        }
        if(j==m){
            return ans;
        }
        return {};
    }
};