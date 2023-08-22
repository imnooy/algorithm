import java.util.*;
import java.io.*;


public class Main
{
    static int n, p;
    static Stack[]sts;

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stt = new StringTokenizer(br.readLine());
        n = Integer.parseInt(stt.nextToken());
        p = Integer.parseInt(stt.nextToken());

        sts = new Stack[7];
        for(int i = 1; i <= 6; i++) sts[i] = new Stack<Integer>();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            stt = new StringTokenizer(br.readLine());
            int line = Integer.parseInt(stt.nextToken());
            int pret = Integer.parseInt(stt.nextToken());
            Stack<Integer> st = sts[line];
            
            if((!st.isEmpty() && st.peek() < pret) || st.isEmpty()) {
                st.push(pret);
                ans++;
            }
            else {
                if(st.peek() == pret) continue;
                else if(st.peek() > pret) {
                    while(true) {
                        if(st.isEmpty() || st.peek() <= pret) {
                            break;
                        }
                        st.pop();
                        ans++;
                    }
                    if(st.isEmpty() || (!st.isEmpty() && st.peek() != pret)) {
                        ans++;
                        st.push(pret);
                    }
                }
            }
        }
        System.out.println(ans);
    }
}