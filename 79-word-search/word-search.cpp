class Solution {
public:
    bool isValid(int ind,int i,int j,vector<vector<char>>& board,string word){
        //base case if ind reaches end
        if(ind==word.length()){
            return true;
        }
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[ind]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        bool res=isValid(ind+1,i+1,j,board,word) || 
                 isValid(ind+1,i,j+1,board,word) ||
                 isValid(ind+1,i-1,j,board,word) ||
                 isValid(ind+1,i,j-1,board,word);
        board[i][j]=temp;
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(isValid(0,i,j,board,word)) return true;
            }
        }
        return false;
    }
};