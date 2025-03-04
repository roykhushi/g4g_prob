//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    // int solve(vector<int> &arr, int idx, int prevIdx){
    //     int n = arr.size();
        
    //     if(idx == n){
    //         return 0;
    //     }
        
    //     int excl = solve(arr,idx+1,prevIdx);
        
    //     int incl = 0;
    //     if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
    //         incl = 1+solve(arr,idx+1,idx);
    //     }
        
    //     return max(incl,excl);
    // }
    
    int lis(vector<int>& arr) {
        // code here
        // int ans = solve(arr,0,-1);
        
        // return ans;
        
        
        int n = arr.size();
        
        if(n == 0){
            return 0;
        }
        
        vector<int> dp(n,1);
        int ans = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends