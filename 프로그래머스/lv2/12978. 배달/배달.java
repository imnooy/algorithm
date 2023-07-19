import java.util.*;

class Solution {
    static class Pair {
        int n;
        int time;
        
        Pair(int n, int time) {
            this.n = n;
            this.time = time;
        }
    }
    
    public void bfs(int n, int k) {
        isused[1] = 0; //1번 마을에서 배달 시작
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(1, 0));
        
        while(!q.isEmpty()) {
            Pair p = q.poll();
            
            for(int j = 1; j <= n; j++) {
                if(adj[p.n][j] == 0) continue;
                int time = adj[p.n][j] + p.time;
                if(isused[j] > 0 && isused[j] < time) continue;
                if(time > k) continue;
                
                
                isused[j] = time;
                q.add(new Pair(j, time));
            }
        }
    }
    
    public int[][] adj;
    public int[] isused;
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        isused = new int[N + 1];
        adj = new int[N + 1][N + 1];
        
        for(int i = 0; i < road.length; i++) {
            int n1 = road[i][0];
            int n2 = road[i][1];
            int time = road[i][2];
            
            adj[n1][n2] = adj[n1][n2] == 0 ? time : Math.min(adj[n1][n2], time);
            adj[n2][n1] = adj[n2][n1] == 0 ? time : Math.min(adj[n2][n1], time);
        }
        
        bfs(N, K);
        
        for(int i = 1; i <= N; i++) {
            if(isused[i] > 0) answer++;
        }
        
        if(isused[1] == 0) answer++;

        return answer;
    }
}