//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //using merge sort
  
    int conquer(vector<int> &arr,int start,int mid, int end){
        
        vector<int> merged;
        int count = 0;
        
        int i = start;//left arr
        int j = mid+1; //right arr;
        
        while(i<=mid && j<=end){
            if(arr[i] <= arr[j]){
                merged.push_back(arr[i]);
                i++;
            }
            else{
                merged.push_back(arr[j]);
                count += (mid-i+1);
                j++;
            }
        }
        
        //left over elements;
        while(i<=mid){
            merged.push_back(arr[i]);
            i++;
        }
        while(j<=end){
            merged.push_back(arr[j]);
            j++;
        }
        for(int x=start;x<=end;x++){
            arr[x] = merged[x-start];
        }
        return count;
        
    }
  
    int divide(vector<int> &arr,int start, int end){
        int mid = start + (end-start)/2; 
        int count = 0;
        if(start>=end){
            return count;
        }
        //divide the arrays 
        count += divide(arr,start,mid);
        count += divide(arr,mid+1,end);
        count += conquer(arr,start,mid,end);
        
        return count;
    }
  
 
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        //brute force O(n2)
        // int n = arr.size();
        // int count = 0;
        
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[i] > arr[j]){
        //             count+=1;
        //         }
        //     }
        // }
        // return count;
        int n = arr.size();
        
        int ans = divide(arr,0,n-1);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends