//To achieve this, you can perform the following operation any number of times:
Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = n-1 ; i>=0 ; i--){
         if(st.count(nums[i])){
            return ceil((i+1)/3.0);
         }
          st.insert(nums[i]);

        }
        return 0;
    }
};
