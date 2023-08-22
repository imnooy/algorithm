import java.util.*;
import java.io.*;


public class Main
{
    static int n, m;
    static int[][]adj;
    static int a, b, c;

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        adj = new int[n+1][n+1];
        for(int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j++) {
                adj[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    adj[j][k] = Math.min(adj[j][i] + adj[i][k], adj[j][k]);
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            if(adj[a][b] <=c) {
                sb.append("Enjoy other party").append("\n");
            }
            else {
                sb.append("Stay here").append("\n");
            }
        }
        System.out.println(sb);
    }
}