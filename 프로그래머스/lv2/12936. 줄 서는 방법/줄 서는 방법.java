import java.util.*;

class Solution {
    public int[] solution(int n, long k) {
        int[] answer = new int[n];
        long[]fac=new long[n+1];
        boolean[]isused=new boolean[n];
        fac[0]=1;
        for(int i=1; i<=n; i++) {
            fac[i]=i*fac[i-1];
        }
        
        int nn=n;
        
        int index=0;
        int num;
        while(index<n) {
            
            long f = fac[nn];
            long fDiv = f / nn;
            long div = k/fDiv;
            long mod = k%fDiv;
            if(mod>0) div++;

            int cnt=0;
            for(int i=0; i<n; i++) {
                if(isused[i]) continue;
                cnt++;
                if(cnt==div) {
                    isused[i]=true;
                    answer[index++]=i+1;
                    break;
                }
            }
            
            nn--;
            k=mod==0? fac[nn]:mod;
        }
        
        return answer;
    }
}