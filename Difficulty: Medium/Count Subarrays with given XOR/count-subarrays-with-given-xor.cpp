//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        //brute force
        //O(n2) --> tle
        // long count = 0;
        // for(int i=0;i<arr.size();i++){
        //     long temp = 0;
        //     for(int j=i;j<arr.size();j++){
        //         temp = temp^arr[j];
        //         if(temp == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        //optimised
        //using map to find the prev xor == curr_xor^k;
        
        long count = 0;
        unordered_map<int,int> mp;
        
        mp[0] = 1;
        
        long curr_xor = 0;
        
        for(int i=0;i<arr.size();i++){
            curr_xor = curr_xor^arr[i];
            if(mp.find(curr_xor^k) != mp.end()){
                count += mp[curr_xor^k];
            }
            mp[curr_xor]++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends