//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	void helper(int i,int n,string s,string t,vector<string>&ans){
	    if(i>=s.length()){
	        if(t.length()>0){
	            ans.push_back(t);
	           
	        }
	         return;
	    }
	    //not pick
	    helper(i+1,n,s,t,ans);
	    //pick;
	    t.push_back(s[i]);
	    helper(i+1,n,s,t,ans);
	    
	}
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    string t;
		    helper(0,s.length(),s,t,ans);
		   sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends