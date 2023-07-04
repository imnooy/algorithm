import java.util.*;
import java.io.*;


public class Main
{
    static int n, m;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        PriorityQueue<Long> pq = new PriorityQueue<>();

        st=new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            long num=Long.parseLong(st.nextToken());
            pq.add(num);
        }

        for(int i=0; i<m; i++) {
            long a = pq.poll();
            long b = pq.poll();
            a+=b;

            pq.add(a);
            pq.add(a);
        }

        long sum=0;
        while(!pq.isEmpty()) {
            sum+=pq.poll();
        }

        System.out.println(sum);

    }
}