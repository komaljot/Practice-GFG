//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
// bool check(vector<vector<int> >& matrix){
//     for(int i=0;i<8;i++){
        
//     }
// }

    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==1)return 0;
        int di[8]={1,-1,-1,0,1,1,-1,0};
        int dj[8]={-1,0,1,1,1,0,-1,-1};
        int fcnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(matrix[i][j]==1){
                for(int k=0;k<8;k++){
                    int r=i+di[k];
                    int c=j+dj[k];
                    if(r>=0 and r<n and c>=0 and c<m and matrix[r][c]==0 )cnt++;
                }
                 if(cnt>0 and cnt%2==0)fcnt++;
                }
               
            }
        }
        return fcnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends