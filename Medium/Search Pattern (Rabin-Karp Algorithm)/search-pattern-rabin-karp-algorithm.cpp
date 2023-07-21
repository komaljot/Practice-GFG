//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    #define d 256
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int n=txt.length();
            int m=pat.length();
            // int d=256;
            int i=0;
            int j=0;
            int h=1;
            int prime=101;//q
            vector<int>ans;
            int p=0;//t
            int q=0;//p
            for( i=0;i<m-1;i++){
                h=(h*d)%prime;
            }
            
            for(i=0;i<m;i++){
                p=(p*d+txt[i])%prime;
                q=(q*d+pat[i])%prime;
            }
            
            for(i=0;i<=n-m;i++){
                if(p==q){
                    for(j=0;j<m;j++){
                        if(txt[i+j]!=pat[j])break;
                    }
                    if(j==m)
                    ans.push_back(i+1);
                }
                if(i<n-m){
                    p=(d*(p-txt[i]*h)+txt[i+m])%prime;
                    if(p<0)p=p+prime;
                }
                
            }
            if(ans.empty())return {-1};
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends