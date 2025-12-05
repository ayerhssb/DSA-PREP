class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefixSum[i] = sum;
        }
        if (n == 1 || (sum % 2)) {
            return 0;
        }
        for (int i = 0; i < n - 1; i++) {

            if ((prefixSum[i] % 2 && (sum - prefixSum[i]) % 2 == 0) ||
                (!prefixSum[i] % 2 && (sum - prefixSum[i]) % 2)) {

                continue;
            } else {

                ans++;
            }
        }
        return ans;
    }
};
