class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> sortednums = nums;
        sort(sortednums.begin(), sortednums.end());

        int current = 1;
        int longest = 1;

        for (int i = 0; i < sortednums.size() - 1; i++) {

            if (sortednums[i + 1] == sortednums[i] + 1) {
                current++;
            }
            else if (sortednums[i + 1] != sortednums[i]) {
                current = 1;
            }

            longest = max(longest, current);
        }

        return longest;
    }
};