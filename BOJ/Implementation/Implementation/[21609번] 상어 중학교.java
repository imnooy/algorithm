import java.util.*;
import java.io.*;


public class Main
{
    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }
    }

    static class Group implements Comparable<Group> {
        List<Pair> list;
        int rainbow;
        int row;
        int col;

        Group(List<Pair> list, int rainbow, int row, int col) {
            this.list=list;
            this.rainbow=rainbow;
            this.row=row;
            this.col=col;
        }

        @Override
        public int compareTo(Group g) {
            int ans=g.list.size()-this.list.size();
            if(ans==0) {
                ans=g.rainbow-this.rainbow;
                if(ans==0) {
                    ans=g.row-this.row;
                    if(ans==0) {
                        ans=g.col-this.col;
                    }
                }
            }
            return ans;
        }
    }

    static int n, m;
    static int[][]arr;
    static int[]dx=new int[]{-1, 0, 1, 0};
    static int[]dy=new int[]{0, 1, 0, -1};
    static boolean[][]visited;
    static PriorityQueue<Group> pq;
    static List<Pair> rainbows;
    static int score;

    static boolean isRange(int x, int y) {
        if(x<0 || x>=n || y<0 || y>=n) return false;
        return true;
    }

    static void bfs(int x, int y) {
        Queue<Pair> q = new ArrayDeque<>();
        visited[x][y]=true;
        q.add(new Pair(x, y));
        int num=arr[x][y];
        int rainbow=0;
        int row=x;
        int col=y;
        List<Pair> list=new ArrayList<>();
        list.add(new Pair(x, y));

        for(Pair p : rainbows) {
            visited[p.x][p.y]=false;
        }

        while(!q.isEmpty()) {
            Pair p=q.poll();

            for(int d=0; d<4; d++) {
                int nx=p.x+dx[d];
                int ny=p.y+dy[d];

                if(!isRange(nx, ny)) continue;
                if(arr[nx][ny] < 0) continue;
                if(visited[nx][ny]) continue;
                if(arr[nx][ny]==0 || arr[nx][ny]==num) {
                    visited[nx][ny]=true;
                    Pair block=new Pair(nx, ny);
                    q.add(block);
                    list.add(block);
                    if(arr[nx][ny]==0) rainbow++;
                    else {
                        row=Math.min(row, nx);
                        col=Math.min(col, ny);
                    }
                }
            }
        }
        if(list.size()>=2) {
            pq.add(new Group(list, rainbow, row, col));
        }
    }

    static boolean one() {
        pq=new PriorityQueue<>();
        visited=new boolean[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]<=0) continue;
                if(visited[i][j]) continue;
                bfs(i, j);
            }
        }

        if(pq.isEmpty()) return false;
        else return true; //계속 하삼
    }

    static void two() {
        Group g=pq.poll();
        List<Pair> list=g.list;
        for(Pair p : list) {
            arr[p.x][p.y]=-2;
        }
        int b=list.size();
        score+=(b*b);
    }

    static void gravity(int x, int y) {
        int nx=x;

        while((nx+1)<n && arr[nx+1][y]==-2) {
            nx++;
        }
        if(nx==x) return;
        arr[nx][y]=arr[x][y];
        arr[x][y]=-2;
    }

    static void three() {
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]<0) continue;
                gravity(i, j);
            }
        }
    }

    static void four() {
        int [][] tmp=new int[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                tmp[n-j-1][i]=arr[i][j];
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                arr[i][j]=tmp[i][j];
            }
        }
    }

    static void five() { //무지개 블록들 다시 설정
        rainbows=new ArrayList<>();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]==0) rainbows.add(new Pair(i, j));
            }
        }
    }

    static void debug() {
        System.out.println("=Debug");
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(arr[i][j]+"   ");
            }
            System.out.println();
        }
        System.out.println("=");
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        arr=new int[n][n];
        rainbows=new ArrayList<>();
        for(int i=0; i<n; i++) {
            st=new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                arr[i][j]=Integer.parseInt(st.nextToken());
                if(arr[i][j]==0) rainbows.add(new Pair(i, j));
            }
        }
        score=0;

        while(true) {
            if(!one()) break;
            two();
            three();
            four();
            three();
            five();
        }

        System.out.println(score);

    }
}
