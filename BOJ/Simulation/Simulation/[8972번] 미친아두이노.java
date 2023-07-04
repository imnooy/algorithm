import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BJ_8972_미친아두이노_김윤미 {
    static class Pair{
        int x;
        int y;

        Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }
    }
    static int dx[]=new int[]{0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
    static int dy[]=new int[]{0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
    static int r, c;
    static char[][]arr;
    static Pair jongsu;
    static Queue<Pair> mad;
    static int X;
    static Queue<Integer> command;

    static int getDis(int r1, int s1, int r2, int s2) {
        return Math.abs(r1-r2)+Math.abs(s1-s2);
    }

    //1. 종수 이동
    static boolean jongsuMove(int dir) {
        int nx=jongsu.x+dx[dir];
        int ny=jongsu.y+dy[dir]; //종수가 이동할 칸

        //2. 종수의 아두이노가 미친 아두이노가 있는 칸으로 이동할 경우에는 게임 끝, 게임 짐
        if(arr[nx][ny]=='R') {
            return false;
        }
        arr[jongsu.x][jongsu.y]='.';
        arr[nx][ny]='I';
        jongsu=new Pair(nx, ny); //그게 아니라면 이동시켜주기
        return true;
    }

    //3. 미친 아두이노 이동
    static boolean madMove() {
        int sz=mad.size();
        Queue<Pair> to=new ArrayDeque<>();

        //종수의 아두이노와 가장 가까워 지는 방향으로 가기
        for(int i=0; i<sz; i++) {
            int toDir=5; //가까워지는 방향 찾기
            int toDis=100000; //미친아두이노와 종수의 거리
            Pair pos=mad.poll();

            if(arr[pos.x][pos.y]=='X') { //이미 폭발한 아두이노..
                arr[pos.x][pos.y]='.';
                continue;
            }

            for(int d=1; d<=9; d++) {
                int nx=pos.x+dx[d];
                int ny=pos.y+dy[d];
                if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
                if(toDis>getDis(jongsu.x, jongsu.y, nx, ny)) {
                    toDir=d;
                    toDis=getDis(jongsu.x, jongsu.y, nx, ny);
                }
            }
            arr[pos.x][pos.y]='.'; //원래 미친 아두이노 이동함 - 비워주기
            int nx=pos.x+dx[toDir];
            int ny=pos.y+dy[toDir];
            if(arr[nx][ny]=='I') { //종수 만남 게임 끝
                return false;
            }
            to.add(new Pair(nx, ny));
        }

        while(!to.isEmpty()) {
            Pair t=to.poll();
            int nx=t.x;
            int ny=t.y;

            if(arr[nx][ny]=='R' || arr[nx][ny]=='X') { //이미 아두이노 있으면 폭발해야함
                arr[nx][ny]='X';
            }
            else {
                arr[nx][ny]='R';
                mad.add(new Pair(nx, ny));
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        r= Integer.parseInt(st.nextToken());
        c= Integer.parseInt(st.nextToken());

        arr=new char[r][c];
        mad=new ArrayDeque<>();
        command=new ArrayDeque<>();
        for(int i=0; i<r; i++) {
            char []input=br.readLine().toCharArray();
            for(int j=0; j<c; j++) {
                char c=input[j];
                if(c=='I') jongsu=new Pair(i, j);
                else if(c=='R') mad.add(new Pair(i, j));
                arr[i][j]=c;
            }
        }

        char []input=br.readLine().toCharArray();
        for(int i=0; i<input.length; i++) {
            command.add(input[i]-'0');
        }

        X=0;
        while(!command.isEmpty()) {
            int dir=command.peek();
            //1. 먼저, 종수가 아두이노를 이동시킴
            boolean jsMovable=jongsuMove(dir);
            X++;
            if(!jsMovable) break;

            boolean madMovable=madMove();
            if(!madMovable) break;

            command.poll();
        }

        if(!command.isEmpty()) {
            System.out.println("kraj "+X);
        }
        else {
            StringBuilder sb=new StringBuilder();
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    if(arr[i][j]=='X') arr[i][j]='.';
                    sb.append(arr[i][j]);
                }
                sb.append("\n");
            }
            System.out.println(sb.toString());
        }
    }
}
