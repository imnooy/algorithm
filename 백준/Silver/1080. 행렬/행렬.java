import java.util.*;
import java.io.*;


public class Main
{
    static int n, m;
    static boolean[][]a, b;
    static void swap(int x, int y) {
        for(int i = x; i <= x + 2; i++) {
            for(int j = y; j <= y + 2; j++) {
                a[i][j] = !a[i][j];
            }
        }
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        a = new boolean[n][m];
        b = new boolean[n][m];
        int ans = 0;

        for(int i = 0; i < n; i++) {
            char[]ch = br.readLine().toCharArray();
            for(int j = 0; j < m; j++) {
                char c = ch[j];
                if(c == '0') a[i][j] = false;
                else a[i][j] = true;
            }
        }

        for(int i = 0; i < n; i++) {
            char[]ch = br.readLine().toCharArray();
            for(int j = 0; j < m; j++) {
                char c = ch[j];
                if(c == '0') b[i][j] = false;
                else b[i][j] = true;
            }
        }

        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                if(a[i][j] != b[i][j]) {
                    swap(i, j);
                    ans ++;
                }
            }
        }

        boolean isPossible = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] != b[i][j]) {
                    isPossible = false;
                    break;
                }
            }
        }

        if(isPossible) System.out.println(ans);
        else System.out.println(-1);
    }
}