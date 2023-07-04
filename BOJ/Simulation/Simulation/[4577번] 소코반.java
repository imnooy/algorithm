import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Pair{
        char before;
        char after;

        Pair(char before, char after) {
            this.before=before;
            this.after=after;
        }
    }
    static int r, c;
    static Pair arr[][];
    static int userX;
    static int userY;
    static int[]dx=new int[]{-1, 1, 0, 0};
    static int[]dy=new int[]{0, 0, -1, 1};
    static Queue<Character> command;
    static int remainBox;

    static void move(int d) {
        int nx=userX+dx[d];
        int ny=userY+dy[d];

        //1. 캐릭터에게 지시한 방향이 빈칸(박스나 벽이 아님)인 경우에는 그 칸으로 이동
        //먼저 캐릭터가 있는 공간 비워주기
        if(arr[nx][ny].after=='.' || arr[nx][ny].after=='+') {
            arr[userX][userY].after=arr[userX][userY].before;

            //캐릭터 위치시키기
            if(arr[nx][ny].after=='.') { //빈 공간
                arr[nx][ny].after='w';
            }
            else if(arr[nx][ny].after=='+') { //비어 있는 목표점
                arr[nx][ny].after='W';
            }
            userX=nx;
            userY=ny; //캐릭터 이동
        }

        //2. 지시한 방향에 박스가 있는 경우, 박스를 민다.
        //이 경우에는 박스가 이동할 칸도 비어있어야 한다.
        int fx=nx+dx[d];
        int fy=ny+dy[d];
        if(arr[nx][ny].after=='b' || arr[nx][ny].after=='B') {
            if (arr[fx][fy].after == '.' || arr[fx][fy].after == '+') {
                arr[userX][userY].after = arr[userX][userY].before;
                userX = nx;
                userY = ny;
                //박스 밀 수 있으면 치우고 사용자가 들어감
                if (arr[nx][ny].before == '+') {
                    remainBox++; //원래 박스 있던 곳이 목표점인데 치우는 거면 옮겨야 하는 박스 수 증가
                    arr[nx][ny].after = 'W';
                } else if (arr[nx][ny].before == '.') {
                    arr[nx][ny].after = 'w';
                }

                if (arr[fx][fy].after == '.') { //빈 공간
                    //박스 민다.
                    arr[fx][fy].after = 'b';
                } else if (arr[fx][fy].after == '+') { //비어 있는 목표점
                    //박스 민다.
                    arr[fx][fy].after = 'B';
                    remainBox--;
                }
            }
        }
    }

    static int getDir(char c) {
        if(c=='U') return 0;
        else if(c=='D') return 1;
        else if(c=='L') return 2;
        else return 3;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        int tc=1;
        while(true) {
            StringTokenizer st=new StringTokenizer(br.readLine()
            );
            r= Integer.parseInt(st.nextToken());
            c= Integer.parseInt(st.nextToken());
            if(r==0 && c==0) {
                break;
            }

            arr=new Pair[r][c];
            command=new ArrayDeque<>();
            remainBox=0; //옮겨야 할 남은 박스

            for(int i=0; i<r; i++) {
                char []input=br.readLine().toCharArray();
                for(int j=0; j<c; j++) {
                    char c=input[j];
                    char before='.';
                    if(c=='w' || c=='W') {
                        userX=i;
                        userY=j;
                    }
                    else if(c=='b') {
                        remainBox++; //밀어야 할 박스 개수 증가
                    }

                    if(c=='B' || c=='W' || c=='+') {
                        before='+';
                    }
                    arr[i][j]=new Pair(before, c);
                }
            }

            char []input=br.readLine().toCharArray();
            for(int i=0; i<input.length; i++) {
                command.add(input[i]);
            }

            while(!command.isEmpty()) {
                char d=command.poll();
                move(getDir(d));
                if(remainBox==0) break;
            }

            sb.append("Game "+tc++ +": ");
            if(remainBox==0) sb.append("complete").append("\n");
            else sb.append("incomplete").append("\n");

            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    sb.append(arr[i][j].after);
                }
                sb.append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}
