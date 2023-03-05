//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int nums[], int n , int target )
{
    // code here
    vector<int>ans;
       // int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){ans.push_back(i);break;}
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){ans.push_back(i);break;}
        }
        if(ans.size()==0)return {-1,-1};
        return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends