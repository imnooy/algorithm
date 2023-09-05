import java.util.*;
import java.io.*;


public class Main
{
    static int n, k;
    static int[]arr;

    static int dfs(int K, int num, int sum) {
        if(K == n) return num;
        int max = 0;
        max = Math.max(max, dfs(K + 1, num, 0)); //선택 안 함

        //현재 원소 선택
        if(arr[K] + sum >= k) { //누적합 k넘음
            //초과한 만큼 더하고 빼기, 누적합 초기화
            max = Math.max(max, dfs(K + 1, num + sum + arr[K] - k, 0));
        }
        //초과 안함 - 누적합에 더하고 계속 고
        else max = Math.max(max, dfs(K + 1, num, sum + arr[K]));
        return max;
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        arr = new int[n];

        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int ans = dfs(0, 0, 0);
        System.out.println(ans);
    }
}