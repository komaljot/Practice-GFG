//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int ones=0;int zeros=0;int maxzeros=-1;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zeros++;
                maxzeros=max(maxzeros,zeros);
            }
            else{
                ones++;
                if(zeros>0)zeros--;
                maxzeros=max(maxzeros,zeros);
                if(zeros<0)zeros=0;
                
            }
        }
        return ones+maxzeros;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends