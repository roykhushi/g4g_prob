//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int> ans;
        map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            
            if(i<k-1){
                continue;
            }
            ans.push_back(mp.size());
            
            if(mp[arr[i-k+1]] == 1){
                mp.erase(arr[i-k+1]);
            }
            else{
                mp[arr[i-k+1]]--;
            }
            
        }
        return ans;
        
        
        //brute forve
        
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends