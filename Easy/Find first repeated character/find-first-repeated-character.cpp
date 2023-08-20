//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    string ans="-1";
    int mp[26]={0};
    for(int i=0;i<s.length();i++){
        if(mp[s[i]-'a']==1){
            ans=s[i];
            return ans;
        }
        mp[s[i]-'a']++;
    }
    return ans;
}