//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str = read.readLine().trim();
            String ans = ob.compareFrac(str);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {

    String compareFrac(String str) {
        String[] total_arr = str.split(", ");
        
        String[] frac1 = total_arr[0].split("/");
        double n1 = Double.parseDouble(frac1[0]);
        double d1 = Double.parseDouble(frac1[1]);
        
        String[] frac2 = total_arr[1].split("/");
        double n2 = Double.parseDouble(frac2[0]);
        double d2 = Double.parseDouble(frac2[1]);
        
        double ans1 = (n1/d1);
        double ans2 = (n2/d2);
        
        if(ans1>ans2){
            return total_arr[0];
        }
        else if(ans1<ans2){
            return total_arr[1];
        }
        return "equal";
    }
}
