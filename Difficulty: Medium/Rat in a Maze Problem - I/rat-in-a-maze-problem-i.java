//{ Driver Code Starts
// Initial Template for Java

import java.util.*;

class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}

// } Driver Code Ends


class Solution {
    public ArrayList<String> findPath(int[][] mat) {
        // Your code here
        ArrayList<String> res = new ArrayList<>();
        recurse(mat,0,0,"",res);
        return res;
    }
    public static void recurse(int[][] mat, int r, int c, String res, ArrayList<String> ans){
        int rows = mat.length;
        int cols = mat[0].length;
        if(r == rows-1 && c == cols-1 && mat[r][c] == 1){
            ans.add(res);
            return;
        }
        if(r<0 || r>=rows || c<0 || c>=cols){
            return;
        }
        
        if(mat[r][c] == 0 || mat[r][c] == -1){
            return;
        }
        mat[r][c] = -1;
        
        recurse(mat,r-1,c,res+"U",ans);
        recurse(mat,r+1,c,res+"D",ans);
        recurse(mat,r,c-1,res+"L",ans);
        recurse(mat,r,c+1,res+"R",ans);
        
        mat[r][c] = 1;
        
    }
}