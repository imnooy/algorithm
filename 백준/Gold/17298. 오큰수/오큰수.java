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

    static int n;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        Stack<Pair> st=new Stack<>();
        int[]arr=new int[n];

        StringTokenizer stk = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            int num=Integer.parseInt(stk.nextToken());
            //스택 제일 위 원소의 오큰수일때
            while(!st.isEmpty()) {
                Pair p=st.peek();
                if(p.y>=num) break;
                arr[p.x]=num;
                st.pop();
            }
            st.push(new Pair(i, num));
        }

        StringBuffer sb=new StringBuffer();
        for(int i=0; i<n; i++) {
            if(arr[i]==0) sb.append(-1+" ");
            else sb.append(arr[i]+" ");
        }

        System.out.println(sb.toString());
    }
}