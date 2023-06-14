import java.util.*;
import java.io.*;


public class Main
{
    static int n, m;
    static int[]arr;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        arr=new int[101];

        int before = 1;
        for(int i=0; i<n; i++) {
            st=new StringTokenizer(br.readLine());
            int end = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());

            arr[before]=speed;
            before+=end;
        }

        int index=1; //현재 보고 있는 인덱스
        int cur = arr[index];
        for(int i=1; i<=100; i++) { //
            if(arr[i]==0) {
                arr[i]=cur;
            }
            else if(arr[i]!=cur) {
                cur=arr[i];
            }
        }
        
        // for(int i=1; i<=100; i++) {
        //     System.out.print(arr[i]+" ");
        // }

        st=new StringTokenizer(br.readLine());
        int end=Integer.parseInt(st.nextToken());
        int speed=Integer.parseInt(st.nextToken());
        cur=1; //현재 위치
        int ans=0;

        while(cur<=100) {
            if(cur>end) {
                st=new StringTokenizer(br.readLine());
                end+=Integer.parseInt(st.nextToken());
                speed=Integer.parseInt(st.nextToken());
            }
            ans=Math.max(ans, speed-arr[cur]);
            cur++;
        }
        System.out.println(ans);
    }
}
