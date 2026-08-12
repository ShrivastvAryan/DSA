class Solution {
public:

    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        // Check right child
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        // If parent is not largest
        if (largest != i) {
            int temp = nums[i];
            nums[i] = nums[largest];
            nums[largest] = temp;

            heapify(nums, n, largest);
        }
    }


    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Step 2: Move largest element to the end
        for (int i = n - 1; i > 0; i--) {

            // Swap first and last
            int temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;

            // Fix the remaining heap
            heapify(nums, i, 0);
        }

        return nums;
    }
};