//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String A = br.readLine().trim();
            Solution ob = new Solution();
            String ans = ob.FirstNonRepeating(A);
            out.println(ans);
        }
        out.close();
    }
}

// } Driver Code Ends


class Solution
{
    public String FirstNonRepeating(String A)
    {
        HashMap<Character,Integer> map = new HashMap<>();
        Queue<Character> q = new LinkedList<>();
        
        StringBuilder ans = new StringBuilder();
        
        for(int i=0;i<A.length();i++){
            char ch = A.charAt(i);
            map.put(ch,map.getOrDefault(ch,0)+1);
            
            q.add(ch);
            
            while(!q.isEmpty()){
                if(map.get(q.peek())>1){
                    q.poll();
                }
                else{
                    ans.append(q.peek());
                    break;
                }
            }
            if(q.isEmpty()){
                ans.append('#');
            }
        }
        
        
        return ans.toString();
        
    }
}