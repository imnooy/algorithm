import java.util.*;
import java.io.*;


public class Main
{
    static int n;
    static long x;
    static long[]dp;

    static long func(int nn, long xx) {
        if(xx == 0) return 0; //다 먹음
        if(nn == 0) return 1; //레벨 0버거
        

        if(dp[nn] < xx) { //중간 패티보다 더 먹음
            return dp[nn-1]+func(nn-1, xx-dp[nn])+1;
        }
        if(dp[nn] == xx) return dp[nn-1]+1; //중간 패티까지 먹음
        
        return func(nn-1, xx-1); //중간 패티보다 조금 먹음
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        x = Long.parseLong(st.nextToken());
        dp = new long[n+1];

        dp[0] = 1; //레벨 0 패티 1장
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] * 2 + 1; //패티 개수 저장
        }

        System.out.println(func(n, x));
    }
}