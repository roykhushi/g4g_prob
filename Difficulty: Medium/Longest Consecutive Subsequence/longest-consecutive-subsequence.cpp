//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int curr_len = 1;
        int max_len =1;
        
        sort(arr.begin(),arr.end());
        
        for(int i=1;i<arr.size();i++){
            if(arr[i] == arr[i-1]+1){
                curr_len+=1;
            }
            else if(arr[i] == arr[i-1]){
                continue;
            }
            else{
                max_len = max(max_len,curr_len);
                curr_len = 1;
            }
        }
        max_len = max(max_len,curr_len);
        
        return max_len;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends