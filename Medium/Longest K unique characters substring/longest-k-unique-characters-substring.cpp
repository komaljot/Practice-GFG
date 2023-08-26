//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
     if(k>s.length())return -1;
    int ans=-1;
    unordered_map<char,int>mp;
    int n=s.length();
    int i=0;int j=0;
    while(j<n){
        mp[s[j]]++;
        if(k==mp.size()){
            ans=max(ans,j-i+1);
            j++;
        }
        else if(k>mp.size())j++;
        else if(k<mp.size()){
            while(k<mp.size()){
               
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
                j++;
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends