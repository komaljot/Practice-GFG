//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans=0;
        int n=str.length();
        int indicator=1;//to keep a check on the sign
        int i=0;
        //if we encounter empty spaces--simply go ahead
         if(n == 0){
            return 0;
        }
        // while(i<n){
        //     if(str[i]==' ')i++;
        // }
        if(str[i]=='-' and i<n){
            indicator=-1;i++;
        }
        else if(str[i]=='+' and i<n) {
            indicator=1;i++;
        }
        while(i<n){
            if(str[i]<'0' || str[i]>'9')return -1;
            ans=ans*10+str[i]-'0';
            i++;
            if(ans>=INT_MAX)return INT_MAX;
            if(ans<=INT_MIN)return INT_MIN;
        }
        return ans*indicator;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends