//2270. Number of Ways to Split Array

//note: time limit exceed for this solution, to be seems okay will fix
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int lsum=0;
        int rsum=0;
        int output=0;
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            lsum=0;
            rsum=0;
            for(int j=0;j<=i;j++){
                lsum += nums[j];
            }

            for(int k=i+1;k<=n-1;k++){
                rsum += nums[k];
            }
            if(lsum>=rsum)
                output++;
        }
        return output;
    }
};