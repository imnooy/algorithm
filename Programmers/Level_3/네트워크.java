import java.util.*;

class Solution {
    
    public boolean[] visited;
    public List<Integer>[] adj;
    
    public void dfs(int start) {
        for(int i=0; i<adj[start].size(); i++) {
            int j=adj[start].get(i);
            if(visited[j]) continue;
            visited[j]=true;
            dfs(j);
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited=new boolean[n];
        adj=new ArrayList[n];
        
        for(int i=0; i<n; i++) {
            adj[i]=new ArrayList<>();
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(computers[i][j]==1) adj[i].add(j);
            }
        }
        
        for(int i=0; i<n; i++) {
            if(visited[i]) continue;
            answer++;
            dfs(i);
        }
        
        return answer;
    }
}
