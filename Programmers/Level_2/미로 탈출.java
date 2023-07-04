import java.util.*;

class Solution {
    
    public class Pair {
        int x;
        int y;
        
        Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }
    }
    
    public char[][]arr;
    public Pair start;
    public Pair exit;
    public Pair lever;
    public int ans;
    public int row;
    public int col;
    public int []dx=new int[]{-1, 0, 1, 0};
    public int []dy=new int[]{0, 1, 0, -1};
    
    public int bfs(int startX, int startY, int endX, int endY) { //출발점, 도착지 받아 bfs 시작
        int[][]visited=new int[row][col];
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(startX, startY));
        visited[startX][startY]=1;
        
        while(!q.isEmpty()) {
            Pair p=q.poll();
            for(int d=0; d<4; d++) {
                int px=p.x+dx[d];
                int py=p.y+dy[d];
                
                if(px<0 || px>=row || py<0 || py>=col) continue;
                if(arr[px][py]=='X') continue;
                if(visited[px][py]>0) continue;
                
                visited[px][py]=visited[p.x][p.y]+1;
                if(px==endX && py==endY) return visited[px][py];
                q.add(new Pair(px, py));
            }
        }
        
        return -1;
    }
    
    public int solution(String[] maps) {
        int answer = 0;
        row=maps.length;
        col = maps[0].length();
        arr=new char[row][col];
        ans=Integer.MAX_VALUE;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                char[] chars=maps[i].toCharArray();
                char c=chars[j];
                arr[i][j]=c;
                if(c=='S') {
                    start=new Pair(i, j);
                }
                else if(c=='E') {
                    exit=new Pair(i, j);
                }
                else if(c=='L') {
                    lever=new Pair(i, j);
                }
            }
        }
        
        int toLever = bfs(start.x, start.y, lever.x, lever.y);
        if(toLever == -1) return -1;
        System.out.println(toLever);
        int toEnd=bfs(lever.x, lever.y, exit.x, exit.y);
        if(toEnd == -1) return -1;
        answer=toLever+toEnd-2;
        return answer;
    }
}
