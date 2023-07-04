import java.util.*;
import java.io.*;


public class Main
{
    static int n, k;
    static int[] arr; //입력받은 k개의 수
    static int[] lastIndex;
    static boolean[] isused; //쓰고 있는지
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        arr = new int[k + 1];
        isused = new boolean[k + 1];
        lastIndex = new int[k + 1];

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= k; i++) {
            int num = Integer.parseInt(st.nextToken());
            arr[i] = num;
            lastIndex[num] = 101; //나온 수라는 거 표시
        }

        int count = 0;
        int index = 1;
        for(int i = 1; i <= k; i++) {
            int num = arr[i];
            if(isused[num]) continue;
            index = i;
            count++;
            isused[num] = true;
            if(count == n) break;
        }

        int ans = 0;
        for(int i = index + 1; i <= k; i++) {
            int num = arr[i]; //num이 들어가야 함
            if(isused[num]) continue;
            //현재 꽂혀있는 num들 중 가장 나중에 사용되거나 사용되지 않는 기기를 찾자
            for(int j = i + 1; j <= k; j++) {
                if(lastIndex[arr[j]] != 101) continue;
                lastIndex[arr[j]] = j;
            }

            int pick = 0;
            boolean notUse = false;
            for(int j = 1; j <= k; j++) {
                if(!isused[j]) continue;
                if(lastIndex[j] == 101) {
                    pick = j;
                    notUse = true;
                    break;
                }
            }

            //최대한 나중에 사용되는 거 찾기
            if(!notUse) {
                int in = i;
                for(int j = 1; j <= k; j++) {
                    if(!isused[j]) continue;
                    if(in < lastIndex[j]) {
                        in = lastIndex[j];
                        pick = j;
                    }
                }
            }

            isused[pick] = false;
            ans++;
            isused[num] = true;

            for(int j = i + 1; j <= k; j++) {
                lastIndex[arr[j]] = 101; //복구
            }
        }

        System.out.println(ans);
    }
}