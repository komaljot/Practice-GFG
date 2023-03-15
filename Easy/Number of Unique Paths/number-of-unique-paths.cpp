//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    
    int solve(int i,int j,vector<vector<int>>&dp){
        if(i<0 or j<0)return 0; //invalid case
        if(i==0 and j==0)return 1;//valid case
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(i-1,j,dp)+solve(i,j-1,dp);
    }
    
    
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return solve(a-1,b-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends