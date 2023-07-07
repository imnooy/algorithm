import java.util.*;
import java.io.*;


public class Main
{
    static int m, n;
    static int[][]arr;
    static int[][]tmp;
    static int[][]indexes;

    static void find(int index, int i, int num) {
        int start = 0;
        int end = n;
        int mid = (start+end)/2;

        while(start<end) {
            if(tmp[index][mid]<num) start=mid+1;
            else end=mid;
            mid=(start+end)/2;
        }
        indexes[index][i]=start;
    }
    
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m=Integer.parseInt(st.nextToken());
        n=Integer.parseInt(st.nextToken());

        arr=new int[m][n];
        tmp=new int[m][n];
        indexes=new int[m][n];

        for(int i=0; i<m; i++) {
            st=new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                arr[i][j]=Integer.parseInt(st.nextToken());
                tmp[i][j]=arr[i][j];
            }
        }

        for(int i=0; i<m; i++) {
            Arrays.sort(tmp[i]);
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                find(i, j, arr[i][j]);
            }
        }

        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         System.out.print(indexes[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=i+1; j<m; j++) {
                boolean isPossible = true;
                for(int k=0; k<n; k++) {
                    if(indexes[i][k]!=indexes[j][k]) {
                        isPossible = false;
                        break;
                    }
                }
                if(isPossible) ans++;
            }
        }

        System.out.println(ans);
    }
}