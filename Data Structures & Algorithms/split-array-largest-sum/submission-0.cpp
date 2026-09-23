class Solution {
public:

    bool canSplit(vector<int>& nums, int k, long long maxAllowedSum) {

        int subarrays = 1;
        long long currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (currentSum + nums[i] <= maxAllowedSum) {

                currentSum = currentSum + nums[i];

            } else {

                subarrays = subarrays + 1;
                currentSum = nums[i];

                if (subarrays > k) {
                    return false;
                }
            }
        }

        return true;
    }


    int splitArray(vector<int>& nums, int k) {

        long long low = 0;
        long long high = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > low) {
                low = nums[i];
            }

            high = high + nums[i];
        }


        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {

                // mid works.
                // Try to find a smaller maximum sum.
                high = mid;

            } else {

                // mid is too small.
                // We need to allow a larger sum.
                low = mid + 1;
            }
        }

        return low;
    }
};