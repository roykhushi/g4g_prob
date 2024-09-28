//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        pair<long long, long long> ans;
        long long min = LONG_MAX;
        long long max = LONG_MIN;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]<min){
                min = arr[i];
            }
        }
        ans.first = min;
        ans.second = max;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends