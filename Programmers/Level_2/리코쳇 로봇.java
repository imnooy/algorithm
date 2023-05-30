import java.util.*;

public class Pair {
    int x;
    int y;
    Pair(int x, int y) {
        this.x=x;
        this.y=y;
    }
}

class Solution {
    public char[][]arr;
    public int[]dx=new int[]{-1, 0, 1, 0};
    public int[]dy=new int[]{0, 1, 0, -1};
    public Pair start;
    public Pair end;
    public int ans;
    public int[][]dis;
    public int r, c;
    
    public Pair next(int x, int y, int d) {
        int nx=x;
        int ny=y;
        while(nx>=0 && nx<r && ny>=0 && ny<c && arr[nx][ny]!='D') {
            nx+=dx[d];
            ny+=dy[d];
        }
        return new Pair(nx-dx[d], ny-dy[d]);
    }
    
    public void bfs() {
        Queue<Pair> q=new ArrayDeque<>();
        dis[start.x][start.y]=1;
        q.add(start);
        
        while(!q.isEmpty()) {
            Pair p = q.poll();
            
            for(int d=0; d<4; d++) {
                Pair np=next(p.x, p.y, d);
                int nx=np.x;
                int ny=np.y;
                if(dis[nx][ny]>0) continue;
                
                if(nx==end.x && ny==end.y) {
                    ans=dis[p.x][p.y];
                    return;
                }
                dis[nx][ny]=dis[p.x][p.y]+1;
                q.add(new Pair(nx, ny));
            }
        }
    }
    
    public int solution(String[] board) {
        int answer = 0;
        ans=-1;
        r=board.length;
        c=board[0].length();
        arr=new char[r][c];
        dis=new int[r][c];
        for(int i=0; i<r; i++) {
            arr[i]=board[i].toCharArray();
            for(int j=0; j<c; j++) {
                if(arr[i][j]=='R') {
                    start=new Pair(i, j);
                }
                else if(arr[i][j]=='G') {
                    end=new Pair(i, j);
                }
            }
        }
        
        bfs();
        return ans;
    }
}
