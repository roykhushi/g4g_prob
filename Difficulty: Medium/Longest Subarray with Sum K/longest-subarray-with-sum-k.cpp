//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        // int n = arr.size();
        // int maxSize = 0;
        
        // for(int i=0;i<n;i++){
        //     long long sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //         if(sum == k){
        //             maxSize = max(maxSize,j-i+1);
        //         }
        //     }
        // }
        // return maxSize;
        
        map<int,int> mp;
        int maxSize = 0;
        int n = arr.size();
        long long sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum == k){
                maxSize = max(maxSize,i+1);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            long long rem = sum-k;
            
            if(mp.find(rem) != mp.end()){
                maxSize = max(maxSize,i-mp[rem]);
            }
        }
        
        return maxSize;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends