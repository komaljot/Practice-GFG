//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

int findcountlessthaneqto(vector<int>row,int mid){
    int low=0;
    int high=row.size()-1;
    while(low<=high){
        int m=(low+high)/2;
        if(row[m]<=mid)low=m+1;
        else high=m-1;
    }
    return low;
    
}


    int median(vector<vector<int>> &matrix, int R, int C){
        // code here    
        int low=0;
        int high=1e9;
        int n=matrix.size();
        int m=matrix[0].size();
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
            cnt+=findcountlessthaneqto(matrix[i],mid);
            }
            if(cnt>(m*n)/2)high=mid-1;
             else low=mid+1;
            
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends