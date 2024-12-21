//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
       
        
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(mat[i][j] == x){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
         int rows = mat.size();
         int cols = mat[0].size();
        
        // for(int i=0;i<cols;i++){
        //     int start = 0;
        //     int end = rows-1;
            
        //     while(start <= end){
        //         int mid = start + (end-start)/2;
        //         int elem = mat[mid][i];
        //         if(elem == x){
        //             return true;
        //         }
        //         else if(elem < x){
        //             start = mid+1;
        //         }
        //         else{
        //             end = mid-1;
        //         }
        //     }
        // }
        // return false;
        
        int i = 0;
        int j = cols-1;
        
        while(i<rows && j>=0){
            int elem = mat[i][j];
            if(elem > x){
                j--;
            }
            else if(elem < x){
                i++;
            }
            else{
                return true;
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends