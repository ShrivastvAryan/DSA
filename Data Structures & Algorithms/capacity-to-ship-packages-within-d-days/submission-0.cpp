class Solution {
public:

    bool canShip(vector<int>& weights, int days, int capacity) {

        int daysNeeded = 1;
        int currentWeight = 0;

        for (int i = 0; i < weights.size(); i++) {

            // If adding this package exceeds capacity,
            // ship the current packages and start a new day.
            if (currentWeight + weights[i] > capacity) {
                daysNeeded++;
                currentWeight = 0;
            }

            currentWeight = currentWeight + weights[i];
        }

        return daysNeeded <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;

        for (int i = 0; i < weights.size(); i++) {

            // Ship must at least carry the heaviest package.
            low = max(low, weights[i]);

            // Maximum possible capacity:
            // carry every package in one day.
            high = high + weights[i];
        }


        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                // mid works, but maybe a smaller capacity also works.
                high = mid - 1;
            }
            else {
                // mid is too small.
                low = mid + 1;
            }
        }

        return low;
    }
};
