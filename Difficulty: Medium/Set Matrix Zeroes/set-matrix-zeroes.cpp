//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    // void markRow(vector<vector<int>> &mat,int i){
    //     int cols = mat[0].size();
        
    //     for(int j=0;j<cols;j++){
    //         if(mat[i][j] != 0){
    //             mat[i][j] = INT_MIN;
    //         }
    //     }
    // }
    
    // void markCol(vector<vector<int>> &mat,int j){
    //     int rows = mat.size();
        
    //     for(int i=0;i<rows;i++){
    //         if(mat[i][j] != 0){
    //             mat[i][j] = INT_MIN;
    //         }
    //     }
    // }
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        
        //brute force => mark every row nd col needed as -1 except for the no 0
        //=> failed at 1010 bcz mat[i][j] from INT_MIN to INT_MAX
        // int rows = mat.size();
        // int cols = mat[0].size();
        
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(mat[i][j] == 0){
        //             markRow(mat,i);
        //             markCol(mat,j);
        //         }
        //     }
        // }
        
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(mat[i][j] == INT_MIN){
        //             mat[i][j] = 0;
        //         }
        //     }
        // }
        
        //better soln
        //similar to the approach you had earlier where you were marking 
        //the indicies of row and col but the issue was that you were 
        //breaking from the loop and only marking the row and col for  the 1st zero encountered
        //in this sol do the same but maintain a row nd col vectors for marking the specific rows and cols
        
        int n = mat.size();
        int m = mat[0].size();
        
        int col[m] = {0};
        int row[n] = {0};
        
        for(int i=0;i<n;i++){ //first marking the particular row and col
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    col[j] = 1;
                    row[i] = 1;
                }
            }
        }
        
        //now traversing the mat to mark the elems as 0 based on the markings of the row and col arr
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i] == 1 || col[j] == 1){
                    mat[i][j] = 0;
                }
            }
        }
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends