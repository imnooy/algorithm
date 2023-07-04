import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n;
    static int[][]arr; //판
    static int t, x, y;
    static int score;
    static List<Integer> removeCols;
    static List<Integer> removeRows;

    static void place(int t, int xx, int yy) { //블록 이동 후 배치
        if(t==1) { //정사각형 하나
            arr[xx][yy]=1;
        }
        else if(t==2) { //가로로 긴 거
            arr[xx][yy]=1;
            arr[xx][yy+1]=1;
        }
        else {
            arr[xx][yy]=1;
            arr[xx+1][yy]=1;
        }
    }

    static int moveDown(int xx, int yy) { //출발점 받아 밑으로 이동시켜서 경계 x값 리턴
        int res=xx;
        for(int i=xx+1; i<=9; i++) {
            if(arr[i][yy]==1) break;
            res=i;
        }
        return res;
    }

    static int moveRight(int xx, int yy) { //출발점 받아 오른쪽으로 이동시켜서 경계 y값 리턴
        int res=yy;
        for(int j=yy+1; j<=9; j++) {
            if(arr[xx][j]==1) break;
            res=j;
        }
        return res;
    }

    //2. 놓은 블록이 경계 끝이나 다른 블록 만날 때까지 이동
    static void move(int t, int xx, int yy) {
        //2-1. 밑으로 먼저 이동 시키자
        int nx=moveDown(xx, yy);
        if(t==2) {
            nx=Math.min(nx, moveDown(xx, yy+1));
        }
        if(t==3) place(t, nx-1, yy); //밑으로 이동 시킨 블록 놓기
        else place(t, nx, yy);

        //2-2. 오른쪽으로 이동시키자
        int ny=moveRight(xx, yy);
        if(t==3) {
            ny=Math.min(ny, moveRight(xx+1, yy));
        }
        if(t==2) place(t, xx, ny-1); //오른쪽으로 이동 시킨 블록 놓기
        else place(t, xx, ny);
    }

    static void removeTite() { //한 줄에 다 있으면 없애고 점수 획득
        //파란색 열 없애기
        removeCols=new ArrayList<>();
        for(int j=4; j<=9; j++) {
            boolean isFull=true;
            for(int i=0; i<=3; i++) {
                if(arr[i][j]==0) {
                    isFull=false;
                    break;
                }
            }
            if(isFull) removeCols.add(j);
        }

        for(int j : removeCols) {
            for(int i=0; i<=3; i++) {
                arr[i][j]=0; //사라짐
            }
            score++; //사라지면 1점 획득
        }

        //초록색 행 없애기
        removeRows=new ArrayList<>();
        for(int i=4; i<=9; i++) {
            boolean isFull=true;
            for(int j=0; j<=3; j++) {
                if(arr[i][j]==0) {
                    isFull=false;
                    break;
                }
            }
            if(isFull) removeRows.add(i);
        }

        for(int i:removeRows) {
            for(int j=0; j<=3; j++) {
                arr[i][j]=0; //사라지기
            }
            score++; //1점 획득
        }
    }
    static void afterRemove() { //타일 사라진 후 - 여기 봐야 함
        Queue<Integer> toCol=new ArrayDeque<>();
        for(int j=9; j>=4; j--) {
            boolean isEmpty=true;
            for(int i=0; i<=3; i++) {
                if(arr[i][j]==1) {
                    isEmpty=false;
                    break;
                }
            }
            if(!isEmpty) {
                if(toCol.isEmpty()) continue;
                int to=toCol.poll();
                for(int i=0; i<=3; i++) {
                    if(arr[i][j]==1) {
                        arr[i][to]=1;
                        arr[i][j]=0;
                    }
                }
                toCol.add(j);
            }
            //죄다 비어있는 열에만 옮길 수 있듬
            else toCol.add(j);
        }

        /////
        Queue<Integer> toRow=new ArrayDeque<>();
        for(int i=9; i>=4; i--) {
            boolean isEmpty=true;
            for(int j=0; j<=3; j++) {
                if(arr[i][j]==1) {
                    isEmpty=false;
                    break;
                }
            }
            if(!isEmpty) {
                if(toRow.isEmpty()) continue;
                int to=toRow.poll();
                for(int j=0; j<=3; j++) {
                    if(arr[i][j]==1) {
                        arr[to][j]=1;
                        arr[i][j]=0;
                    }
                }
                toRow.add(i);
            }
            //죄다 비어있는 열에만 옮길 수 있듬
            else toRow.add(i);
        }
    }

    //연한 칸에 블록 있으면 그만큼 양 끝 블록들 없애기
    static void specialRemove() {
        boolean one=false;
        boolean two=false;

        //연한 파란 열들 먼저 보자
        for(int i=0; i<=3; i++) {
            if(arr[i][4]==1) one=true;
            if(arr[i][5]==1) two=true;
        }

        if(one) {
            for(int i=0; i<=3; i++) {
                arr[i][8]=0;
            }
        }
        if(two)  {
            for(int i=0; i<=3; i++) {
                arr[i][9]=0;
            }
        }

        one=false;
        two=false;

        //그 다음 초록 행들 보기
        for(int j=0; j<=3; j++) {
            if(arr[4][j]==1) one=true;
            if(arr[5][j]==1) two=true;
        }

        if(one) {
            for(int j=0; j<=3; j++) {
                arr[8][j]=0;
            }
        }
        if(two)  {
            for(int j=0; j<=3; j++) {
                arr[9][j]=0;
            }
        }
    }

    static int end() {
        int cnt=0;
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                if(i<=3 && j>=4 && arr[i][j]==1) cnt++;
                if(i>=4 && j<=3 && arr[i][j]==1) cnt++;
            }
        }

        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());

        arr=new int[10][10];
        score=0;

        for(int N=1; N<=n; N++) {
            StringTokenizer st=new StringTokenizer(br.readLine());
            t=Integer.parseInt(st.nextToken());
            x=Integer.parseInt(st.nextToken());
            y=Integer.parseInt(st.nextToken());

            //1. 블록 놓고 이동시키자
            move(t, x, y);

            //3. 모든 칸이 타일로 찬 행이나 열이 있으면 없애고 점수 추가
            removeTite();

            //4. 옮기기
            afterRemove();

            //5. 연한 타일 칸 보기
            specialRemove();

            //6. 만약 연한 칸 때문에 지워졌으면 다시 옮기기
            afterRemove();
        }

        StringBuilder sb=new StringBuilder();
        sb.append(score).append("\n");
        sb.append(end()).append("\n");

        System.out.println(sb.toString());

    }
}
