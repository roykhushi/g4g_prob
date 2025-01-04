//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        //brute force = O(n3) == tle  
        
        // vector<vector<int>> ans;
        // int n = arr.size();
        
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         for(int k=j+1;k<n;k++){
        //             int sum = arr[i]+arr[j]+arr[k];
        //             if(sum == target){
        //                 vector<int> temp = {arr[i],arr[j],arr[k]};
        //                 ans.push_back(temp);
        //             }
        //         }
        //     }
        // }
        // return ans.size();
        
        
        int count = 0;
        int n = arr.size();
        
        for (int i = 0; i < n - 2; i++) {
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = (target-arr[i]);
                if (arr[j] + arr[k] == sum) {
                    count++;
                    //handling dup values of arr[j]
                    int temp = j + 1;
                    while (temp < k && arr[temp] == arr[temp - 1]) {
                        count++;
                        temp++;
                    }
                    k--;
                } 
                else if (arr[j] + arr[k] < sum) {
                    j++;
                } 
                else {
                    k--;
                }
            }
        }
        return count;
    }
};



//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends