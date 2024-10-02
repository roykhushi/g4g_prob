//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        // vector<int> ans;
        // int n = nums.size();
        // unordered_map<int,int> mp;
        
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }
        // for(auto i : mp){
        //     if(i.second > n/3){
        //         ans.push_back(i.first);
        //     }
        // }
        // if(ans.empty()){
        //     ans.push_back(-1);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        
        //using boyre moore voting algo
        int n = nums.size();

    // There can be at most two elements with more than n/3 frequency
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

    // Step 1: Find potential candidates using Boyer-Moore Voting Algorithm
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify the candidates by counting their occurrences in the array
    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        }
    }

    vector<int> result;
    if (count1 > n / 3) {
        result.push_back(candidate1);
    }
    if (count2 > n / 3) {
        result.push_back(candidate2);
    }

    // If no majority element exists, return -1
    if (result.empty()) {
        return {-1};
    }

    return result;
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
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends