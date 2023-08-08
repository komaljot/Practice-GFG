//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

int lessthaneqto(vector<int>&R,int mid){
    int cnt=0;
    int low=0;
    int high=R.size()-1;
    while(low<=high){
        int m=(low+high)/2;
        if(R[m]<=mid)low=m+1;
        else high=m-1;
    }
    return low;
    
}

    int median(vector<vector<int>> &matrix, int R, int C){
        // code here   
        int low=0;
        int high=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<R;i++){
                
                cnt+=lessthaneqto(matrix[i],mid);
            }
            if(cnt>(R*C)/2)high=mid-1;
            else {
                low=mid+1;
            }
            
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