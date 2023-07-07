//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
    //     int ans=INT_MAX;
    //     int start=0;
    //     string res="";
       
    //     unordered_map<char,int>mp;
    //     for(int i=0;i<p.size();i++)mp[p[i]]++;
        
    //      int cnt=mp.size();
    //      int i=0;int j=0;
    //      while(j<s.size()){
    //          if(mp.find(s[j])!=mp.end()){
    //              mp[s[j]]--;
    //              if(mp[s[j]]==0)cnt--;
    //          }//j++;
    //          if(cnt==0){//ans mila
    //             //  ans=min(ans,j-i+1);
    //              while(cnt==0){
    //                  if(mp.find(s[i])!=mp.end()){
    //                      mp[s[i]]++;
                        
    //                      if(mp[s[i]]==1){
    //                          cnt++;
    //                         //  ans=min(ans,j-i+1);
    //                          if(j-i+1<ans){
    //                             ans=j-i+1;
    //                             start=i;
    //                         }
                             
    //                      }
                         
    //                  }
    //                   i++;
    //              }
    //          }j++;
             
    //      }
    //     //  cout<<ans;
    //     if(ans==INT_MAX)return "";
    //      return s.substr(start,ans);
         
    // }
      int m[256]={0};
        // count of distinct characters of p string
        int cnt=0;
        // count of distinct characters and counter array incrementing
        for(int i=0; i<p.length(); i++){
            if(m[p[i]]==0)  cnt++;    
            m[p[i]]++;
        }
        int i=0, j=0, st=0, ans=INT_MAX;
        // sliding window logic
        while(i<s.length()){
            m[s[i]]--;
            // whenever we encounter the character of p string in s m[s[i]] value will become zero for other characters it will become negative as we intialized the m values to -1
            if(m[s[i]]==0)  cnt--;
            // above for the given if we will decrement the cnt
            // when cnt becomes zero it means that we got a window where we get all characters of p
            if(cnt==0){
                while(cnt==0){
                    // Now we will find minimum possible window for it when cnt==0 we will find the min size and store it in ans
                    if(ans>i-j+1){
                        ans=i-j+1;
                        st=j;
                    }
                    // Now we will increment j (the starting position) and check if m[s[j]]>0 if greater than zero it means we have to one more character in string p and for it we will iincrement the count
                    
                    m[s[j]]++;
                    if(m[s[j]]>0)  cnt++;
                    j++;
                }
            }
            i++;
        }
        if(ans==INT_MAX)    return "-1";
        return s.substr(st,ans);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends