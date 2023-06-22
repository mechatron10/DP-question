 bool solver(int i,int current_sum,vector<int>&arr,int &sum,vector<vector<int>>&dp)
   {
       if(i==arr.size())
       {
           if(current_sum==sum)
           {
               return true;
           }
           return false;
       }
       if(current_sum==sum)
       {
           return true;
       }
       if(current_sum>sum)
       {
           return false;
       }
       if(dp[i][current_sum]!=-1)
       {
           return dp[i][current_sum];
       }
       bool ans=solver(i+1,current_sum+arr[i],arr,sum,dp)|solver(i+1,current_sum,arr,sum,dp);
       return dp[i][current_sum]=ans;
   }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solver(0,0,arr,sum,dp);
        
    
    }