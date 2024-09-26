//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int,int> map;
        int sum = 0;
        int max_len = 0;
        map[0] = -1;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            if(map.find(sum) != map.end()){
                max_len = max(max_len, i-map[sum]);
            }
            else{
                map[sum] = i;
            }
        }
        
        return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends