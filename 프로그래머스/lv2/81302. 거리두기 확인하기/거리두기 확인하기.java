import java.util.*;

public class Pair {
    int x;
    int y;
    int cnt;
    
    Pair(int x, int y, int cnt) {
        this.x=x;
        this.y=y;
        this.cnt=cnt;
    }
}

class Solution {
    public int[]dx=new int[]{-1, 0, 1, 0};
    public int[]dy=new int[]{0, 1, 0, -1};
    public char[][] arr;
    public List<Pair> people; //참가자 좌표 리스트
    
    public boolean isPossible(int x1, int y1, int x2, int y2) {
        if(Math.abs(x1-x2)+Math.abs(y1-y2)>2) return true;
        return false;
    }
    
    public boolean bfs(int x1, int y1, int x2, int y2) {
        Queue<Pair> q = new ArrayDeque<>();
        boolean[][] visited=new boolean[5][5];
        
        q.add(new Pair(x1, y1, 0));
        visited[x1][y1]=true;
        
        while(!q.isEmpty()) {
            Pair p = q.poll();
            for(int d=0; d<4; d++) {
                int nx=p.x+dx[d];
                int ny=p.y+dy[d];
                
                if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
                if(visited[nx][ny]) continue;
                if(arr[nx][ny]=='X') continue; //막혀있다
                if(p.cnt+1>2) continue;
                if(nx==x2 && ny==y2) return false; //만났다..
                
                visited[nx][ny]=true;
                q.add(new Pair(nx, ny, p.cnt+1));
            }
        }
        
        return true;
    }
    
    public boolean func() {
        for(int i=0; i<people.size(); i++) {
            Pair p1 = people.get(i);
            for(int j=i+1; j<people.size(); j++) {
                Pair p2 = people.get(j);
                if(!isPossible(p1.x, p1.y, p2.x, p2.y)) {
                    // System.out.println(p1.x+" "+p1.y+" 여기랑 "+p2.x+" "+p2.y);
                    // System.out.println("맨해튼거리 안댐");
                    if(!bfs(p1.x, p1.y, p2.x, p2.y)) {
                        // System.out.println("bfs안댐");
                        return false;
                    }
                }
            }  
        }
        System.out.println("끝!!");
        return true;
    }
    
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        for(int i=0; i<places.length; i++) {
            people = new ArrayList<>();
            arr=new char[5][5];
            String[] strs = places[i];
            System.out.println(i+"번째");
            for(int j=0; j<5; j++) {
                String str=strs[j];
                arr[j]=str.toCharArray();
                for(int k=0; k<5; k++) {
                    if(arr[j][k]=='P') people.add(new Pair(j, k, 0));
                }
            }
            
            if(!func()) {
                answer[i]=0;
            }
            else answer[i]=1;
        }
        
        return answer;
    }
}