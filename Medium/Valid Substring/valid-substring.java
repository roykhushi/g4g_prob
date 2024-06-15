//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();

            Solution ob = new Solution();
            System.out.println(ob.findMaxLen(S));
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    static int findMaxLen(String S) {
        // code here
            Stack<Integer> st =  new Stack<>();
            int count = 0;
            
            st.push(-1);
            
            for(int i=0;i<S.length();i++){
                if(S.charAt(i) == '('){
                    st.push(i);
                }
                else{
                    if(!st.empty()){
                        st.pop();
                    }
                    
                    if(st.empty()){
                        st.push(i);
                    }
                    count = Math.max(count,i-st.peek());
                }
            }
            return count;
    }
}