class Solution {
    public int solution(int x, int y, int n) {
        int answer = 0;
        if(x==y) return 0;
        int[] dp = new int[3*y+1];
        //dp[i]=i를 만들기 위한 최소 연산 수
        for(int i=x; i<y; i++) {
            if(i!=x && dp[i]==0) continue;
            if(dp[i+n]==0) dp[i+n]=dp[i]+1;
            else dp[i+n]=Math.min(dp[i]+1, dp[i+n]);
            
            if(dp[2*i]==0) dp[2*i]=dp[i]+1;
            else dp[2*i]=Math.min(dp[i]+1, dp[2*i]);
            
            if(dp[3*i]==0) dp[3*i]=dp[i]+1;
            else dp[3*i]=Math.min(dp[i]+1, dp[3*i]);
        }
        if(dp[y]==0) return -1;
        return dp[y];
    }
}