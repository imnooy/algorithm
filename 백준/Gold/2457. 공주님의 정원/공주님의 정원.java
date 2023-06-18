import java.util.*;
import java.io.*;


public class Main
{
    static class Flower implements Comparable<Flower> {
        int start;
        int end;

        Flower(int start, int end) {
            this.start=start;
            this.end=end;
        }

        @Override
        public int compareTo(Flower f) {
            int ans=this.start-f.start;
            if(ans==0) return this.end-f.end;
            return ans;
        }
    }

    static int n;
    static List<Flower> list;
    static boolean isPossible(Flower f, int day) {
        if(f.start<=day && day<f.end) return true;
        return false;
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        list=new ArrayList<>();

        for(int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            Flower f = new Flower(a*100+b, c*100+d);
            if(f.start>=1201) continue;
            if(f.end<301) continue;
            list.add(f);
        }

        Collections.sort(list);

        int cur=301;
        int before=-1;
        int cnt=0;

        for(int i=0; i<n; i++) {
            Flower f = list.get(i);
            if(before!=-1 && isPossible(f, before) && cur<f.end) {
                cur=f.end;
            }
            else if((before==-1 && isPossible(f, 301)) || isPossible(f, cur)) {
                before=cur;
                cnt++;
                cur=f.end;
            }
            if(cur>=1201) break;
        }
        
        if(cur<=1130) cnt=0;
        System.out.println(cnt);
    }
}