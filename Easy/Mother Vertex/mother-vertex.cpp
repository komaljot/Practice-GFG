//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void dfs( vector<int>adj[],int k,int arr[]){
        arr[k]=1;
        for(int x:adj[k]){
            if(arr[x]==0){
                dfs(adj,x,arr);
            }
        }
    }
    
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int arr[V]={0};
	    int ln=0;
	    
	    for(int i=0;i<V;i++){
	        if(arr[i]==0){
	            dfs(adj,i,arr);
	            ln=i;
	        }
	    }
	   for(int i=0;i<V;i++)arr[i]=0;
	    dfs(adj,ln,arr);
	    for(int x:arr){
	        if(x==0)return -1;
	        
	    }
	    return ln;
	    
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends