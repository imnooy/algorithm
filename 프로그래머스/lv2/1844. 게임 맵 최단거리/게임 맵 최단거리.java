import java.util.*;

class Solution {
    static class Pair {
        int x;
        int y;
        
        Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }
    }
    
    public int[]dx=new int[]{-1, 0, 1, 0};
    public int[]dy=new int[]{0, 1, 0, -1};
    
    public int bfs(int[][]maps) {
        int[][]dis=new int[maps.length][maps[0].length];
        Queue<Pair> q = new ArrayDeque<>();
        int n=maps.length;
        int m=maps[0].length;
        
        dis[0][0]=1;
        q.add(new Pair(0, 0));
        
        while(!q.isEmpty()) {
            Pair p=q.poll();
            for(int d=0; d<4; d++) {
                int nx=p.x+dx[d];
                int ny=p.y+dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(dis[nx][ny]>0) continue;
                if(maps[nx][ny]==0) continue;
                if(nx==n-1 && ny==m-1) return dis[p.x][p.y]+1;
                dis[nx][ny]=dis[p.x][p.y]+1;
                q.add(new Pair(nx, ny));
            }
        }
        return -1;
    }
    public int solution(int[][] maps) {
        int answer = 0;
        return bfs(maps);
    }
}