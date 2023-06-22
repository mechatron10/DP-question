class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        vector<int>ans;
        //fnding the index of the longest increasing subsequence 
         //also replace the equal length if that equal length has occured before the last index
         vector<int>hash(n);
         for(int i=0;i<n;++i)
         {
             hash[i]=i;
         }
         int last=0;
         vector<int>dp(n,1);//will store the max length subsequence ending at index i 
         int found=1;
         for(int i=0;i<n;++i)
          {
             for(int j=i-1;j>=0;--j)
             {
                 if(nums[i]>nums[j]&&dp[i]<=dp[j]+1)
                 {
                     
                     if(dp[i]==dp[j]+1&&nums[hash[i]]>nums[j])
                     {
                         hash[i]=j;
                     }
                     else
                     {
                         dp[i]=dp[j]+1;
                         hash[i]=j;
                     }
                 }
             }
             if(found<dp[i])
             {
                 last=i;
                 found=dp[i];
             }
          }
          ans.push_back(nums[last]);
          while(hash[last]!=last)
          { 
                last=hash[last];
                ans.push_back(nums[last]);
          }
          reverse(ans.begin(),ans.end());
          return ans;
        }
       
    
};