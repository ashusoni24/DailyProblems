You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
A subarray is a contiguous sequence of elements within an array.

Example 1:
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int cnt = 0, j = 0;
        for (int x : nums) {
            while (j < n && cnt < k) {
                cnt += nums[j++] == mx;
            }
            if (cnt < k) {
                break;
            }
            ans += n - j + 1;
            cnt -= x == mx;
        }
        return ans;
    }
};
