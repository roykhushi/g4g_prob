//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String input_line[] = read.readLine().trim().split("\\s+");
            int n = Integer.parseInt(input_line[0]);
            String input_line1[] = read.readLine().trim().split("\\s+");
            int[][] a = new int[n][n];
            int c = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            String ans = ob.pattern(a);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public String pattern(int[][] arr) {
        // Code here
        
        //for row 
        int row = arr.length;
        int col = arr[0].length;
        
        for(int i=0;i<row;i++){
            int count = 0;
            int s = 0;
            int e = col-1;
            
            while(s<=e){
                if(arr[i][s] != arr[i][e]){
                    count = 1;
                    break;
                }
                s++;
                e--;
            }
            if(count == 0){
                String ans = Integer.toString(i)+" R";
                return ans;
            }
        }
        //for col
        
        for(int i=0;i<col;i++){
            int count = 0;
            int s = 0;
            int e = row-1;
            
            while(s<=e){
                if(arr[s][i] != arr[e][i]){
                    count = 1;
                    break;
                }
                s++;
                e--;
            }
            if(count == 0){
                String ans = Integer.toString(i)+" C";
                return ans;
            }
        }
        return Integer.toString(-1);
    }
}
