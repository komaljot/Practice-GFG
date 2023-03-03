//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    
   
     int m=pow(10,9)+7;


    long long power(int N,int R)
    {
//      double ans=1.0;
//         long long nn=n;
//         if(nn<0)nn=-1*nn;

//         while(nn){
//     if(nn%2==0){
//         x=x*x;
//         nn=nn/2;

//     }
//     else{
//          ans=ans*x; 
//             nn=nn-1;


//     }
//     }
// if(n<0)ans=(double)(1.0)/(double)(ans);
// return ans;
 if(R==0)return 1;

         if(R==1)return N;

         if(R%2==0){ 

             long long temp=power(N , R/2)%m;

             return (temp%m*temp%m)%m;

             }

        else return (power(N , R-1)%m * N)%m;
      
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends