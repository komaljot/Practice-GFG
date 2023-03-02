//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(vector<int>& height, int n, int k,vector<int>&dp){
      //tabulation
      dp[0]=0;
      for(int i=1;i<n;i++){
          int mini=INT_MAX;int t=0;
          for(int j=1;j<=k;j++){
              if(i-j>=0) 
              t=dp[i-j]+abs(height[i]-height[i-j]);
              mini=min(mini,t);
          }
          dp[i]=mini;
      }
      return dp[n-1];
      
      
  }
  
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return f(height,n,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends