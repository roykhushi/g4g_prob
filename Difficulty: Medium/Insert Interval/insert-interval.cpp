//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,vector<int> &newInterval) {
        // code here
        vector<vector<int>> ans;
        
        intervals.push_back(newInterval);
        vector<int> temp = {-1,-1};
        
        sort(intervals.begin(),intervals.end());
        
        for(auto x : intervals){
            if(temp[0] == -1){
                temp = x;
            }
            else{
                if(temp[1] >= x[0]){
                    temp[1] = max(x[1],temp[1]);
                    // temp = x;
                    // ans.push_back(x);
                }
                else{
                    ans.push_back(temp);
                    temp = x;
                }
            }
        }
        
        
        ans.push_back(temp);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends