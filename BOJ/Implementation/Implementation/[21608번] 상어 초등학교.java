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

    static int[]dx=new int[]{-1, 0, 1, 0};
    static int[]dy=new int[]{0, 1, 0, -1};

    static boolean isRange(int x, int y) {
        if(x<=0 || x>n || y<=0 || y>n) return false;
        return true;
    }

    static boolean isAdj(int index, int x, int y) {
        for(int i=0; i<4; i++) {
            if(like[index][i]==arr[x][y]) return true;
        }
        return false;
    }

    static int two(Pair p) {
        int cnt=0;
        for(int d=0; d<4; d++) {
            int nx=p.x+dx[d];
            int ny=p.y+dy[d];

            if(!isRange(nx, ny)) continue;
            if(arr[nx][ny]==0) cnt++;
        }

        return cnt;
    }

    static int one(Pair p, int num) { //num: 학생 번호
        //비어있는 값만 본다
        int cnt =0; //좋아하는 학생 가까이 있는지 봄
        for(int d=0; d<4; d++) {
            int nx=p.x+dx[d];
            int ny=p.y+dy[d];
            if(!isRange(nx, ny)) continue;
            if(arr[nx][ny]==0) continue;
            
            if(isAdj(num, nx, ny)) cnt++;
        }

        return cnt;
    }

    static Pair func(int num) {
        PriorityQueue<Pair> pq=new PriorityQueue<>(new Comparator<Pair>() { //java 8에서 타입 
            @Override
            public int compare(Pair p1, Pair p2) {
                int ans=one(p2, num)-one(p1, num);
                if(ans==0) {
                    ans=two(p2)-two(p1);
                    if(ans==0) {
                        ans=p1.x-p2.x;
                        if(ans==0) {
                            ans=p1.y-p2.y;
                        }
                    }
                }
                return ans;
            }
        });

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(arr[i][j]!=0) continue;
                pq.add(new Pair(i, j));
            }
        }
        // System.out.println("학생번호: "+num+" 자리는? x: "+pq.peek().x+" y: "+pq.peek().y);
        return pq.poll();
    }

    static int satisfied(int cnt) {
        if(cnt==0) return 0;
        else return (int)Math.pow(10, cnt-1);
    }

    static int[][]like;
    static int n;
    static int[][]arr;

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
        int N=n*n;
        like=new int[N+1][4];
        arr=new int[n+1][n+1];

        for(int i=0; i<N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken());
            for(int j=0; j<4; j++) {
                like[index][j]=Integer.parseInt(st.nextToken());
            }
            Pair seat = func(index); //자리 정함
            arr[seat.x][seat.y]=index;
        }
        
        int sum=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int cnt=one(new Pair(i, j), arr[i][j]);
                sum+=satisfied(cnt);
            }
        }
        System.out.println(sum);
    }
}
