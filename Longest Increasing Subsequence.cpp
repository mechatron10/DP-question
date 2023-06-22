class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //Read the previous accepted soltion for better understanding it
        //contains the detailed explaination
     vector<int>ans;
      for(int i=0;i<nums.size();++i)
      {
         if(ans.empty()||ans[ans.size()-1]<nums[i])
         {
             ans.push_back(nums[i]);
         }
         else
         {
            auto it=lower_bound(ans.begin(),ans.end(),nums[i]);//points to first index that is greater than or equal to the nums[i] this is done because of the greedy solution 
            *it=nums[i];//replace the element pointed by the nums[i]as we are making the best possible increasing subsequence keeping the end as small as possible
         }
      }   
      return ans.size();
    }
};