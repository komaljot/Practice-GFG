//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int count=0;
        int s=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            //int a=0;
            s+=A[i];
            if(s==0){
               // count=max(count,i-a);
               count=i+1;
            }
            else{
            if(m.find(s)==m.end()){
            m[s]=i;}
            
            else {
                count=max(count,i-m[s]); 
            }
                
            
            } 
          
        }
        return count;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends