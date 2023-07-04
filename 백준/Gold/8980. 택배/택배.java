import java.util.*;
import java.io.*;


public class Main
{
    static class Pair implements Comparable<Pair> {
        int from;
        int to;
        int box;

        Pair(int from, int to, int box) {
            this.from = from;
            this.to = to;
            this.box = box;
        }

        @Override
        public int compareTo(Pair p) {
            int ans = this.to - p.to;
            if(ans == 0) return this.from - p.from;
            return ans;
        }
    }

    static int n, c, m;
    static PriorityQueue<Pair> pq;
    static int[] boxes;
    static boolean[] comp;

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        pq = new PriorityQueue<>();
        boxes = new int[n+1]; //i번째까지 배달할 수 있는 박스 수

        m = Integer.parseInt(br.readLine());
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            Pair p = new Pair(a, b, c);
            pq.add(p);
        }

        for(int i = 1; i <= n; i++) boxes[i] = c;
        
        int ans = 0;
        while(!pq.isEmpty()) {
            Pair p = pq.poll();

            int maxBox = c;
            for(int i = p.from; i < p.to; i++) {
                maxBox = Math.min(maxBox, boxes[i]);
            }

            maxBox = Math.min(maxBox, p.box);
            for(int i = p.from; i < p.to; i++) {
                boxes[i] -= maxBox;
            }
            ans += maxBox;
        }
        

        System.out.println(ans);

    }
}