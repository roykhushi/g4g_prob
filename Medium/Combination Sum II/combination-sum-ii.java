//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter ot = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String s[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int k = Integer.parseInt(s[1]);
            int a[] = new int[n];
            s = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);
            List<List<Integer>> ans = new Solution().CombinationSum2(a, n, k);
            for (List<Integer> list : ans) {
                for (int x : list) ot.print(x + " ");
                ot.println();
            }
            if (ans.size() == 0) ot.println();
        }
        ot.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public static void solve(int idx, int[] arr, int k, List<List<Integer>> ans, List<Integer>l){
        if(k == 0){
            ans.add(new ArrayList<>(l));
            return;
        }
        for(int i=idx;i<arr.length;i++){
            if(i>idx && arr[i] == arr[i-1] ) {
                continue;
            }
            if(arr[idx] > k){
                break;
            }
            l.add(arr[i]);
            solve(i+1,arr,k-arr[i],ans,l);
            l.remove(l.size()-1);
        }
    }
    public List<List<Integer>> CombinationSum2(int arr[], int n, int k) {
        // Code Here.
        List<List<Integer>> ans = new ArrayList<>();
        //List<Integer> l = new ArrayList<>();
        Arrays.sort(arr);
        solve(0,arr,k,ans,new ArrayList<>());
        return ans;
    }
}
