//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            int n = Integer.parseInt(read.readLine());
            String input[] = read.readLine().split(" ");
            
            int arr[] = new int[n];
            for(int i = 0;i<n;i++){
                arr[i] = Integer.parseInt(input[i]);
            }
            
            Solution ob = new Solution();
            System.out.println(ob.countTriplet(arr, n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    int countTriplet(int arr[], int n) {
        // code here
        //using two pointer approach
        Arrays.sort(arr); //1,2,3,5
        int count =0;
        for(int i=n-1;i>=1;i--){
            int low = 0;
            int high = i-1;
            
            while(low<high){
                if(arr[low] + arr[high] == arr[i]){
                    count ++;
                    low ++;
                    high--;
                }
                else if(arr[low] + arr[high] < arr[i]){
                    low ++;
                }
                else{
                    high --;
                }
            }
        }
        return count;
    }
}