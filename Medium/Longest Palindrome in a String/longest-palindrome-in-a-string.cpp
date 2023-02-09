//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int expand(int l,int r,int n,string &s){
        while(l>=0 && r<n && s[l]==s[r])l--,r++;
        return r-l-1;
    }
    string longestPalin (string s) {
        // code here
        int n=s.size(),start=0,end=0;
    for(int i=n-1;i>=0;i--){
        int len1=expand(i,i,n,s);
        int len2=expand(i,i+1,n,s);
        int len=max(len1,len2);
        if(len>end-start){
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }
    return s.substr(start,end-start+1);
    
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends