class Solution {
public:
    vector<string> convert(string sentence){
        sentence += " ";
        vector<string> ans;

        string word = "";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                ans.push_back(word);
                word="";
            }
            else{
                word += sentence[i];
            }
        }

        return ans;
    }
    bool areSentencesSimilar(string x, string y) {
         if (x.length() < y.length()) {
            swap(x, y);
        }
        vector<string> vx, vy;
        vx = convert(x);
        vy = convert(y);

        int l = 0;
        for(int i = 0; i < vy.size(); i++) {
            if(vx[i] == vy[i]) {
                l++;
            }
            else {
                break;
            }
        }

        int ind = vx.size() - 1, r=vy.size();
        for(int i=vy.size()-1; i>=0; i--){
            if(vy[i] == vx[ind]){
                ind--;
                r=i;
            }
            else{
                break;
            }
        }
        return r <= l;
    }
};