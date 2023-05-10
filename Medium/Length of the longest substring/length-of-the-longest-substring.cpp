//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        // vector<int>m(26,0);
        int m[26]={0};
        int i=0;
        int j=0;
        int ans=0;
        
        while(j<S.size()){
            if(m[S[j]-'a']!=0){
                m[S[i]-'a']--;
                i++;
                
                
            }
            else{
                m[S[j]-'a']++;
                
                ans=max(ans,j-i+1);
                j++;
            }
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends