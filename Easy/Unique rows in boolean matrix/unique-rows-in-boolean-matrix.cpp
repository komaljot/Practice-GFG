//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int r,int c)
    {
        //Your code here
        vector<vector<int>>ans;
        unordered_set<string>u;
        
        for(int i=0;i<r;i++){
            string r="";
            for(int j=0;j<c;j++){
                r+=to_string(M[i][j])+",";
            }
            if(u.find(r)==u.end()){
                u.insert(r);
                vector<int>row;
                for(int j=0;j<c;j++){
                    row.push_back(M[i][j]);
                }
                ans.push_back(row);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends