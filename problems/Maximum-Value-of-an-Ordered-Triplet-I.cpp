class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n,0);
        vector<int>rightmax(n,0);

        for(int j  = 1 ;j<n ;j++){
             leftmax[j] = max(leftmax[j-1] , nums[j-1]);
        }
        for(int j  = n-2 ;j>=0 ;j--){
              rightmax[j] = max(rightmax[j+1] , nums[j+1]);
        }
           
        long long result = 0;
        for(int i = 1 ;i<n-1 ;i++){
            result = max(result , (long long)(leftmax[i]- nums[i])*rightmax[i]);
            
        }
        return result;
    }
};
