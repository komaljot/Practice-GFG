//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
       
       //----APPROACH 1 - BRUTE FORCE!
        // long maxi=INT_MIN;
        // for(int i=0;i<N;i++){
        //      long sum=0;
        //     for(int j=i;j<min(i+K,N);j++){
        //         sum+=Arr[j];
        //     }
        //     maxi=max(maxi,sum);
        // }
        // return maxi;
        
        //APPROACH 2 - SLIDING WINDOW!
        
        int i=0;//denotes starting of the window
        int j=0;//denotes end of the window
        long sum=0;
        long maxi=LONG_MIN;
        while(j<N){//we will move the window till j reaches the end of the loop
         sum+=Arr[j];//adding jth ele every time
         if(j-i+1==K){//implies humare kaam ka ele
         maxi=max(maxi,sum);//updates maxi if needed
         sum-=Arr[i];//removing the ith ele from the window
         i++;j++;//shifting winodw ahead
             
         }
         else if(j-i+1<K)j++;
        
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends