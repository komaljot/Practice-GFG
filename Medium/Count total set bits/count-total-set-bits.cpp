//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    // int helper(int n){
    //     int count=0;
    //     while(n){
    //         if(n&1)count++;
    //         n=n>>1;
    //     }
    //     return count;
    // }
    
    int p(int n){
        int x=0;
        while(pow(2,x)<=n){
            x++;
        }
        return x-1;
    }
    int countSetBits(int n)
    {
        // Your logic here
        // int cnt=0;
        // for(int i=1;i<=n;i++){
        //     cnt+=helper(i);
        // }
        // return cnt;
        
        //1) finding highest power of 2;
        // int x=0;
        // while(pow(2,x)<=n)x++;
        if(n==0)return 0;
        
        int x=p(n);
        int ans=pow(2,x-1)*x + n-pow(2,x)+1+ countSetBits(n-pow(2,x));
        return ans;
        
        
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends