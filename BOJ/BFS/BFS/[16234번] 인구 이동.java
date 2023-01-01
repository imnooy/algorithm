import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }
    }

    static class Unite { //연합
        List<Pair> country;
        int sum;

        Unite() {
            this.country=new ArrayList<>();
            this.sum=0;
        }
    }

    static int []dx=new int[]{-1, 0, 1, 0};
    static int []dy=new int[]{0, 1, 0, -1};

    static int n, l, r;
    static int arr[][];
    static boolean visited[][];

    static boolean isOpen(int x1, int y1, int x2, int y2) { //국경선 열 수 있는가
        int diff=Math.abs(arr[x1][y1]-arr[x2][y2]);
        if(diff>=l && diff<=r) return true;
        return false;
    }

    static boolean open() { //bfs - 국경선 열기(연합 만들기)
        Queue<Pair> q=new ArrayDeque<>();
        visited=new boolean[n+1][n+1];
        boolean val=false;
        List<Unite> unites=new ArrayList<>();

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(visited[i][j]) continue;

                q.add(new Pair(i, j)); //연합 만들기 시작
                visited[i][j]=true;
                Unite u=new Unite();
                u.country.add(new Pair(i, j));
                u.sum+=arr[i][j];

                boolean makeUnite=false;
                while(!q.isEmpty()) {
                    Pair p=q.poll();

                    for(int d=0; d<4; d++) {
                        int nx=p.x+dx[d];
                        int ny=p.y+dy[d];

                        if(nx<1 || nx>n || ny<1 || ny>n) continue;
                        if(visited[nx][ny]) continue;
                        if(!isOpen(p.x, p.y, nx, ny)) continue;
                        makeUnite=true;
                        u.country.add(new Pair(nx, ny));
                        u.sum+=arr[nx][ny];
                        visited[nx][ny]=true;
                        q.add(new Pair(nx, ny));
                    }
                }

                if(!makeUnite) continue;
                val=true; //한번이라도 연합 만들어짐
                unites.add(u);
            }
        }

        for(Unite u:unites) {
            List<Pair> list=u.country;
            int people=u.sum/list.size();

            for(Pair p:list) {
                arr[p.x][p.y]=people;
            }
        }

        return val;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());

        n= Integer.parseInt(st.nextToken());
        l= Integer.parseInt(st.nextToken());
        r= Integer.parseInt(st.nextToken());

        arr=new int[n+1][n+1];

        for(int i=1; i<=n; i++) {
            st=new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++) {
                arr[i][j]= Integer.parseInt(st.nextToken());
            }
        }

        int ans=0;

        while(true) {
            if(open()) ans++;
            else break;
        }
        System.out.println(ans);
    }
}
