import java.util.*;
import java.io.*;


public class Main
{
    static int n;
    static List<Long> list; //두 수 합 저장해라
    static long[] arr; //입력받은 수들 저장
    static long[] sum;

    static boolean find(long num) {
        int start = 0;
        int end = list.size();
        int mid = (start+end)/2;

        while(start<end) {
            // if(arr[mid]==num) return true;
            // if(arr[mid]<num) start = mid + 1; //오른쪽에 있음
            // else end = mid;
            // mid=(start+end)/2;

            if(list.get(mid)==num) return true;
            if(list.get(mid)<num) start = mid + 1; //오른쪽에 있음
            else end = mid;
            mid=(start+end)/2;
        }
        return false;
    }
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        arr=new long[n];
        sum=new long[n*n];
        list=new ArrayList<>();

        for(int i=0; i<n; i++) {
            arr[i]=Long.parseLong(br.readLine());
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                list.add(arr[i]+arr[j]);
            }
        }

        Arrays.sort(arr);
        Collections.sort(list);

        for(int k=n-1; k>=0; k--) {
            for(int z=n-1; z>=0; z--) {
                if(find(arr[k]-arr[z])) {
                    System.out.println(arr[k]);
                    return ;
                }
            }
        }
    }
}