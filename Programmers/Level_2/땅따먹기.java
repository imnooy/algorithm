import java.util.*;

class Solution {
    int solution(int[][] land) {
        int answer = 0;

        int n=land.length;
        int[][]dp=new int[n][4];
        //dp에 저장되는 값 : 각 행의 각 열에서 얻을 수 있는 최댓값
        
        for(int i=0; i<4; i++) {
            dp[0][i]=land[0][i];
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<4; j++) { //이 열 밟는다
                for(int k=0; k<4; k++) { //전에 밟은 것들 보기..
                    if(j==k) continue;
                    dp[i][j]=Math.max(dp[i-1][k]+land[i][j], dp[i][j]);
                }
            }
        }
        
        for(int i=0; i<4; i++) {
            answer=Math.max(dp[n-1][i], answer);
        }

        return answer;
    }
}
