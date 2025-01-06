//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        
        if(arr.size() < 2){
            return vector<int>();
        }
        
        vector<int> ans;
        
        int diff = INT_MAX;
        int a = arr[0];
        int b = arr[arr.size()-1];
        
        int i = 0;
        int j = arr.size()-1;
        
        while(i<j){
            int sum = arr[i]+arr[j];
            int curr_diff = abs(target-sum);
            
            if(curr_diff == diff){
                if(abs(arr[i]-arr[j]) > abs(a-b)){
                    a = arr[i];
                    b = arr[j];
                }
            }
            else if(curr_diff < diff){
                diff = curr_diff;
                a = arr[i];
                b = arr[j];
            }
            
            if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends