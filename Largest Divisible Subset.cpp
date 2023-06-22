class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& nums) {
        // Code here
        //problem will be solved like the longest increasing subsequence 
        //subsets does not mean that we have to find the subsequence only we can rearrange the numbers
        //sort them and do whatever we want with them 
        //we will need to keep the dp as it contains the longest subset found so far till the ith index
        sort(nums.begin(),nums.end());//the sorted array helps to get the  answer as before all the current 
       //all the smaller will divide the current as well as all the 
        vector<int>dp(n,1);
        vector<int>hash(n);
       
        int length=1;
        int last=0;
        for(int i=0;i<n;++i)//hash will tell the occurence of the previous element 
        {
            hash[i]=i;
        }
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
            }
            if(dp[i]>length)
            {
                length=dp[i];
                last=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[last]);
        while(hash[last]!=last)
        {
            last=hash[last];
            ans.push_back(nums[last]);
            
        }
        
       return ans;
        
        
    }
};