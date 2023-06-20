import java.util.*;

class Solution {
    public int[]arr;
    public int solution(int storey) {
        int answer = 0;
        int cnt=0;
        for(int i=1; i<=storey; i*=10) {
            cnt++;
        }
        arr=new int[cnt+2];
        String str = String.valueOf(storey);
        int index=1;
        int strIndex = str.length();
        while(strIndex-->0) {
            arr[index]=Integer.parseInt(str.substring(strIndex, strIndex+1));
            index++;
        }
        
        for(int i=1; i<=cnt+1; i++) {
            int num = arr[i];
            // System.out.print(num+" ");
            if(i<=cnt && arr[i+1]>=5 && arr[i]>=5) {
                answer+=(10-arr[i]);
                arr[i+1]++;
            }
            else if(i==cnt+1 || arr[i]<=5)  { //- 하자
                answer+=arr[i];
            }
            else {
                answer+=(10-arr[i]);
                arr[i+1]++;
            }
        }
        
        return answer;
    }
}