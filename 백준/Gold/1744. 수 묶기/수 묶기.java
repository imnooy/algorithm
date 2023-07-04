import java.util.*;
import java.io.*;


public class Main
{
    static int n;
    static List<Integer> plus;
    static List<Integer> minus;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        plus = new ArrayList<>();
        minus = new ArrayList<>();

        n=Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) {
            int num = Integer.parseInt(br.readLine());
            if(num>=0) plus.add(num);
            else minus.add(num);
        }
        Collections.sort(plus);
        Collections.sort(minus, new Comparator<Integer>() {
            @Override
            public int compare(Integer m1, Integer m2) {
                return m2-m1;
            }
        });

        long answer=0;
        
        int plusIndex = plus.size()-1;
        int minusIndex = minus.size()-1;

        while(plusIndex>=1) {
            int n1 = plus.get(plusIndex);
            int n2 = plus.get(plusIndex-1);
            if(n2==0) {
                answer+=n1;
                plusIndex--;
                continue;
            }
            else if(n2==1) {
                answer+=n1;
                answer+=n2;
            }
            else answer+=(n1*n2);
            plusIndex-=2;
        }

        while(minusIndex>=1) {
            int n1 = minus.get(minusIndex);
            int n2 = minus.get(minusIndex-1);
            answer+=(n1*n2);
            minusIndex-=2;
        }

        if(plusIndex==0) {
            if(minusIndex==0) {
                if(plus.get(0)!=0) {
                    answer+=plus.get(0);
                    answer+=minus.get(0);
                }
            }
            else {
                answer+=plus.get(0);
            }
        }
        else if(minusIndex==0) {
            answer+=minus.get(0);
        }
        System.out.println(answer);
    }
}