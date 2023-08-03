//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>ans(N,INT_MAX);
        ans[0]=0;
        
        queue<int>q;
        q.push(0);
        
        vector<pair<int,int>>adj[N];
        for(int i=0 ; i<M ; i++)
        {
            adj[edges[i][0]].push_back( { edges[i][1] , edges[i][2] } );
        }
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            for(auto u:adj[it])
            {
                if(ans[it]+u.second < ans[u.first] )
                {
                    ans[u.first] = ans[it]+u.second;
                    q.push(u.first);
                }
            }
        }
        
        for(int i=0 ; i<ans.size() ; i++)
        {
            if(ans[i]==INT_MAX)
            {
                ans[i]=-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends