//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
//   public:
//   int mod=1e+7;
// //   int a=0;int b=0;
//   int helper(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
//       if(i<0 or j<0)return 0;//invalid case
//       if(i==0 and j==0)return 1;
//       if(dp[i][j]!=-1) return dp[i][j];
//       int a=0;
//       if(grid[i][j]==1) a= helper(i-1,j,grid,dp);
//       int b=0;
//       if(grid[i][j]==1) b= helper(i,j-1,grid,dp);
//       return dp[i][j]=(a+b)%mod;
//   }
  
  
//     int uniquePaths(int n, int m, vector<vector<int>> &grid) {
//         // code here
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//           if(grid[0][0]==0 || grid[n-1][m-1]==0) return 0;
//       return  helper(n-1,m-1,grid,dp)%mod;
        
//     }
// };
public:
  int mod=1e9+7;
    int helper(int row,int col,vector<vector<int>> &grid,int n,int m,vector<vector<int>>&dp){
        if(row==0 && col==0){
            return 1;
        }
        if(row<0 ||col<0 ) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        
        int up=0;
        if(grid[row][col]==1){
            up=helper(row-1,col,grid,n,m,dp);
        }
        int left=0;
        if(grid[row][col]==1){
            left=helper(row,col-1,grid,n,m,dp);
        }
        return dp[row][col]=(up+left)%mod;
        
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(grid[0][0]==0 || grid[n-1][m-1]==0) return 0;
        return helper(n-1,m-1,grid,n,m,dp)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends