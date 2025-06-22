class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> even, odd;
        int evencnt = 0, oddcnt = 0, swapsone = 0, swapstwo = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                evencnt++;
                even.push_back(i);
            } else {
                oddcnt++;
                odd.push_back(i);
            }
        }
        if (abs(evencnt - oddcnt) > 1) {
            return -1;
        }
        int curr = 0, target = 0;
        // even-odd-even-odd
        if (evencnt >= oddcnt) {
            while (curr < even.size() && target < odd.size()) {
                if (even[curr] % 2 == 0) {
                    curr++;
                    continue;
                }
                while (odd[target] % 2 != 0) {
                    target++;
                }
                swapsone += abs(odd[target] - even[curr]);
                curr++;
                target++;
            }
        }
        curr = 0;
        target = 0;
        // odd-even-odd-even
        if (oddcnt >= evencnt) {
            while (target < even.size() && curr < odd.size()) {
                if (odd[curr] % 2 == 0) {
                    curr++;
                    continue;
                }
                while (even[target] % 2 != 0) {
                    target++;
                }
                swapstwo += abs(even[target] - odd[curr]);
                curr++;
                target++;
            }
        }
        if(evencnt>oddcnt){return swapsone;}
        else if(evencnt<oddcnt){return swapstwo;}

        return min(swapsone, swapstwo);
    }
};
