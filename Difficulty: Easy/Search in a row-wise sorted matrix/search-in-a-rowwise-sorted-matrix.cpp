//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();
        
        for(int j=0;j<rows;j++){
            
            int start = 0;
            int end = cols-1;
            
            while(start <= end){
                int mid = start + (end-start)/2;
                
                int elem = mat[j][mid];
                
                if(elem == x){
                    return true;
                }
                else if(elem < x){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends