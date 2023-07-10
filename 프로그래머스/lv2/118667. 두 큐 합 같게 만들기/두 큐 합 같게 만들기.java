import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = -1;
        long asum=0;
        long bsum=0;
        Queue<Long> q1=new ArrayDeque<>();
        Queue<Long> q2=new ArrayDeque<>();
        for(long num : queue1) {
            asum+=num;
            q1.add(num);
        }
        for(long num : queue2) {
            bsum+=num;
            q2.add(num);
        }
        
        if((asum+bsum)%2==1) return -1;
        
        int cnt=0;
        while(!q1.isEmpty() && !q2.isEmpty()) {
            if(asum==bsum) {
                return cnt;
            }
            if(asum<bsum) {
                long num=q2.poll();
                q1.add(num);
                bsum-=num;
                asum+=num;
            }
            else {
                long num=q1.poll();
                q2.add(num);
                asum-=num;
                bsum+=num;
            }
            cnt++;
            if(cnt>600000) return -1;
        }
        return answer;
    }
}