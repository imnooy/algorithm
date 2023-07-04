import java.util.*;
import java.io.*;


public class Main
{
    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }
    }

    static int n, x, y;

    static boolean isRange(Pair p1, Pair p2) {
        if(p1.x<=p2.x && p2.x<=p1.y) return true;
        return false;
    }
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                int ans=p2.y-p1.y;
                if(ans==0) return p1.x-p2.x;
                return ans;
            }
        });
        List<Pair> list = new ArrayList<>();
        n=Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x=Integer.parseInt(st.nextToken());
            y=Integer.parseInt(st.nextToken());

            Pair p = new Pair(x, y);
            list.add(p);
        }

        Collections.sort(list, new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                int ans=p1.x-p2.x;
                if(ans==0) return p1.y-p2.y;
                return ans;
            }
        });

        for(Pair p : list) {
            if(pq.isEmpty()) {
                pq.add(p);
            }
            else {
                Pair top = pq.poll();
                if(isRange(top, p)) { //시작점이 범위에 들어감
                    if(top.y<p.y) { //범위 연장 가능
                        top.y=p.y;
                    }
                }
                else {
                    pq.add(p);
                }
                pq.add(top);
            }
        }

        int sum=0;
        while(!pq.isEmpty()) {
            Pair p = pq.poll();
            sum+=(p.y-p.x);
        }

        System.out.println(sum);
    }
}