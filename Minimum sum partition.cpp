int sum;
    int solver(int i,int total,int *arr,int &n,vector<vector<int>>&dp)
    {
        if(i==n)//we are just computing the sum of the elements of the first set and using the accumulate or
        //the total value to get the sum of the second set automatically this is the first approach
        {
            int set1=sum-total;//the sum of the elements of the set1 
            int set2=total;//the sum of the value of the elements of the set
            return abs(set1-set2);//no more value can be addded 
        }
        if(dp[i][total]!=-1)
        {
            return dp[i][total];
        }
        //we can store the minimum absolute difference that is found by considering or not considering the 
        //element at the position i
       //afterwards we can convert it into the bottom up approach
       int ans=INT_MAX;
        ans=min(solver(i+1,total-arr[i],arr,n,dp),solver(i+1,total,arr,n,dp));
        //save every answer in the dp may be this is what we 
       //have to do

      return dp[i][total]=ans;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    //use the approach of the take or not take in the subsequence problems 
	    //The absoulte difference between the sum of the two sets is minimum 
	    //we can use the map to store the result at any point 
	    //if we take or if we not take the sum of first set can be determined we just have to find the 
	    int total=0;
	   
	    for(int i=0;i<n;++i)
	    {
	     total+=arr[i];   
	    }
	     vector<vector<int>>dp(n,vector<int>(total+1,-1));
	    sum=total;
	    return solver(0,total,arr,n,dp);
	} 
};