//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        // int s=0;
        
        // unordered_map<int,int>mp;
        // mp[0]++;
        // for(int i=0;i<n;i++){
        //     s=s+arr[i];
        //     mp[s]++;
            
            
        // }
        // for(auto x:mp)if(x.second>1)return true;
        // else return false;
        unordered_map<int ,int> mp ;
        int sum=0; 
        mp[0]++; 
         for(int i=0; i<n; i++){
             sum+=arr[i]; 
             mp[sum]++; 
         }
         for(auto x:mp) if(x.second>1) return true; 
         return false; 
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends