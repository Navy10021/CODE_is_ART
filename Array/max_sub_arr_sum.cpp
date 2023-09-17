#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubarraySum(arr);
    cout << result << endl; // Output will be 6
    return 0;
}
