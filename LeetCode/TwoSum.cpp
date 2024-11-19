//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rv{};
        for(size_t i=0;i<nums.size();i++){
            for(size_t j=0;j<nums.size();j++){
                if(i==j){
                    continue;
                }
                if(nums[i]+nums[j] == target){

                    auto checki = find(rv.begin(), rv.end(), i);
                    auto checkj = find(rv.begin(), rv.end(), j);

                    if (checki != rv.end()) {
                    //
                    }else {
                    rv.push_back(i);
                    }
                    if (checkj != rv.end()) {
                    //
                    }else {
                    rv.push_back(j);
                    }
                }
            }
        }
        return rv;
    }
};