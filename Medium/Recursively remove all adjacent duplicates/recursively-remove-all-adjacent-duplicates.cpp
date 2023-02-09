//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
        string ans;
        int i=0;
        int n=s.length();
        while(i<n){
            if(s[i]!=s[i+1]){
                ans+=s[i];
            }
            else{
                while(s[i]==s[i+1])i++;
            }
            i++;
        }
        if (ans.size()== s.size())

    return ans;

   return rremove(ans);

    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends