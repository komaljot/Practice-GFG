//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void helper(string S,vector<string>&ans,int ind){
        if(ind==S.size()){
            ans.push_back(S);
            return;
        }
       for(int i=ind;i<S.size();i++){
           swap(S[i],S[ind]);
           helper(S,ans,ind+1);
           swap(S[i],S[ind]);
           
       }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>ans;
        
        int i=0;
        helper(S,ans,i);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends