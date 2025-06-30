class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            if(l!=r){
                s[r]=' ';
                r++;
            }
            l=r;
            while(i<n && s[i]!=' '){
                s[r]=s[i];
                r++;
                i++;
            }
            reverse(s.begin()+l,s.begin()+r);
        }
        s.erase(r);
        return s;
    }
};