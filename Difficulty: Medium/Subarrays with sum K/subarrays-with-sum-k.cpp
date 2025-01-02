//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        //brute force = O(n2) gave tle at 1110/1111 test cases
        // int count = 0;
        
        // for(int i=0;i<arr.size();i++){
        //     int sum = arr[i];
        //     if(sum == k) { //for single elem in the arr
        //         count++;
        //     }
        //     for(int j=i+1;j<arr.size();j++){
        //         sum += arr[j];
                
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        //optimised
        
        int curr_sum = 0;
        int count = 0;
        
        map<int,int> mp;
        
        mp[0] = 1;
        
        
        for(int i=0;i<arr.size();i++){
            curr_sum += arr[i];
            
            if(mp.find(curr_sum-k) != mp.end()){
                count += mp[curr_sum-k];
            }
            
            mp[curr_sum]++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends