import java.util.*;
import java.io.*;


public class Main
{
    static int n;
    static int[][]work;
    static int[][]moveTo;
    static int lastA, lastB;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        work=new int[2][n+1];
        moveTo=new int[2][n+1];

        for(int i=1; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int aTime = Integer.parseInt(st.nextToken());
            int bTime = Integer.parseInt(st.nextToken());
            int aTob = Integer.parseInt(st.nextToken());
            int bToa = Integer.parseInt(st.nextToken());

            work[0][i]=aTime;
            moveTo[0][i]=aTob;
            work[1][i]=bTime;
            moveTo[1][i]=bToa;
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        lastA = Integer.parseInt(st.nextToken());
        lastB = Integer.parseInt(st.nextToken());

        //저장되는 값 : 0번째에서 i개까지 조립할 때 최소 시간
        //저장되는 값 : 1번째에서 i개까지 조립할 때 최소 시간이답.
        int dp[][]=new int[2][n+1];

        dp[0][1]=work[0][1];
        dp[1][1]=work[1][1]; 

        for(int i=2; i<n; i++) {
            dp[0][i]=Math.min(dp[1][i-1]+moveTo[1][i-1]+work[0][i], dp[0][i-1]+work[0][i]);
            dp[1][i]=Math.min(dp[0][i-1]+moveTo[0][i-1]+work[1][i], dp[1][i-1]+work[1][i]);
        }

        dp[0][n]=Math.min(dp[0][n-1]+lastA, dp[1][n-1]+moveTo[1][n-1]+lastA);
        dp[1][n]=Math.min(dp[1][n-1]+lastB, dp[0][n-1]+moveTo[0][n-1]+lastB);

        System.out.println(Math.min(dp[0][n], dp[1][n]));
    }
}
