//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
		    int dp[n+1][n+1]={0};
		    for(int i=n;i>=0;i--){
		        for(int j=n;j>=0;j--){
		            if(i==n and j==n)dp[i][j]=0;//last ele
		            else if(i==n)dp[i][j]=0;//last row
		             else if(j==n)dp[i][j]=0;//last col
		             else{
		                 if(str[i]==str[j] and i!=j)dp[i][j]=dp[i+1][j+1]+1;
		                 else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
		             }
		        }
		    }
		    return dp[0][0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends