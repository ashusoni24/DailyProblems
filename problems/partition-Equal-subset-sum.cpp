//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

class Solution {
public:
    vector<vector<int>> dp;
     bool solve(vector<int>& nums ,int i , int x){
        if(x==0){
            return true;
        }
        if(i>=nums.size()){
            return false;
        }
        if (dp[i][x] != -1) return dp[i][x];
        bool take = false;
        if(nums[i]<=x){
            take = solve(nums , i+1 , x-nums[i]);
        }
        bool nottake = solve(nums , i+1 ,  x);
         return dp[i][x] = take || nottake;
     }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int S = accumulate(begin(nums), end(nums), 0);
        if(S%2!=0){
            return false;
        }
         dp = vector<vector<int>>(n, vector<int>(x + 1, -1));
        int x = S/2;
        return solve(nums,0 , x);
    }
};
