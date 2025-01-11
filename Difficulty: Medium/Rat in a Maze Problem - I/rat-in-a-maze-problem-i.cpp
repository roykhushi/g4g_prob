//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSafe(int newX, int newY, vector<vector<int>> &vis,vector<vector<int>> &mat, int n){
        if((newX >= 0 && newX < n) && (newY >=0 && newY < n) && vis[newX][newY] == 0 && mat[newX][newY] == 1){
            return true;
        }
        
        return false;
    }
    void solve(int x, int y, vector<vector<int>> &mat, vector<vector<int>> &vis, vector<string> &ans, string path, int n){
        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        //4 movements -> DLRU
        
        //down
        if(isSafe(x+1,y,vis,mat,n)){
            vis[x][y] = 1;
            solve(x+1,y,mat,vis,ans,path+'D',n);
            vis[x][y] = 0;
        }
        
        //left
        if(isSafe(x,y-1,vis,mat,n)){
            vis[x][y] = 1;
            solve(x,y-1,mat,vis,ans,path+'L',n);
            vis[x][y] = 0;
        }
        
        //right
        if(isSafe(x,y+1,vis,mat,n)){
            vis[x][y] = 1;
            solve(x,y+1,mat,vis,ans,path+'R',n);
            vis[x][y] = 0;
        }
        
        //up
        if(isSafe(x-1,y,vis,mat,n)){
            vis[x][y] = 1;
            solve(x-1,y,mat,vis,ans,path+'U',n);
            vis[x][y] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string> ans;
        
        int n = mat.size();
        
        if(mat[0][0] == 0){
            return ans;
        }
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        solve(0,0,mat,vis,ans,"",n);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends