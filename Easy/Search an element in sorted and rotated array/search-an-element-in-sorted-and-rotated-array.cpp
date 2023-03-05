//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> A, int key) {
    //code here
    int s=0;
    int e=A.size()-1;
     int mid;
        //complete the function here
        while(s<=e){
            mid=s+(e-s)/2;
            if(A[mid]==key)return mid;
            else if(A[mid]>=A[s]){
                if(A[s]<=key and key<A[mid]){
                    e=mid-1;
                    
                }
                else s=mid+1;
            }
            else{
                if(A[mid]<key and key<=A[e]){
                     s=mid+1;;
                    
                }
                else e=mid-1;
                
            }
            
        }
        return -1;
}