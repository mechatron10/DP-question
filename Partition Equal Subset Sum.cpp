class Solution{
public:
    // bool solver(int i,int sum,int *arr,int &n)
    // {
    //     if(i==n-1)
    //     {
    //         return (arr[i]==sum);//is the last element is equal to the given sum then we can surely say 
    //         //we have a sum of 0
    //     }
    //     if(sum==0)//this can be possible for all the elements
    //     {
    //         return true;
    //     }
    //     bool ans=solver(i+1,sum,arr,n);
    //     if(arr[i]<=sum)
    //     {
    //         ans=ans|solver(i+1,sum-arr[i],arr,n);
    //     }
    //     return ans;
    // }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        int target=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        //i must decrease and the j must increase
        //The base cases are present here 
        for(int i=0;i<n;++i)
        {
            dp[i][0]=true;
        }
        dp[n-1][arr[n-1]]=true;
        for(int i=n-2;i>=0;i--)
        {
          
            for(int j=1;j<=target;j++)
            {
                bool ans=dp[i+1][j];
               if(arr[i]<=j)
               {
                   ans=ans|dp[i+1][j-arr[i]];
               }
               dp[i][j]=ans;//we will store the value that will be returned 
            }
        }
        
        return dp[0][target];
       
    }
};