//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
  void dfs( vector<int>adjlist[], vector<bool>&vis,int node){
      vis[node]=true;
      for(auto it:adjlist[node]){
          if(!vis[it]){
              dfs(adjlist,vis,it);
          }
          
      }
      
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjlist[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 and i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<bool>vis(V,0);
        int cnt=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                
                dfs(adjlist,vis,i);
                cnt++;
            }
            
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends