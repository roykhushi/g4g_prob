//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int start = 0;
        int end = arr.size()-1;
        int index = -1;
        
        int ans = INT_MAX;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(arr[start] <= arr[end]){
                index = start;
                ans = arr[start];
                break;
            }
            if(arr[start] <= arr[mid]){
                if(arr[start] < ans){
                    index = start;
                    ans = arr[start];
                }
                start = mid+1;
            }
            else{
                end = mid;
                if(arr[mid] < ans){
                    index = mid;
                    ans = arr[mid];
                }
            }
        }
        
        return index;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends