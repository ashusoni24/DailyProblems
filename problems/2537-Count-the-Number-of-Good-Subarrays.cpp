Given an integer array nums and an integer k, return the number of good subarrays of nums.
A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
A subarray is a contiguous non-empty sequence of elements within an array.

Example 2:
Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.

Using the sliding window concept

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int,int> mp;
      int i = 0;
      int j = 0;
      long long result = 0;
      long long pairs = 0;
      while(j<n){
           pairs += mp[nums[j]];
           mp[nums[j]]++;
           while(pairs>=k){
            result += (n-j);
            mp[nums[i]]--;
            pairs -= mp[nums[i]];
            i++;
           }
           j++;
      }
      return result;
    }
};

