import java.util.*;
import java.io.*;


public class Main
{
    static long a, b;
    static int bIndex;
    static List<Integer> list;
    static Set<Long> set;
    static boolean[] check;
    
    static void find() {
        for(int i=2; i<=(int)Math.sqrt(bIndex); i++) {
            if(!check[i]) continue;
            for(int j=i*2; j<=bIndex; j+=i) {
                check[j]=false;
            }
        }

        for(int i=2; i<=bIndex; i++) if(check[i]) list.add(i);
    }

    static void count() {
        for(long num : list) {
            long tmp = num*num;
            while(tmp<=b) {
                if(a<=tmp) set.add(tmp);
                if(tmp > Long.MAX_VALUE / num) break;
                tmp*=num;
            }
        }
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());
        bIndex = (int)Math.sqrt(b);

        list = new ArrayList<>();
        set = new HashSet<>();
        
        check = new boolean[bIndex+1];

        for(int i=1; i<=bIndex; i++) check[i]=true; //전처리

        find();

        // for(int num : list) System.out.print(num+" ");
        // System.out.println();
        
        count();

        System.out.println(set.size());
    }
}