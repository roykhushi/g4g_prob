//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isSafe(vector<vector<int>> &mat, int row, int col, int num){
        for(int i=0;i<=8;i++){
            if(mat[row][i] == num){
                return false;
            }
        }
        
        for(int i=0;i<=8;i++){
            if(mat[i][col] == num){
                return false;
            }
        }
        
        //3x3 matrices
        int oneRPart = row-(row%3);
        int oneCPart = col-(col%3);
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(mat[i+oneRPart][j+oneCPart] == num){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool solveRecSudoku(vector<vector<int>> &mat, int row, int col){
        int n = mat.size();
        
        //base case 
        if (row == n-1 && col == n) {
            return true;
        }

        
        if(col == n){
            row++;
            col =0;
        }
        
        if(mat[row][col] != 0){
            return solveRecSudoku(mat,row,col+1);
        }
        
        for(int i=1;i<=n;i++){
            if(isSafe(mat,row,col,i)){
                mat[row][col] = i;
                if(solveRecSudoku(mat,row,col+1)){
                return true;
            }
            //bactrack
            mat[row][col] = 0;
            }
            
        }
        
        return false;
    }
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solveRecSudoku(mat,0,0);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends