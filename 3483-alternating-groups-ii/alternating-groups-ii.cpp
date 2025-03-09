class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        if (k>n) return 0;

        int ans=0;
        int validCount=0;
        for(int i=1;i<k;i++) {
            if (colors[i]!=colors[i-1]) validCount++;
        }
        if (validCount==k-1) ans++;
        for (int i=1;i<n;i++) {
            if (colors[i] != colors[i - 1]) validCount--;
            if (colors[(i+k-1)%n] != colors[(i+k-2)%n]) validCount++;
            if (validCount == k - 1) ans++;
        }
        return ans;
    }
};