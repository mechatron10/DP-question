class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    //first the sequence is increasing then it is decreasing we can apply the strictly increasing in the 
	    //forward and the reverse direction to get the answer
	   
	    int n=nums.size();
	    vector<int>forward(n,1);
	    vector<int>reverse(n,1);
	    for(int i=0;i<n;++i)
	    {
	        for(int j=i-1;j>=0;--j)
	        {
	            if(nums[i]>nums[j])
	            {
	                forward[i]=max(forward[i],1+forward[j]);
	            }
	        }
	    }
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=i+1;j<n;++j)
	        {
	            if(nums[i]>nums[j])
	            {
	                reverse[i]=max(reverse[j]+1,reverse[i]);
	            }
	        }
	    }
	    int ans=1;
	    for(int i=0;i<n;++i)
	    {
	        ans=max(ans,forward[i]+reverse[i]-1);
	    }
	    return ans;
	         
	}
};