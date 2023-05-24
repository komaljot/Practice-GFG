//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        
        //genrating 1 in the mask using 1
        int mask=0;
        if(r-l+1 ==32)
       mask=(1<<(r-l+1))-1;
        else  mask=(1<<(r-l+1));
        mask--;//subtracting 1
        mask=(mask<<(l-1));
        mask=(mask&y);
        x=x|mask;
        return x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends