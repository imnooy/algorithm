import java.util.*;
import java.io.*;


public class Main
{
    static int[]arr;
    static int n;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        arr=new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            arr[i]=Integer.parseInt(st.nextToken());
        }

        int left = 0;
        int right = n-1;
        int sum=Integer.MAX_VALUE; //0과의 차이 최솟값

        int aleft = 0;
        int aright = 0;

        while(left < right) {
            if(Math.abs(arr[left]+arr[right])<sum) {
                aleft=arr[left];
                aright=arr[right];
                sum=Math.abs(arr[left]+arr[right]);
            }

            int moveRight = Math.abs(arr[left]+arr[right-1]);
            int moveLeft = Math.abs(arr[left+1]+arr[right]);

            if(moveLeft < moveRight) {
                left++;
            }
            else right--;
        }

        System.out.println(aleft+" "+aright);
    }
}