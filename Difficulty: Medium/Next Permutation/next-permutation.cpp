//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void reverse(vector<int>& arr, int start, int end){
        int i = start;
        int j = end;
        
        while(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& arr) {
        // code here
        int idx = -1;
        int n = arr.size();
        
        for(int i=n-2;i>=0;i--){
            //finding dip in arr
            if(arr[i]<arr[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            return reverse(arr,0,n-1);
        }
        //finding next larger no. than the idx
        for(int i=n-1;i>=idx;i--){
            if(arr[i] > arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        //reverse the arr after that idx
        reverse(arr,idx+1,n-1);
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
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends