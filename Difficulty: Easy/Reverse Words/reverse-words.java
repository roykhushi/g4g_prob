//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            String s = sc.next();
            Solution obj = new Solution();
            System.out.println(obj.reverseWords(s));
            t--;
        }
    }
}

// } Driver Code Ends



class Solution {
    // Function to reverse words in a given string.
    String reverseWords(String S) {
        // code here
        String []str = S.split("\\.");
        String rev = "";
        for(int i=str.length-1;i>=0;i--){
            rev += str[i] + " ";
        }
       rev = rev.trim(); //aage peeche ke spaces hata dega
       rev = rev.replace(" ",".");
       return rev;
    }
}