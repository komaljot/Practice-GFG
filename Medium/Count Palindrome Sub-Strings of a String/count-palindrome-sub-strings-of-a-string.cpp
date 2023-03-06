//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char S[], int N)
{
    //code here
    int count=0;
    //ODD
    for(int axis=0;axis<N;axis++){
        for(int orbit=0;axis-orbit>=0 and axis+orbit<N;orbit++){
            if(S[axis-orbit]==S[axis+orbit])count++;
            else break;
        }
       
    }
     //cout<<count<<endl;
    //EVEN
   for(int l=0,r=1;r<N;l++,r++){
        for(int orbit=0;l-orbit>=0 and r+orbit<N;orbit++){
            if(S[l-orbit]==S[r+orbit])count++;
            else break;
        }
    }
    return count-N;
    
    
}