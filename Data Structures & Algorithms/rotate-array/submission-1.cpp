class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        // Reverse entire array
        int left = 0;
        int right = n - 1;

        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        // Reverse first k elements
        left = 0;
        right = k - 1;

        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        // Reverse remaining elements
        left = k;
        right = n - 1;

        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};