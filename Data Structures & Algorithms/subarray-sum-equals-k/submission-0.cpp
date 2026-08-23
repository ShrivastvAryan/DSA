class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum = prefixSum + nums[i];

            int required = prefixSum - k;

            if (mp.count(required) > 0) {
                count = count + mp[required];
            }

            mp[prefixSum] = mp[prefixSum] + 1;
        }

        return count;
    }
};