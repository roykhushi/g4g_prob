//{ Driver Code Starts
//Initial Template for Java



import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int k = Integer.parseInt(inputLine[0]);
            int n = Integer.parseInt(inputLine[1]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            boolean ans = new Solution().checkDuplicatesWithinK(arr, n, k);
            if (ans) {
                System.out.println("True");
            } else {
                System.out.println("False");
            }
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution {
    boolean checkDuplicatesWithinK(int[] arr, int n, int k) {
        // code here
        HashSet<Integer> set = new HashSet<>();
        
        for(int i=0;i<n;i++){
            if(set.contains(arr[i])){
                return true;
            }
            else{
                set.add(arr[i]);
            }
            if(i>=k){
                set.remove(arr[i-k]);
            }
        }
        return false;
    }
}