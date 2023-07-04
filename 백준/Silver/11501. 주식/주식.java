import java.util.*;
import java.io.*;


public class Main
{
    static int T, n;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for(int t=1; t<=T; t++) {
            n=Integer.parseInt(br.readLine());
            long answer = 0;
            int[]arr=new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=0; i<n; i++) {
                int num = Integer.parseInt(st.nextToken());
                arr[i]=num;
            }
            int max = 0;
            for(int i=n-1; i>=0; i--) {
                int num=arr[i];
                if(max<arr[i]) {
                    max=arr[i];
                }
                else {
                    answer+=(max-arr[i]);
                }
            }
            System.out.println(answer);
        }
    }
}