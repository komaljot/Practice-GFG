//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>&mat,int n, int m,int dr[],int dc[]){
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        
        if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==0 and mat[nr][nc]=='O'){
            dfs(nr,nc,vis,mat,n,m,dr,dc);
        }
    }
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
       int dr[4]={-1,0,1,0};
       int dc[4]={0,1,0,-1};
       //first row and last row
       for(int j=0;j<m;j++){
           if(vis[0][j]==0 and mat[0][j]=='O'){
               dfs(0,j,vis,mat,n,m,dr,dc);
           }
           if(vis[n-1][j]==0 and mat[n-1][j]=='O'){
               dfs(n-1,j,vis,mat,n,m,dr,dc);
           }
       }
       //first col and last col
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 and mat[i][0]=='O'){
                dfs(i,0,vis,mat,n,m,dr,dc);
            }
             if(vis[i][m-1]==0 and mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat,n,m,dr,dc);
        }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends