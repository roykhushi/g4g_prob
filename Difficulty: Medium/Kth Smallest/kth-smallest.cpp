//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    public:
        int partition(vector<int> &arr, int low,int high){
            int pivot = arr[high];
            int i = low-1;
            
            for(int j=low;j<high;j++){
                if(arr[j]<=pivot){
                    i++;
                    swap(arr[i],arr[j]);
                }
            }
            swap(arr[i+1],arr[high]);
            return i+1;
        }
        int quickselect(vector<int> &arr,int low, int high, int k){
            //getting the pivot index
            if(low<=high){
                int pidx = partition(arr,low,high);
                
                if(pidx == k-1){
                    return arr[pidx];
                }
                else if(pidx > k-1){//search in left side
                    return quickselect(arr,low,pidx-1,k);
                }
                else{//search in right side
                    return quickselect(arr,pidx+1,high,k);
                }
            }
            return -1;
        }
    int kthSmallest(vector<int> &arr, int k) {
        //quickselect approach
        int n = arr.size()-1;
        return quickselect(arr,0,n,k);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends