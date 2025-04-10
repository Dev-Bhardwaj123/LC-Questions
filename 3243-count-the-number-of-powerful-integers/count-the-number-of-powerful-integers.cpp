class Solution {
public:

    long long dp(string& start, string& finish, int limit, string& s, int digit, int f, int st, vector<vector<vector<long long>>>& memo) {
        if (digit==0) {
            return 1;
        } 

        if (memo[digit][f][st]!=-1) {
            return memo[digit][f][st];
        }

        long long tot = 0;

        

        if (digit<=s.size()) {

            int question = s[s.size()-digit]-'0';

            int unable = 1;
            

            if (finish[finish.size()-digit]-'0'>question) {
                f = 1;
            } else if (finish[finish.size()-digit]-'0'<question&&f==0) {
                
                    unable = 0;
            }

            if ((digit<=start.size()&&start[start.size()-digit]-'0'<question)||digit>start.size()) {
                st = 1;
            }else if (digit<=start.size()&&start[start.size()-digit]-'0'>question&&st==0) {
                    unable = 0;
                }

            


            if (unable==1) {
                cout << "BRUH";
                tot+=dp(start,finish,limit,s,digit-1,f,st,memo);
            }
            
        } else {
            for (int i = 0;i<=limit;i++) {
                int temp = f;
                int temp2 = st;

                if ((finish[finish.size()-digit]-'0')>i) {
                    temp = 1;
                } else if (finish[finish.size()-digit]-'0'<i&&f==0) {
                    continue;
                }

                if ((digit<=start.size()&&(start[start.size()-digit]-'0'<i))||(digit>start.size()&&i!=0)) {
                    temp2 = 1;
                } else if (digit<=start.size()&&start[start.size()-digit]-'0'>i&&st==0) {
                    continue;
                }

                tot+=dp(start,finish,limit,s,digit-1,temp,temp2,memo);
            }
        }

        return memo[digit][f][st]=tot;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string first = to_string(start);
        string second = to_string(finish);


        vector<vector<vector<long long>>> memo(second.size()+1,vector<vector<long long>>(2,vector<long long>(2,-1)));


        return dp(first,second,limit,s,second.size(),0,0,memo);
    }
};