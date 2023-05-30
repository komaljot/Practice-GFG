//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool check(string str1, string str2){
        if(str1.length()!=str2.length())return false;
        unordered_map<char,char>mp;
        int i=0;
        while(i<str1.length()){
            if(mp.find(str1[i])!=mp.end()){
                if(mp[str1[i]]!=str2[i])return false;
                
            }
            else{
                mp[str1[i]]=str2[i];
            }
            i++;
            
        }
        return true;
        
    }
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        return check(str1,str2)&&check(str2,str1);
        
        
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends