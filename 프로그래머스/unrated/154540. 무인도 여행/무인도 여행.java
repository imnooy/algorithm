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
    public boolean[][]visited;
    public char[][]arr;
    public List<Integer> list;
    
    public int[]dx=new int[]{-1, 0, 1, 0};
    public int[]dy=new int[]{0, 1, 0, -1};
    
    public int n, m;
    
    public void bfs(int x, int y) {
        Queue<Pair> q=new ArrayDeque<>();
        visited[x][y]=true;
        q.add(new Pair(x, y));
        int sum=0;
        sum+=(arr[x][y]-'0');
        while(!q.isEmpty()) {
            Pair p = q.poll();
            for(int d=0; d<4; d++) {
                int nx=p.x+dx[d];
                int ny=p.y+dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(visited[nx][ny]) continue;
                if(arr[nx][ny]=='X') continue;
                visited[nx][ny]=true;
                q.add(new Pair(nx, ny));
                sum+=(arr[nx][ny]-'0');
            }
        }
        if(sum==0) return;
        list.add(sum);
    }
    
    public int[] solution(String[] maps) {
        n=maps.length;
        m=maps[0].length();
        arr=new char[n][m];
        visited=new boolean[n][m];
        list=new ArrayList<>();
        for(int i=0; i<n; i++) {
            char[]ch=maps[i].toCharArray();
            for(int j=0; j<m; j++) {
                arr[i][j]=ch[j];
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(visited[i][j]) continue;
                if(arr[i][j]=='X') continue;
                bfs(i, j);
            }
        }
        
        if(list.size()==0) {
            int[] answer = new int[1];
            answer[0]=-1;
            return answer;
        }
        int[] answer = new int[list.size()];
        Collections.sort(list);
        for(int i=0; i<list.size(); i++) {
            answer[i]=list.get(i);
        }
        return answer;
    }
}