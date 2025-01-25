class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        map<int, queue<int>> levels; 
        unordered_map<int, int> levelMap; 
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());

        int currentLevel = 0;
        levels[currentLevel].push(sortedNums[0]);
        levelMap[sortedNums[0]] = currentLevel;

        for (int i = 1; i < sortedNums.size(); i++) {
            if (sortedNums[i] - levels[currentLevel].back() <= limit) {
                levels[currentLevel].push(sortedNums[i]);
            } else {
                currentLevel++;
                levels[currentLevel].push(sortedNums[i]);
            }
            levelMap[sortedNums[i]] = currentLevel;
        }
        for (int i = 0; i < nums.size(); i++) {
            int elementLevel = levelMap[nums[i]]; 
            nums[i] = levels[elementLevel].front(); 
            levels[elementLevel].pop(); 
        }

        return nums;
    }
};