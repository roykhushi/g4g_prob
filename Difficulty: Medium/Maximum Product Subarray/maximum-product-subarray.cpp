//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        long long curr_prod = 1;
        long long max_prod = LONG_MIN;
        
        if(n == 1){
            return arr[0];
        }
        
        for(int i=0;i<n;i++){
            curr_prod *= arr[i];
            
            max_prod = max(max_prod,curr_prod);
            
            if(curr_prod == 0){
                curr_prod = 1;
            }
        }
        
        curr_prod = 1;
        for(int i=n-1;i>=0;i--){
            curr_prod *= arr[i];
            
            max_prod = max(max_prod,curr_prod);
            
            if(curr_prod == 0){
                curr_prod = 1;
            }
        }
        
        return max_prod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends