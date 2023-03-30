//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void helper(int col,int n,vector<int>&board,vector<int>&left,vector<int>&ld,vector<int>&ud,vector<vector<int>>&ans){
    if(col==n){ans.push_back(board);return;}
    for(int row=0;row<n;row++){
        if(left[row]==0 and ld[row+col]==0 and ud[n-1+col-row]==0){
            left[row]=1; ld[row+col]=1; ud[n-1+col-row]=1;
            board[row]=col+1;
            helper(col+1,n,board,left,ld,ud,ans);
            left[row]=0; ld[row+col]=0; ud[n-1+col-row]=0;
            board[row]=0;
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<int>board(n,0);
        vector<int>left(n,0);
        vector<int>ud(2*n-1,0);
        vector<int>ld(2*n-1,0);
        helper(0,n,board,left,ld,ud,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends