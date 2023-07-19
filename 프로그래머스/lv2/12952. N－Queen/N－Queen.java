import java.util.*;

class Solution {
    public boolean[][] isused;
    public int ans;
    public Map<String, Boolean> map;
    
    public boolean isPossible(int x, int y, int n) {
        //가로
        for(int j = 0; j < n; j++) {
            if(isused[x][j]) return false;
        }
        
        //세로
        for(int i = 0; i < n; i++) {
            if(isused[i][y]) return false;
        }
        
        //대각선
        int xyDiff = x - y;
        int xySum = x + y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int ijDiff = i - j;
                int ijSum = i + j;
                
                if(ijDiff == xyDiff && isused[i][j]) return false;
                if(xySum == ijSum && isused[i][j]) return false;
            }
        }
        return true;
    }
    
    public void func(int k, int n) {
        if(k == n) {
            String str = "";
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(!isused[i][j]) continue;
                    str += (i + j + " ");
                }
            }
            if(map.containsKey(str)) return;
            map.put(str, true);
            ans++;
            return;
        }
        
        for(int j = 0; j < n; j++) {
            if(isused[k][j]) continue;
            if(!isPossible(k, j, n)) continue;

            isused[k][j] = true;
            func(k + 1, n);
            isused[k][j] = false;
        }
    }
    
    public void debug(int n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                System.out.print(isused[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
    
    
    public int solution(int n) {
        int answer = 0;
        ans = 0;
        map = new HashMap<>();
        isused = new boolean[n][n];
        func(0, n);
        return ans;
    }
}