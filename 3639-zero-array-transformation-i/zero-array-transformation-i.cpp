#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l] -= 1;  
            if (r + 1 < n) {
                diff[r + 1] += 1;
            }
        }

        int curr_decrement = 0;
        for (int i = 0; i < n; i++) {
            curr_decrement += diff[i];
            nums[i] += curr_decrement; 
            if (nums[i] > 0) {  
                return false;
            }
        }

        return true;
    }
};
