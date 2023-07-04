import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ_3678_카탄의개척자_김윤미 {
    static class Tile{
        int num;
        boolean[] adj;
        Tile() {
            this.adj=new boolean[6];
        }
    }

    static int dx[]=new int[]{-2, 2, -1, 1, 1, -1};
    static int dy[]=new int[]{-0, 0, -1, -1, 1, 1};

    static Tile arr[][];
    static int cnt[];
    static int ans[];

    static int n;

    static int nextDir(int i, int j, int d) { //현재 좌표, 전에 온 방향 받아서 다음 방향 좌표 리턴
        if(d==0) { //밑에서 위로 왔으면
            if(arr[i+dx[2]][j+dy[2]].num==0) {
                return 2; //왼쪽 대각선으로 갈 수 있으면 가라
            }
        }
        else if(d==1) { //위에서 밑으로 왔으면
            if(arr[i+dx[4]][j+dy[4]].num==0) {
                return 4;
            }
        }
        else if(d==2) { //오른쪽 대각선 밑에서 왔으면 (↖)
            if(arr[i+dx[3]][j+dy[3]].num==0) {
                return 3;
            }
        }
        else if(d==3) { //오른쪽 대각선 위에서 왔으면(↙)
            if(arr[i+dx[1]][j+dy[1]].num==0) {
                return 1;
            }
        }
        else if(d==4) { //왼쪽 대각선 위에서 왔으면(↘)
            if(arr[i+dx[5]][j+dy[5]].num==0) {
                return 5;
            }
        }
        else { //왼쪽 대각선 밑에서 왔으면(↗)
            if(arr[i+dx[2]][j+dy[2]].num==0) {
                return 2;
            }
            else if(arr[i+dx[0]][j+dy[0]].num==0) {
                return 0;
            }
        }
        return d;
    }

    static void mark(int i, int j, int num) { //현재 좌표 받아서 인접 타일들에 인접 여부 기록
        for(int d=0; d<=5; d++) {
            int nx=i+dx[d];
            int ny=j+dy[d];

            if(arr[nx][ny]==null) {
                arr[nx][ny]=new Tile();
            }

            arr[nx][ny].adj[num]=true;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int C=Integer.parseInt(br.readLine());

        arr=new Tile[1001][1001];
        cnt=new int[6];
        ans=new int[10001];

        int curDir=4;
        int i=500;
        int j=500;

        for(int n=1; n<=10000; n++) { //전처리
            //1. 표시 숫자 정하기
            int num=-1;
            if(arr[i][j]==null) { //첫번째 타일임
                arr[i][j]=new Tile();
                num=1;
                arr[i][j].num=1;
            }
            else {
                for(int in=1; in<=5; in++) {
                    if(arr[i][j].adj[in]) continue;
                    else {
                        if(num==-1) { //아직 안 정해진 상태
                            num=in;
                        }
                        else { //가능한 자원이 여러 가지
                            if(cnt[num]<cnt[in]) continue;
                            else if(cnt[num]>cnt[in]) { //적게 나타난 자원 선택
                                num=in;
                            }
                            else if(cnt[num]==cnt[in]) {
                                //그러한 경우도 여러 가지
                                if(num>in) {
                                    num=in; //번호가 작은 것 선택
                                }
                            }
                        }
                    }
                }
            }
            //2. 개수 증가
            arr[i][j].num=num;
            cnt[num]+=1;
            ans[n]=num;

            //3. 인접 타일에 마크하기
            mark(i, j, num);

            //4. 다음 방향 찾기
            curDir=nextDir(i, j, curDir);
            i+=dx[curDir];
            j+=dy[curDir];
        }
        StringBuffer sb=new StringBuffer();
        for(int c=1; c<=C; c++) {
            n=Integer.parseInt(br.readLine());
            sb.append(ans[n]).append("\n");
        }

        System.out.println(sb.toString());
    }
}
