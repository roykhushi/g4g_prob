//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        //brute force
        // for(int i=0;i<arr.size();i++){
        //     for(int j=i+1;j<arr.size();j++){
        //         if(arr[i] + arr[j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        //optimised
        map<int,int> mp;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            int half = target-arr[i];
            
            if(mp.find(half) != mp.end()){
                return true;
            }
            mp[arr[i]] = i;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends