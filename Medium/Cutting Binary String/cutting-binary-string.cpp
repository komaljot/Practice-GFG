//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool checkpoweroffive(string s){
        int n=s.length();
        if(n==0)return false;
        if(s[0]=='0')return false;
        long long num=0;
        for(int i=0;i<n;i++){
            num=num*2+(s[i]-'0');
        }
        if(num==0)return false;
        while(num>1){
            if(num%5!=0)return false;
            num=num/5;
        }
        return true;
        
    }
    int cuts(string s){
        int n=s.length();
        //code
        if(n==0 || s[0]=='0')return -1;
        if(checkpoweroffive(s))return 1;
        int ans=INT_MAX;
        
        for(int i=1;i<n;i++){
            string left=s.substr(0,i);
            string right=s.substr(i);
            if(checkpoweroffive(left)){
              int rtcuts=cuts(right);
              if(rtcuts!=-1){
                  ans=min(ans,1+rtcuts);
              }
            }
           
            
            
        }
        if(ans!=INT_MAX)return ans;
        return -1;
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends