//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        
        vector<int> ans;
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        int total = rows*cols;
        int count = 0;
        
        int startRow = 0;
        int endRow = rows-1;
        int startCol = 0;
        int endCol = cols-1;
        
        
        
        while(count<total){
            for(int i=startCol;count < total && i<=endCol;i++){
                ans.push_back(mat[startRow][i]);
                count+=1;
            }
            startRow++;
            for(int i=startRow;count < total && i<=endRow;i++){
                ans.push_back(mat[i][endCol]);
                count+=1;
            }
            endCol--;
            for(int i=endCol;count < total && i>=startCol;i--){
                ans.push_back(mat[endRow][i]);
                count+=1;
            }
            endRow--;
            for(int i=endRow;count < total && i>=startRow;i--){
                ans.push_back(mat[i][startCol]);
                count+=1;
            }
            startCol++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends