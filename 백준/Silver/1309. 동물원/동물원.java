import java.util.*;
import java.io.*;


public class Main
{
    static int n;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 1];
        // dp[1] = 3; // 1 + 2
        // dp[2] = 7; // 1 + 4 + 2 (0마리, 1마리, 2마리)
        // dp[3] = 17;// 1 + 6 + 8 + 2 (0마리, 1마리, 2마리, 3마리)
        // dp[4] = 41;// 1 + 8 + 18 + 12 + 2 (0마리, 1마리, 2마리, 3마리, 4마리)

        dp[1] = 3;
        if(n > 1) dp[2] = 7;
        for(int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
        }
        System.out.println(dp[n]);
    }
}