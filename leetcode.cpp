#include <vector>


class Solution {
public:
    // target = 7, nums = [2,3,1,2,4,3]
    // res = 2
    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        const int nlen = nums.size(); // 6
        int left = 0, right = 0; // left inclusive, right exclusive // 2, 5
        int curr_sum = 0; // 7
        int result = 0; // 3
        do {
            do {
                curr_sum += nums[right++];
            } while (right < nlen && curr_sum < target);
            if (curr_sum < target)
            {
                break;
            }
            do {
                result = result == 0 ? right - left : std::min(right - left, result);
                curr_sum -= nums[left++];
            } while(curr_sum >= target && left < right);
        } while (right < nlen);
        return result;
    }
};
