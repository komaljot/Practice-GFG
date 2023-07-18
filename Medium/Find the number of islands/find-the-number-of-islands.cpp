//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int n,int m,int r,int c){
        vis[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int b=r+dr;
                    int l=c+dc;
                    if(b<n and b>=0 and l<m and l>=0 and !vis[b][l] and grid[b][l]=='1'){
                        vis[b][l]=1;
                        q.push({b,l});
                    }
                }
            }
        }
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        // vector<vector<int>> vis(n, vector<int>(m, 0)); // Add the closing angle bracket here

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,vis,n,m,i,j);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends