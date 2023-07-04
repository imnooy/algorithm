import java.util.*;
import java.io.*;


public class Main
{
    static int n;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int[] dp = new int[n+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        int ans = 0;
        for(int i=0; i<n; i++) {
            int num = Integer.parseInt(st.nextToken());
            dp[num] = dp[num-1] + 1; //연속된 증가수열만..
            ans = Math.max(ans, dp[num]);
        }

        System.out.println(n-ans);
    }
}