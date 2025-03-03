class Solution {
public:
    void solve(int i,string sumPath,long sum,long prev,string num,int target,vector<string>& res){
        if(i==num.size()){
            if(sum==target){
                res.push_back(sumPath);
            }
            return;
        }
        for(int j=i;j<num.size();j++){
            if(j>i && num[i]=='0'){
                break;
            }
            long nums=stol(num.substr(i,j-i+1));
            string tempPath=num.substr(i,j-i+1);
            if(i==0){
                solve(j+1,tempPath,nums,nums,num,target,res);
            }
            else{
                solve(j+1,sumPath+ '+'+tempPath,sum+nums,nums,num,target,res);
                solve(j+1,sumPath+'-'+tempPath,sum-nums,-nums,num,target,res);
                solve(j+1,sumPath+'*'+tempPath,sum-prev+(prev*nums),prev*nums,num,target,res);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        solve(0,"",0,0,num,target,res);
        return res;
    }
};