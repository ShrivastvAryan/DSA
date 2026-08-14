class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        // Store product of all elements to the LEFT
        int prefix = 1;

        for(int i = 0; i < n; i++) {
            output[i] = prefix;
            prefix *= nums[i];
        }

        // Multiply by product of all elements to the RIGHT
        int suffix = 1;

        for(int i = n - 1; i >= 0; i--) {
            output[i] *= suffix;
            suffix *= nums[i];
        }

        return output;
    }
};