import java.util.*;
import java.io.*;


public class Main
{
    static class Pair implements Comparable<Pair> {
        int x;
        int y;

        Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }

        @Override
        public int compareTo(Pair p) {
            int ans=this.x-p.x;
            if(ans==0) return this.y-p.y;
            return ans;
        }
    }
    static int n, s, t;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                int ans = p1.y-p2.y;
                if(ans==0) return p1.x-p2.x;
                return ans;
            }
        });
        List<Pair> list = new ArrayList<>();

        for(int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            Pair p = new Pair(a, b);
            list.add(p);
        }

        Collections.sort(list);

        for(int i=0; i<n; i++) {
            Pair p = list.get(i);
            if(!pq.isEmpty()) {
                Pair top = pq.peek();
                if(top.y <= p.x) pq.poll();
            }
            pq.add(p);
        }

        System.out.println(pq.size());
    }
}