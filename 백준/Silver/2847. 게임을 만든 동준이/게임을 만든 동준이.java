import java.util.*;
import java.io.*;


public class Main
{
    static int n;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n=Integer.parseInt(br.readLine());
        int[] arr=new int[n];
        long answer=0;
        for(int i=0; i<n; i++) {
            int num = Integer.parseInt(br.readLine());
            arr[i]=num;
        }

        for(int i=n-2; i>=0; i--) {
            if(arr[i]>=arr[i+1]) {
                int diff = arr[i+1]-1;
                answer+=(arr[i]-diff);
                arr[i]=diff;
            }
        }
        System.out.println(answer);
    }
}