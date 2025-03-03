class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)<pivot){
                v.push_back(nums.at(i));
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)==pivot){
                count++;
            }
        }
        for(int i=0;i<count;i++){
            v.push_back(pivot);
        }
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)>pivot){
                v.push_back(nums.at(i));
            }
        }
        
        return v;
    }
};