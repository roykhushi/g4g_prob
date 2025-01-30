//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // void addSolution(vector<vector<int>> &board,vector<vector<int>> &ans, int n){
    //     vector<int> temp;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             temp.push_back(board[i][j]);
    //         }
    //     }
        
    //     ans.push_back(temp);
    // }
    
    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        int x = row;
        int y = col;
        
        //for row
        while(y>=0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
        }
        
        x = row;
        y = col;
        
        //for diag
        while(x>=0 && y>=0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
            x--;
        }
        
        x = row;
        y = col;
        
        while(x<n && y>=0){
            if(board[x][y] == 1){
                return false;
            }
            x++;
            y--;
        }
        
        return true;
    }
    
    void solve(int col,vector<vector<int>> &board,vector<vector<int>> &ans,vector<int> temp,int n){
        //base case
        if(col == n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 1;
                temp.push_back(row+1);
                solve(col+1,board,ans,temp,n);
                //backtrack
                temp.pop_back();
                board[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        solve(0,board,ans,temp,n);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends