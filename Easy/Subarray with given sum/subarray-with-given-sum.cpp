//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int>ans;
        int i=0;int j=0;
        long long sum=0;
        if(s==0)return {-1};

        int p=-1,q=-1;
        while(j<n+1 and i<=j){
            
            if(sum<s){
                sum+=arr[j];
                j++;
            }
            else if(sum==s){
                // p=i+1;q=j+1;break;
                return {i+1,j};
            }
            else if(sum>s){
                while(sum>s){
                    sum-=arr[i];
                    i++;
                }
               // j++;
            }
        }
        // if(p==-1 and q==-1)
        return {-1};
        // ans.push_back(p);ans.push_back(q);
        // return ans;
        
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends