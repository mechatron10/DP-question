class Solution {
  public:
    int mod=1e9+7; 
    int solver(int i,int target,vector<int>&arr,vector<vector<int>>&dp)
    {
        // cout<<"i="<<i<<" target="<<target<<endl;
        if(i==0)
        {
            // cout<<"target="<<target<<endl;
            if(target==0&&arr[0]==0)//if we have a zero allowed then we will return the answer 2 
            {
                return 2;
            }
            
            if(target==arr[0]||target==0)
            {
                return 1;
            }
            return 0;
        }
        if(target<0)
        {
            return 0;
        }
        if(dp[i][target]!=-1)
        {
            return dp[i][target]%mod;
        }
        
        int temp1;
        temp1=solver(i-1,target,arr,dp);
        int temp2=0;
        if(target>=arr[i])
        {
          temp2=solver(i-1,target-arr[i],arr,dp)%mod; 
        }
        return dp[i][target]=(temp1+temp2)%mod;
        
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        //we just have to find the subsets that have a sum of total_sum-d/2;we can derive this 
        //hence our question becomes same as the  question to find the sum with given target
       //The case of the zeros must be handled correctly only for the last element as the 0 that are present in between for those we have 
       //already considered the subsets with take or not take concept
        int total=accumulate(arr.begin(),arr.end(),0);
        if((total+d)/2>total||(total+d)%2!=0)
        {
            return 0;
        }
       
        int target=(total+d)/2;
         vector<vector<int>>dp(n,vector<int>(target+1,-1));
      //  cout<<"target="<<target<<endl;
        return solver(n-1,target,arr,dp);
    }
};