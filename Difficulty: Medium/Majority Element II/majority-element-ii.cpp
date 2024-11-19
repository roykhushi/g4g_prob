//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = arr.size();
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(auto &i : mp){
            if(i.second > n/3){
                ans.push_back(i.first);
            }
        }
        // if(ans.size() == 0){
        //     ans.push_back(-1);
        // }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends