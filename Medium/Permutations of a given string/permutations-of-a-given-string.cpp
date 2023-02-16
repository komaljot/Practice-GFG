//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void f(vector<string>&ans,int ind,string s){
	    if(ind==s.length()){
	        ans.push_back(s);
	        return;
	    }
	    for(int i=ind;i<s.length();i++){
	        if(s[i]==s[i+1])continue;
	        swap(s[ind],s[i]);
	        f(ans,ind+1,s);
	        swap(s[ind],s[i]);
	        
	    }
	}
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    //string s="";
		    vector<string>ans;
		    f(ans,0,S);
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends