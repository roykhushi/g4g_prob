//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> preProd(n,1);
        vector<int> suffProd(n,1);
        
        // preProd[0] = arr[0];
        // suffProd[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++){
            preProd[i] = arr[i-1]*preProd[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffProd[i] = arr[i+1]*suffProd[i+1];
        }
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            ans[i] = preProd[i]*suffProd[i];
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends