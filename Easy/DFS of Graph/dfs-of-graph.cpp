//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
     void dfs(int V, vector<int>adj[],vector<bool>&vis,int node,vector<int>&ans){
        //if(vis[node])return;
        
        if(!vis[node]){
            ans.push_back(node);
            vis[node]=true;
            for(auto it:adj[node]){
            if(!vis[it])
            dfs(V,adj,vis,it,ans);
                
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>vis(V,0);
        dfs(V,adj,vis,0,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends