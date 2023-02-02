//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string S){
    //complete the function here
    string ans="";
    int count=1;
        S.push_back('#');

    for(int i=1;i<S.length();i++){
        if(tolower(S[i])==tolower(S[i-1])){
            count++;
        }
        else{
            ans=ans+to_string(count);
           ans.push_back(tolower(S[i-1]));
           count=1;
           
        }
    }
    return ans;
}

