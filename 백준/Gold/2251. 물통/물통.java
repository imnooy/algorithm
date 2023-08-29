import java.util.*;
import java.io.*;


public class Main
{
    static class Pair {
        int x;
        int y;
        int z;

        Pair(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        @Override
        public boolean equals(Object o) {
            Pair p = (Pair) o;
            if(p.x == this.x && p.y == this.y && p.z == this.z)
                return true;
            return false;
        }

        @Override
        public int hashCode() {
            return 0;
        }
    }
    static Set<Integer> ans;
    static Set<Pair> set;
    static int a, b, c;

    public static void drink(int x, int y, int z) {
        Pair p = new Pair(x, y, z);
        // System.out.println(x + " " + y + " " + z);
        if(set.contains(p)) return;
        if(x == 0) {
            ans.add(z);
        }
        set.add(p);
        if(x > 0) { //x를 다른 곳에 부어라
            if(x + y <= b) { //y에 부어라
                drink(0, x + y, z);
            }
            else {
                drink((x + y - b), b, z);
            }

            if(x + z <= c) { //z에 부어라
                drink(0, y, x + z);
            }
            else {
                drink((x + z - c), y, c);
            }
        }
        if(y > 0) { //y를 다른 곳에 부어라
            if(y + x <= a) { //x에 부어라
                drink(y + x, 0, z);
            }
            else {
                drink(a, (y + x - a), z);
            }

            if(y + z <= c) { //z에 부어라
                drink(x, 0, y + z);
            }
            else {
                drink(x, (y + z - c), c);
            }
        }

        if(z > 0) { //z를 다른 곳에 부어라
            if(z + x <= a) { //x에 부어라
                drink(z + x, y, 0);
            }
            else {
                drink(a, y, (z + x - a));
            }

            if(z + y <= b) { //y에 부어라
                drink(x, z + y, 0);
            }
            else {
                drink(x, b, (z + y - b));
            }
        }
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        ans = new TreeSet<>();
        set = new HashSet<>();

        drink(0, 0, c);
        StringBuilder sb = new StringBuilder();
        for(int num : ans) {
            sb.append(num + " ");
        }
        System.out.println(sb);
    }
}