//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            long a[] = new long[(int)(n)];
            // long getAnswer[] = new long[(int)(n)];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(inputLine[i]);
            }
            int k = Integer.parseInt(br.readLine().trim());
            
            Compute obj = new Compute();
            long answer[] = obj.printFirstNegativeInteger(a, n, k);
            int sz = answer.length;
            
            StringBuilder output = new StringBuilder();
            for(int i=0;i<sz;i++)
                output.append(answer[i]+" ");
            System.out.println(output);
            
        }
	}
}


// } Driver Code Ends


//User function Template for Java


class Compute {
    
    public long[] printFirstNegativeInteger(long A[], int N, int K)
    {
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        long[] ans = new long[N-K+1];
        ArrayList<Long> l = new ArrayList<>();
        
        //storing 1st k elems
        for(int i=0;i<K;i++){
            if(A[i] < 0){
                dq.offer(i);
            }
        }
        //storing ans of first k sized window
        
        if(dq.size() > 0){
            l.add(A[dq.peek()]);
        }
        else{
            l.add((long)0); 
        }
        
        //processing fore remaining windows
        for(int i=K;i<N;i++){
            //removal
            if(!dq.isEmpty() && (i-dq.peek()>=K)){
                dq.poll();
            }
            if(A[i] < 0){
                //addition
                dq.add(i);
            }
            //store ans
            if(dq.size() > 0){
                l.add(A[dq.peek()]);
            }
            else{
                l.add((long)0); 
            }
                
        }
        
        //storing elem in arrr
        int k = 0;
        for(int i=0;i<l.size();i++){
            ans[k++] = l.get(i);
        }
        return ans;
    }
}