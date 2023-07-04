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

        public void print() {
            System.out.println(x+" "+y);
        }
    }

    static int r, c, k, w, x, y, t;
    static int[][]arr;
    static List<Pair> warms; //온풍기 리스트
    static int[]dx=new int[]{0, 0, 0, -1, 1}; //오 왼 위 아래
    static int[]dy=new int[]{0, 1, -1, 0, 0};
    static int[][]input;

    static Map<String, Integer> map;

    static int findLeftD(int d) {
        if(d==1) return 3;
        else if(d==2) return 4;
        else if(d==3) return 2;
        else return 1;
    }

    static int findRightD(int d) {
        if(d==1) return 4;
        else if(d==2) return 3;
        else if(d==3) return 1;
        else return 2;
    }

    static boolean isRange(Pair p) {
        if(p.x<0 || p.x>=r || p.y<0 || p.y>=c) return false;
        return true;
    }

    static boolean isRange(int x, int y) {
        if(x<0 || x>=r || y<0 || y>=c) return false;
        return true;
    }

    static Pair findLeft(int wx, int wy, int d) {
        int dir=findLeftD(d);
        Pair left=new Pair(wx+dx[d]+dx[dir], wy+dy[d]+dy[dir]);
        if(isWall(wx, wy, wx+dx[dir], wy+dy[dir]) || isWall(wx+dx[dir], wy+dy[dir], left.x, left.y)) {
            return null;
        }
        return left;
    }

    static Pair findRight(int wx, int wy, int d) {
        int dir=findRightD(d);
        Pair right = new Pair(wx+dx[d]+dx[dir], wy+dy[d]+dy[dir]);
        if(isWall(wx, wy, wx+dx[dir], wy+dy[dir]) || isWall(wx+dx[dir], wy+dy[dir], right.x, right.y)) {
            return null;
        }
        return right;
    }

    static Pair findForward(int wx, int wy, int d) {
        if(isWall(wx, wy, wx+dx[d], wy+dy[d])) {
            return null;
        } 
        return new Pair(wx+dx[d], wy+dy[d]);
    }

    static boolean isWall(int x1, int y1, int x2, int y2) {
        String key = "";
        if(x1<x2) key+=(x1+" "+x2+" ");
        else key+=(x2+" "+x1+" ");

        if(y1<y2) key+=(y1+" "+y2);
        else key+=(y2+" "+y1);
        return map.containsKey(key);
    }

    static void wind(int index) { //1번 각 온풍기 바람 불어용
        int[][]visited=new int[r][c];
        int hx=warms.get(index).x;
        int hy=warms.get(index).y;
        int d=input[hx][hy];
        int nx=hx+dx[d];
        int ny=hy+dy[d];
        if(nx<0 || nx>=r || ny<0 || ny>=c) return;
        if(isWall(hx, hy, nx, ny)) return;
        visited[nx][ny]=5;
        arr[nx][ny]+=5;
        Queue<Pair> q=new ArrayDeque<>();
        q.add(new Pair(nx, ny));
        while(!q.isEmpty()) {
            Pair p = q.poll();

            Pair left=findLeft(p.x, p.y, d);
            if(left!=null && isRange(left) && visited[left.x][left.y]==0) {
                visited[left.x][left.y]=visited[p.x][p.y]-1;
                arr[left.x][left.y]+=visited[left.x][left.y];
                if(visited[left.x][left.y]>1) {
                    q.add(left);
                }
            } 

            Pair forward=findForward(p.x, p.y, d);
            if(forward!=null && isRange(forward) && visited[forward.x][forward.y]==0) {
                visited[forward.x][forward.y]=visited[p.x][p.y]-1;
                arr[forward.x][forward.y]+=visited[forward.x][forward.y];
                if(visited[forward.x][forward.y]>1) {
                    q.add(forward);
                }
            }

            Pair right=findRight(p.x, p.y, d);
            if(right!=null && isRange(right) && visited[right.x][right.y]==0) {
                visited[right.x][right.y]=visited[p.x][p.y]-1;
                arr[right.x][right.y]+=visited[right.x][right.y];
                if(visited[right.x][right.y]>1) {
                    q.add(right);
                }
            }
        }
    }

    static void adjust() { //2번 온도 조절
        int[][]tmp=new int[r][c];
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                for(int d=1; d<=4; d++) {
                    int nx=i+dx[d];
                    int ny=j+dy[d];

                    if(!isRange(nx, ny)) continue;
                    if(isWall(i, j, nx, ny)) continue;
                    if(arr[i][j]==0 && arr[nx][ny]==0) continue;

                    int diff=((Math.abs(arr[i][j]-arr[nx][ny]))/4);
                    if(arr[i][j]>arr[nx][ny]) {
                        tmp[i][j]-=diff;
                        tmp[nx][ny]+=diff;
                    }
                }
            }
        }

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                arr[i][j]+=tmp[i][j];
            }
        }
    }

    static void decrease() { //3번
        for(int i=1; i<r-1; i++) {
            arr[i][0]=arr[i][0]==0 ? arr[i][0] : arr[i][0]-1;
            arr[i][c-1]=arr[i][c-1]==0 ? arr[i][c-1] : arr[i][c-1]-1;
        }

        for(int j=1; j<c-1; j++) {
            arr[0][j]=arr[0][j]==0 ? arr[0][j] : arr[0][j]-1;
            arr[r-1][j]=arr[r-1][j]==0 ? arr[r-1][j] : arr[r-1][j]-1;
        }

        arr[0][0]=arr[0][0]==0?0:arr[0][0]-1;
        arr[0][c-1]=arr[0][c-1]==0?0:arr[0][c-1]-1;
        arr[r-1][0]=arr[r-1][0]==0?0:arr[r-1][0]-1;
        arr[r-1][c-1]=arr[r-1][c-1]==0?0:arr[r-1][c-1]-1;
    }

    static boolean check() { //검사
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(input[i][j]!=5) continue;

                if(arr[i][j]<k) return false;
            }
        }
        return true;
    }

    static void debug() {
        System.out.println("===DEBUG===");
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("========");
    }

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r=Integer.parseInt(st.nextToken());
        c=Integer.parseInt(st.nextToken());
        k=Integer.parseInt(st.nextToken());
        warms = new ArrayList<>();
        arr=new int[r][c];
        input=new int[r][c];
        map=new HashMap<>();
        for(int i=0; i<r; i++) {
            st=new StringTokenizer(br.readLine());
            for(int j=0; j<c; j++) {
                input[i][j]=Integer.parseInt(st.nextToken());
                if(input[i][j]>=1 && input[i][j]<=4) {
                    warms.add(new Pair(i, j));
                }
            }
        }
        w=Integer.parseInt(br.readLine());
        for(int i=0; i<w; i++) {
            //벽의 정보들
            st=new StringTokenizer(br.readLine());
            x=Integer.parseInt(st.nextToken())-1;
            y=Integer.parseInt(st.nextToken())-1;
            t=Integer.parseInt(st.nextToken());

            String key="";
            if(t==0) {
                key+=((x-1)+" "+x+" "+y+" "+y);
            }
            else {
                key+=(x+" "+x+" "+y+" "+(y+1));
            }
            map.put(key, 1);
        }

        int choco=0;

        while(true) {
            for(int i=0; i<warms.size(); i++) {
                wind(i);
            }

            adjust();
            decrease();
            choco++;
            if(choco>100) {
                choco=101;
                break;
            }

            if(check()) {
                break;
            }
        }

        System.out.println(choco);
    }
}