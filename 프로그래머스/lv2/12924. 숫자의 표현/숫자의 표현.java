class Solution {
    public int solution(int n) {
        int answer = 0;
        int[]dp=new int[n+1]; //i를 표현하는 방법의 수
        
        for(int i=1; i<=n; i++) {
            dp[i]=1;
        }
        for(int i=1; i<=n; i++) {
            int index=i;
            for(int j=i-1; j>=1; j--) {
                index+=j;
                if(index>n) break;
                dp[index]++;
            }
        }
        return dp[n];
    }
}